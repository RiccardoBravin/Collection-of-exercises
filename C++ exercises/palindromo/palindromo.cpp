#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    int x;

    cout << "Inserisci una stringa per vedere se e' palindroma: ";
    cin >> s;

    for(int i=0; i<=(s.size()/2); i++)
    {
        if(s.at(i)+32==s.at(s.size()-i-1))
            x++;
        else if(s.at(i)==s.at(s.size()-i-1)+32)
            x++;
        else if(s.at(i)==s.at(s.size()-i-1))
            x++;
    }

    if(x==(s.size()/2))
        cout << "La stringa '" << s << "' e' palindroma";
    else
        cout << "La stringa '" << s << "' non e' palindroma";
}
