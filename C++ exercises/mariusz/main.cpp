#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream> //ifstream in("input.txt");      ofstream out("output.txt");
#include <string>
#include <math.h>
#include <time.h>
#include <cstdio>   //freopen("input.txt","r",stdin);   freopen("output.txt","w",stdout);


using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    unsigned short aux1, aux2, aux3, x, n, e;

    cin >> n >> e;

    vector<unsigned int> u;
    vector<unsigned int> d;
    vector<unsigned int> m;


    cin >> x >> aux1 >> aux2 >> aux3;
    u.push_back(x);

    for(int i=1; i<n; i++)
    {
        u.push_back(((aux1*u.at(i-1))+aux2)%aux3);
        cout << u[i] << endl;
    }

    cin >> x >> aux1 >> aux2 >> aux3;
    d.push_back(x);

    for(int i=1; i<n; i++)
    {
        d.push_back(((aux1*d.at(i-1))+aux2)%aux3);
        cout << d[i] << endl;
    }


    cin >> x >> aux1 >> aux2 >> aux3;
    m.push_back(x);

    for(int i=1; i<n; i++)
    {
        m.push_back(((aux1*m.at(i-1))+aux2)%aux3);
        cout << m[i] << endl;
    }


}
