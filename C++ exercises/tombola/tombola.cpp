#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define C 5
#define R 3
#define X 10
#define Y 9

class Cartellina
{
    int ina[R][C];

    bool control(int n);

public:
    int atqc();
    bool tombola();
    void estc();
    void print();
    void escludi(int n);
};


class Cartellone
{
    int one[Y][X];
    bool control(int n);
public:
    void setup();
    void printc();
    int est();
};

int Cartellina::atqc()
{
    int x=0,n=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
            {
                if(ina[i][j]==0)
                    x++;
            }
        if(x>n)
            n=x;
        x=0;
    }
    return n;
}

bool Cartellina::control(int n)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
            {
                if (ina[i][j]==n)
                    return true;
            }
    }
    return false;
}

void Cartellina::estc()
{
    int n;


    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            ina[i][j]=0;
        }
    }

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            n=rand()%90+1;
            if (control(n)== false)
                ina[i][j]=n;
            else
                j--;

        }
    }
}

bool Cartellina::tombola()
{
    for(int m=0;m<R;m++)
    {
        for(int n=0;n<C-1;n++)
            {
                if (ina[m][n]!=ina[m][n+1])
                    return false;
            }
    }
    return true;
}

void Cartellina::print()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            printf("%2d ",ina[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Cartellina::escludi(int n)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(n==ina[i][j])
                ina[i][j]=0;
        }
    }
}


void Cartellone::printc()
{
    for(int i=0;i<Y;i++)
    {
        for(int j=0;j<X;j++)
        {
            printf("%2d ",one[i][j]);
        }
        printf("\n");
    }
}

void Cartellone::setup()
{
    for(int i=0;i<Y;i++)
    {
        for(int j=0;j<X;j++)
        {
            one[i][j]=(i*10)+j+1;
        }
    }
}

bool Cartellone::control(int n)
{
    for(int i=0;i<Y;i++)
    {
        for(int j=0;j<X;j++)
            {
                if (one[i][j]==n)
                    return true;
            }
    }
    return false;
}

int Cartellone::est()
{
    int m=rand()%90+1;;

    for(int i=0;i<Y;i++)
    {
        for(int j=0;j<X;j++)
        {
            if(m==one[i][j])
                one[i][j]=0;
        }
    }
    return m;
}

int main()
{
    int n, pl=0, x=0;
    srand(time(0));
    Cartellina p1;
    Cartellina p2;
    Cartellina p3;
    Cartellina p4;
    Cartellone i;
    p1.estc();
    p2.estc();
    p3.estc();
    p4.estc();
    i.setup();

    p1.print();
    p2.print();
    p3.print();
    p4.print();
    i.printc();
    Sleep(5000);

    while(pl==0){
        if(p1.tombola())
            pl=1;
        else if(p2.tombola())
            pl=2;
        else if(p3.tombola())
            pl=3;
        else if(p4.tombola())
            pl=4;
        system("CLS");

        n=i.est();
        p1.escludi(n);
        p2.escludi(n);
        p3.escludi(n);
        p4.escludi(n);

        p1.print();
        p2.print();
        p3.print();
        p4.print();
        i.printc();

        if(p1.atqc()==2&&x<1){
            printf("Il primo giocatore ha fatto ambo");
            x++;
            Sleep(5000);
        }else if(p2.atqc()==2&&x<1){
            printf("Il secondo giocatore ha fatto ambo");
            x++;
            Sleep(5000);
        }else if(p3.atqc()==2&&x<1){
            printf("Il terzo giocatore ha fatto ambo");
            x++;
            Sleep(5000);
        }else if(p4.atqc()==2&&x<1){
            printf("Il quarto giocatore ha fatto ambo");
            x++;
            Sleep(5000);
        }

        if(p1.atqc()==3&&x<2){
            printf("Il primo giocatore ha fatto terna");
            x++;
            Sleep(5000);
        }else if(p2.atqc()==3&&x<2){
            printf("Il secondo giocatore ha fatto terna");
            x++;
            Sleep(5000);
        }else if(p3.atqc()==3&&x<2){
            printf("Il terzo giocatore ha fatto terna");
            x++;
            Sleep(5000);
        }else if(p4.atqc()==3&&x<2){
            printf("Il quarto giocatore ha fatto terna");
            x++;
            Sleep(5000);
        }

        if(p1.atqc()==4&&x<3){
            printf("Il primo giocatore ha fatto quaterna");
            x++;
            Sleep(5000);
        }else if(p2.atqc()==4&&x<3){
            printf("Il secondo giocatore ha fatto quaterna");
            x++;
            Sleep(5000);
        }else if(p3.atqc()==4&&x<3){
            printf("Il terzo giocatore ha fatto quaterna");
            x++;
            Sleep(5000);
        }else if(p4.atqc()==4&&x<3){
            printf("Il quarto giocatore ha fatto quaterna");
            x++;
            Sleep(5000);
        }

        if(p1.atqc()==5&&x<4){
            printf("Il primo giocatore ha fatto cinquina");
            x++;
            Sleep(5000);
        }else if(p2.atqc()==5&&x<4){
            printf("Il secondo giocatore ha fatto cinquina");
            x++;
            Sleep(5000);
        }else if(p3.atqc()==5&&x<4){
            printf("Il terzo giocatore ha fatto cinquina");
            x++;
            Sleep(5000);
        }else if(p4.atqc()==5&&x<4){
            printf("Il quarto giocatore ha fatto cinquina");
            x++;
            Sleep(5000);
        }

        Sleep(100);

        //Sleep(1000);
    };
    printf("Il %n giocatore ha fatto tombola!",pl);
}
