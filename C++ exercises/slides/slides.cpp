#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream> //ifstream in("input.txt);      ofstream out("output.txt);
#include <string>
#include <math.h>
#include <time.h>
#include <cstdio>


using namespace std;

float coll(unsigned int x, unsigned int m, unsigned int bmoc[][1])
{
    unsigned int r=0;
    for(int i=0;i<m;i++)
        if(bmoc[i][0] == x)
            r++;
    return 1/r;
}

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    unsigned int n,m,p,aux;

    cin >> n;
    cin >> m;
    cin >> p;

    unsigned int comb[m][1];
    unsigned int res[p];
    for(int i=0;i<m;i++)
        for(int j=0;j<2;j++)
        {
            cin >> aux;
            comb[i][j] = aux;
        }

    for(int i=0; i<n-p;i++)
    {

    }

}
