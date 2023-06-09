// neural-net-example.cpp

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

class Neuron;

typedef vector<Neuron> Layer;

struct Connection
{
    double weight;
    double deltaWeitght;
};

//********** Training class **********

class TrainingData
{
public:
    TrainingData(const string filename);
    bool isEof(void) {return m_trainingDataFile.eof();}
    void getTopology(vector<unsigned> &topology);

    unsigned getNextInputs(vector<double> &inputVals);
    unsigned getTargetOutputs(vector<double> &targetOutputVals);

private:
    ifstream m_trainingDataFile;

};

void TrainingData::getTopology(vector<unsigned> &topology)
{
    string line;
    string label;

    getline(m_trainingDataFile, line);
    stringstream ss(line);
    ss >> label;

    if(this->isEof() || label.compare("topology:") != 0){
        abort();
    }

    while(!ss.eof()){
        unsigned n;
        ss >> n;
        topology.push_back(n);
    }

    return;
}

TrainingData::TrainingData(const string filename)
{
    m_trainingDataFile.open(filename.c_str());
}

unsigned TrainingData::getNextInputs(vector<double> &inputVals)
{
    inputVals.clear();

    string line;
    getline(m_trainingDataFile, line);
    stringstream ss(line);

    string label;
    ss >> label;
    if(label.compare("in:") == 0){
        double oneValue;
        while(ss >> oneValue){
            inputVals.push_back(oneValue);
        }
    }

    return inputVals.size();
}

unsigned TrainingData::getTargetOutputs(vector<double> &targetOutputVals)
{
    targetOutputVals.clear();

    string line;
    getline(m_trainingDataFile, line);
    stringstream ss(line);

    string label;
    ss >> label;
    if(label.compare("out:") == 0){
        double oneValue;
        while(ss >> oneValue){
            targetOutputVals.push_back(oneValue);
        }
    }

    return targetOutputVals.size();
}


//********** class Neuron **********

class Neuron
{
public:
    Neuron(unsigned numOutputs, unsigned myIndex);
    void setOutputVal(double val) {m_outputVal = val;}
    double getOutputVal(void)const {return m_outputVal;}
    void feedForward(const Layer &prevLayer);
    void calcOutputGradients(double targetVal);
    void calcHiddenGradients(const Layer &nextLayer);
    void updateInputWeights(Layer &prevLayer);

private:
    static double eta;
    static double alpha;
    static double transferFunction(double x);
    static double transferFunctionDerivative(double x);
    static double randomWeight(void){return rand() / double(RAND_MAX);}
    double sumDOW(const Layer &nextLayer) const;
    double m_outputVal;
    vector<Connection> m_outputWeights;
    unsigned m_myIndex;
    double m_gradient;
};

double Neuron::eta = 0.2; // [0.0 to 1.0] overall net training rate
double Neuron::alpha = 0.2; // [0.0 to n] multiplier of last weight change (momentum)

void Neuron::updateInputWeights(Layer &prevLayer)
{
    // The weights to be updated are in the connection container in the neurons in the preceding layer

    for(unsigned n=0; n< prevLayer.size(); n++){
        Neuron &neuron = prevLayer[n];
        double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeitght;

        double newDeltaWeight =
                //Individual input, magnified my the gradient and train rate
                eta //Learning rate ( 0.0 slow, 0.2 medium , 1.0 reckless)
                * neuron.getOutputVal()
                * m_gradient
                //also add momentum = a fraction of the previous delta weight
                + alpha // Momentum (0.0 no momentum, 0.5 moderate momentum)
                * oldDeltaWeight;

        neuron.m_outputWeights[m_myIndex].deltaWeitght = newDeltaWeight;
        neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
    }
}

double Neuron::sumDOW(const Layer &nextLayer) const
{
    double sum = 0.0;

    // Sum our contributions of the errors at the nodes we feed

    for(unsigned n = 0; n < nextLayer.size() - 1; n++){
        sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
    }

    return sum;
}

void Neuron::calcHiddenGradients(const Layer &nextLayer)
{
    double dow = sumDOW(nextLayer);
    m_gradient = dow * Neuron::transferFunctionDerivative(m_outputVal);
}

void Neuron::calcOutputGradients(double targetVal)
{
    double delta = targetVal - m_outputVal;
    m_gradient = delta * Neuron::transferFunctionDerivative(m_outputVal);
}

double Neuron::transferFunction(double x)
{
    double zero = 0;
    // tanh - output range[-1,0...1,0]
    return tanh(x);
    //return max(zero,x);
}

double Neuron::transferFunctionDerivative(double x)
{
    //double zero = 0, uno = 1;
    // tanh derivative
    return 1.0 - x * x;
    /*if(x<=0)
        return zero;
    else
        return uno;*/
}

