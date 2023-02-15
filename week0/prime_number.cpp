#include <iostream>

int main() { 
    int a=14;
    int b=0;
    for(int i = 2; i<(a/2); i+=1) {
        if ((a%i) == 0) {
            b+=1;
        }
    }
    if (b>0) { 
        std::cout << "число a не является простым" << std::endl;
    } else {
        std::cout << "число a является простым" << std::endl;}
}