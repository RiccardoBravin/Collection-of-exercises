#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Cypher
{
public:
    string getS(){return code;}

private:
    Cypher(string a, char x){code = a;n = x;}
    string code;
    char n;
    void cy(string a, char n);
};

void Cypher::cy(string a, char n)
{
    int x;
    x = n;
    for(int i=0; i < a.size(); i++)
    {
        if(a.at(i)>=97 && a.at(i)<=97+26)
        {
            if(a.at(i)+(n%32)>97+26)
                a.replace(i,1,(a.at(i)+((x%32)+26)));
            else
                a.replace(i,1,(a.at(i)+(x%32)));
        }
        else if(a.at(i)>=65 && a.at(i)<=65+26)
        {
            if(a.at(i)+(n%32)>65+26)
                a.replace(i,1,(a.at(i)+((x%32)+26)));
            else
                a.replace(i,1,(a.at(i)+(x%32)));
        }
    }
}



int main()
{
    int x;
    string a;

    cout << "Inserisci la stringa da cifrare: ";
    cin >> a;
    cout << "Inserisci la chiave di cifratura: ";
    cin >> x;

    Cypher c(a,x);

    cout << c.getS();

}
