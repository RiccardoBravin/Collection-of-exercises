#include <iostream>
#include <cstring>

using namespace std;

bool is_palindrome(const char s[], int length);



int main(){
    char s1[] {'b', 'e', 'l', 'l', 'a', ' ', 'a', ' ', 't', 'u', 't', 't', 'i', '\0'};
    char s2[] {'c', 'i', 'a', 'o', ' ', 'a', 's', ' ', 'o', 'a', 'i', 'c', '\0'};
    char s3[] {'a', 's', 'd', 'd', 's', 'a', '\0'};
    char s4[] {'a', 's', 'd', 's', 'a', '\0'};
    char s5[] {'a', '\0'};
    char s6[2];

    cout << "s1 = " << is_palindrome(s1, strlen(s1)) << endl;
    cout << "s2 = " << is_palindrome(s2, strlen(s2)) << endl;
    cout << "s3 = " << is_palindrome(s3, strlen(s3)) << endl;
    cout << "s4 = " << is_palindrome(s4, strlen(s4)) << endl;
    cout << "s5 = " << is_palindrome(s5, strlen(s5)) << endl;
    cout << "s6 = " << is_palindrome(s6, strlen(s6)) << endl;
    cout << "s7 = " << is_palindrome(nullptr, 0) << endl;
    
}

bool is_palindrome(const char s[], int length){
    if(s == nullptr) return false;
    for(int i = 0; i < length; i++){
        if(s[i] != s[length-i-1])
            return false;
    }
    return true;
}