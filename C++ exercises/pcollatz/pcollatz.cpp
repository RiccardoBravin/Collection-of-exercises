#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
#include <cstdio>


using namespace std;

unsigned int collatz(unsigned int x)
{
    unsigned int i=0;
    while(x!=1)
    {
        if(x%2==0)
            x /= 2;
        else
        {
            x *= 3;
            x++;
        }
        i++;
    }
    return i;
}

bool pcollatz(unsigned int x)
{
    unsigned int n = collatz(x),i=0;

    while(x!=1 && n != i)
    {
        if(x%2==0)
            x /= 2;
        else
        {
            x *= 5;
            x++;
        }
        i++;
    }

    if(n > i)
        return true;
    else
        return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    unsigned int s,f;

    unsigned int i=0;

    cin >> s >> f;

    for(s; s<=f; s++)
    {
        if(pcollatz(s))
            i++;

    }

    cout << i;
}
