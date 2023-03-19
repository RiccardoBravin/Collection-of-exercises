#include <iostream>
#include <cstring>

using namespace std;

bool is_palindrome(const char* first, const char* last);

int main(){
    char s1[] {'b', 'e', 'l', 'l', 'a', ' ', 'a', ' ', 't', 'u', 't', 't', 'i', '\0'};
    char s2[] {'c', 'i', 'a', 'o', ' ', 'a', 's', ' ', 'o', 'a', 'i', 'c', '\0'};
    char s3[] {'a', 's', 'd', 'd', 's', 'a', '\0'};
    char s4[] {'a', 's', 'd', 's', 'a', '\0'};
    char s5[] {'a', '\0'};
    char s6[10];
    

    cout << "s1 = " << is_palindrome(s1, &s1[strlen(s1) - 1]) << endl;
    cout << "s2 = " << is_palindrome(s2, &s2[strlen(s2) - 1]) << endl;
    cout << "s3 = " << is_palindrome(s3, &s3[strlen(s3) - 1]) << endl;
    cout << "s4 = " << is_palindrome(s4, &s4[strlen(s4) - 1]) << endl;
    cout << "s5 = " << is_palindrome(s5, &s5[strlen(s5) - 1]) << endl;
    cout << "s6 = " << is_palindrome(s6, &s6[strlen(s6) - 1]) << endl;
    cout << "s7 = " << is_palindrome(nullptr, nullptr) << endl;
    cout << "s8 = " << is_palindrome(s6, nullptr) << endl;
}

bool is_palindrome(const char* first, const char* last){
    if(first == nullptr || last == nullptr) return false;

    while(first < last){
        if(*first != *last)
            return false;
        --last;
        ++first;
    }
    return true;
}