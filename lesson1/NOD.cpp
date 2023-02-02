#include <iostream>

int main() { 
    int a=28;
    int b=56;
    while(a!=0 and b!=0) {
        if (a>b) {
            a=a%b;
        } else { 
            b=b%a;
             }
    }
    std::cout << (a+b) << std::endl;
}