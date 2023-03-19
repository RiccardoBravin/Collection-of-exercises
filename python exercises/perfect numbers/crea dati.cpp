#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>  //ifstream in("input.txt");      ofstream out("output.txt");
#include <string>
#include <math.h>
#include <time.h>
#include <cstdio>   //freopen("input.txt","r",stdin);   freopen("output.txt","w",stdout);

#define L 10000

using namespace std;

int main()
{
    long long int x,n;
    srand(time(NULL));

    for(int i = 0; i < L; i++)
    {
        x = rand() % L;
        if(x <= L % 200)
        {
            n = rand() % 22;

            switch (n)
            {
            case 0:
                printf("6,1\n");
                break;
            case 1:
                printf("28,1\n");
                break;
            case 2:
                printf("496,1\n");
                break;
            case 3:
                printf("8128,1\n");
                break;
            case 4:
                printf("33550336,1\n");
                break;
            case 5:
                printf("8589869056,1\n");
                break;
            case 6:
                printf("137438691328,1\n");
                break;
            case 7:
                printf("2305843008139952128,1\n");
                break;
            case 8:
                printf("2658455991569831744654692615953842176,1\n");
                break;
            case 9:
                printf("191561942608236107294793378084303638130997321548169216,1\n");
                break;
            case 10:
                printf("13164036458569648337239753460458722910223472318386943117783728128,1\n");
                break;
            case 11:
                printf("6,1\n");
                break;
            case 12:
                printf("6,1\n");
                break;
            case 13:
                printf("6,1\n");
                break;
            case 14:
                printf("6,1\n");
                break;
            case 15:
                printf("6,1\n");
                break;
            case 16:
                printf("6,1\n");
                break;
            case 17:
                printf("6,1\n");
                break;
            case 18:
                printf("6,1\n");
                break;
            case 19:
                printf("6,1\n");
                break;
            case 20:
                printf("6,1\n");
                break;
            case 21:
                printf("6,1\n");
                break;
            }


        }
        else
        {
            switch(rand()%10)
            {
            /*case 0:
                cout << rand() <<endl;
                break;
            case 1:
                cout << rand()*14153 << rand() <<endl;
                break;
            case 2:
                cout << rand()*44698 << rand() << rand() <<endl;
                break;
            case 3:
                cout << rand()*1654 << rand() << rand() << rand() <<endl;
                break;
            case 4:
                cout << rand()*15641 << rand() << rand() << rand() << rand() <<endl;
                break;
            case 5:
                cout << rand()*15647 << rand() << rand() << rand() << rand() << rand() <<endl;
                break;
            case 6:
                cout << rand()*1654 << rand() << rand() << rand() << rand() << rand() << rand() <<endl;
                break;
            case 7:
                cout << rand()*15645 << rand() << rand() << rand() << rand() << rand() << rand() << rand() <<endl;
                break;
            case 8:
                cout << rand()*1612 << rand() << rand() << rand() << rand() << rand() << rand() << rand() << rand() <<endl;
                break;*/
            case 9:
                //cout << rand()*48641 << rand()*4654 << rand()*1686 << rand()*1631 << rand()*5841 << rand()*4656 << rand()*6736 << rand()*4348 << rand()*7774 << rand()*456 <<endl;
                printf("%llu%llu%llu\n", rand()*rand());
                break;



            }

        }


    }
}

