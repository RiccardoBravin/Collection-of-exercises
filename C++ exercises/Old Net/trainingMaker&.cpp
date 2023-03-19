// Training randomico per NAND-O

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

bool AND(bool n1, bool n2)
{
    return (n1 && n2);
}

bool OR(bool n1, bool n2)
{
    return (n1 || n2);
}

bool N(bool n1)
{
    return (!n1);
}



int main()
{
    ofstream file;
	file.open("trainingData.txt");

    srand(time(0));
    int n1,n2,n3,t;
    file << "topology: 3 9 1" << endl;

    for(int i = 10000; i >= 0; i--){
        n1 = rand()%2;
        n2 = rand()%2;
        n3 = rand()%2;
        file << "in: " << n1 << ".0 " << n2 << ".0 " << n3 << ".0 " << endl;

        file << "out: " << OR(AND(n1,n2),n3) << ".0" << endl;

    }
}