void Neuron::feedForward(const Layer &prevLayer)
{
    double sum = 0.0;

    //Sum the previous layer's outputs (which are our inputs)
    //Include the bias node from the previous layer

    for(unsigned n=0; n< prevLayer.size(); n++){
        sum += prevLayer[n].getOutputVal() *
                prevLayer[n].m_outputWeights[m_myIndex].weight;
    }

    m_outputVal = Neuron::transferFunction(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
    for(unsigned c=0; c< numOutputs; c++){
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = randomWeight();
    }

    m_myIndex = myIndex;
}

//********** class Net **********

class Net
{
public:
    Net(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals);
    void backProp(const vector<double> &targetVals);
    void getResults(vector<double> &resultVals) const;
    double getRecentAverageError(void) const {return m_recentAverageError;};

private:
    vector<Layer> m_layers; // m_layers(layerNum][neuronNum]
    double m_error;
    double m_recentAverageError;
    double m_recentAverageSmoothingFactor;
};

void Net::getResults(vector<double> &resultVals) const
{
    resultVals.clear();

    for(unsigned n=0; n < m_layers.back().size() - 1; n++){
        resultVals.push_back(m_layers.back()[n].getOutputVal());
    }
}

void Net::backProp(const vector<double> &targetVals)
{
    // calculate overall net error (RMS of output errors)

    Layer &outputLayer = m_layers.back();
    m_error = 0.0;

    for(unsigned n=0; n < outputLayer.size() -1; n++){
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta;
    }

    m_error /= outputLayer.size() - 1; // get average error squared
    m_error = sqrt(m_error);    // RMS

    //implement a recent average measurement(probably unnecessary)

    m_recentAverageError=
            (m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
            / (m_recentAverageSmoothingFactor + 1.0);

    //calculate output layer gradients

        for(unsigned n=0; n<outputLayer.size() -1; n++){
            outputLayer[n].calcOutputGradients(targetVals[n]);
        }

    // Calculate gradients on hidden layers

        for(unsigned layerNum = m_layers.size() - 2; layerNum > 0; layerNum--){
            Layer &hiddenLayer = m_layers[layerNum];
            Layer &nextLayer = m_layers[layerNum +1];

            for(unsigned n=0; n< hiddenLayer.size();n++){
                hiddenLayer[n].calcHiddenGradients(nextLayer);
            }
        }

    //Update connetion weights for all layers from output to first hidden layer

    for(unsigned layerNum = m_layers.size() - 1; layerNum > 0; layerNum--){
        Layer &layer = m_layers[layerNum];
        Layer &prevLayer = m_layers[layerNum - 1];

        for(unsigned n = 0; n < layer.size() -1; n++){
            layer[n].updateInputWeights(prevLayer);
        }
    }

}

void Net::feedForward(const vector<double> &inputVals)
{
    assert(inputVals.size() == m_layers[0].size() - 1);

    //Assign(latch) the input values into the input neurons

    for(unsigned i=0; i< inputVals.size(); i++){
        m_layers[0][i].setOutputVal(inputVals[i]);
    }

    //Forward propagate

    for(unsigned layerNum = 1; layerNum < m_layers.size(); layerNum++){
        Layer &prevLayer = m_layers[layerNum -1];
        for(unsigned n = 0; n < m_layers[layerNum].size() - 1; n++){
            m_layers[layerNum][n].feedForward(prevLayer);
        }
    }

}

Net::Net(const vector<unsigned> &topology)
{
    unsigned numLayers = topology.size();
    for(unsigned layerNum=0; layerNum < numLayers; layerNum++){
        m_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ?  0: topology[layerNum + 1];
        /*We have made a new Layer, now fill it whit neurons, and add a bias to the layer*/

        for(unsigned neuronNum=0; neuronNum <= topology[layerNum]; neuronNum++){
            m_layers.back().push_back(Neuron(numOutputs, neuronNum));
            cout << "Made a Neuron!" << endl;
        }

        //force bias neuron to output value 1.0
        m_layers.back().back().setOutputVal(1.0);
    }
}

void showVectorVals(string label, vector<double> &v)
{
    cout << label << " ";
    for(unsigned i=0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;
}

int main()
{
    TrainingData trainData("trainingData.txt");

    vector<unsigned> topology;
    trainData.getTopology(topology);

    Net myNet(topology);

    vector<double> inputVals, targetVals, resultVals;
    int trainingPass = 0;

    while(!trainData.isEof()){
        ++trainingPass;
        cout << endl << "Pass " << trainingPass;

        // Get new input data and feed it forward:
        if(trainData.getNextInputs(inputVals) != topology[0]){
            break;
        }
        showVectorVals(": Inputs:",inputVals);
        myNet.feedForward(inputVals);

        //collect net's actual results
        myNet.getResults(resultVals);
        showVectorVals("Outputs:", resultVals);

        trainData.getTargetOutputs(targetVals);
        showVectorVals("Targets:", targetVals);

        assert(targetVals.size() == topology.back());

        myNet.backProp(targetVals);

        cout << "Net recent average error: " << myNet.getRecentAverageError() << endl;
    }

    cout << endl << "DONE" << endl;
}
