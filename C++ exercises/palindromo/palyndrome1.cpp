#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const std::string& s);

int main(){
    string s1 {"bella a tutti"};
    string s2 {"asddsa"};
    string s3 {"asdsa"};
    string s4 {""};
    string s5 {};
    string s6;
    string s7 {"ciao as oaic"};

    cout << "s1 = " << is_palindrome(s1) << endl;
    cout << "s2 = " << is_palindrome(s2) << endl;
    cout << "s3 = " << is_palindrome(s3) << endl;
    cout << "s4 = " << is_palindrome(s4) << endl;
    cout << "s5 = " << is_palindrome(s5) << endl;
    cout << "s6 = " << is_palindrome(s6) << endl;
    cout << "s7 = " << is_palindrome(s7) << endl;
}

bool is_palindrome(const std::string& s){
    for(int i = 0; i < s.size()/2; i++){
        if(s.at(i) != s.at(s.size()-i-1))
            return false;
    }
    return true;
}