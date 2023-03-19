#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define INTERESSE 10

class Conto
{
    unsigned int conto;
    float soldi=0;
    int p=0;
    int d=0;
public:
    void saldo();
    void preleva();
    void deposita();
    void lastp();
    void lastd();
};

void Conto::saldo()
{
    printf("Il saldo del suo conto e': %2.f",soldi);
}

void Conto::preleva()
{
    printf("Quanto denaro desidera prelevare?\n");
    scanf("%d",&p);

    if(soldi-p<-3000)
        printf("Siamo spiacenti ma non e' stato possibile effettuare il prelievo\nSaldo insufficiente");
    else if(p>1500)
        printf("Siamo spiacenti ma non e' stato possibile effettuare il prelievo\nPrelievo massimo giornaliero superato");
    else
    {
        soldi-=p;
        printf("Prelievo effettuato\nIl nuovo saldo ammonta a: %2.f",soldi);
    }
}

void Conto::deposita()
{
    printf("Quanto denaro desidera depositare?\n");
    scanf("%d",&d);

    if(soldi<0)
        {
            //soldi+=(d/100)*(100-INTERESSE);
            soldi+=(d*0.9);
            printf("Deposito completato\nIl nuovo saldo ammonta a: %2.f",soldi);
        }
    else
        {
            soldi+=d;
            printf("Deposito completato\nIl nuovo saldo ammonta a: %2.f",soldi);
        }
}

void Conto::lastd()
{
    printf("Il suo ultimo deposito e' stato di: %d",d);
}

void Conto::lastp()
{
    printf("Il suo ultimo prelievo e' stato di: %d",p);
}

int main()
{
    int s,x;

    printf("BENVENUTO SUL PORTALE WEB DELLA TUA BANCA\n");
    printf("Siete pregati di inserire il codice a sei cifre relativo al suo conto : ");
    scanf("%d",&x);

    Sleep(1000);
    system("CLS");

    Conto c1;

    do{
        printf("Che azione vuole compiere su questo conto?\n");
        printf("[1] Visualizzare il saldo\n[2] Prelevare\n[3] Depositare\n[4] Visualizzare l'ultimo deposito\n[5] Visualizzare l'ultimo prelievo\n[6]Logout\n");
        //printf("E' possibile uscire in qualsiasi momento digitando '6' da tastiera\n");
        printf("\nScelta : ");
        scanf("%d",&s);
        printf("\n");
        if(s==1)
            c1.saldo();
        else if(s==2)
            c1.preleva();
        else if(s==3)
            c1.deposita();
        else if(s==4)
            c1.lastd();
        else if(s==5)
            c1.lastp();
        else
            printf("La sua scelta non è contemplata tra quelle proposte");

        Sleep(2000);
        system("CLS");
    }while(s!=6);

    printf("Grazie per averci scelto\nArrivederci");

}
