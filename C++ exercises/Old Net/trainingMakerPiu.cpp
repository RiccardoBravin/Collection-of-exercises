// Training randomico per NAND-O

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    ofstream file;
	file.open("trainingData.txt");

    srand(time(0));
    float n1,n2;
    file << "topology: 2 4 1" << endl;

    for(int i = 1000; i >= 0; i--){
        n1 = rand()%500+1;
        n2 = rand()%300+1;
        file << "in: " << n1/10000 << " " << n2/10000 << endl;

        file << "out: " << (n1+n2)/10000 << endl;

    }


}
