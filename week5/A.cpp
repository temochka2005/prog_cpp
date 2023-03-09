#include <iostream>


int main(){
    double * dprt;
    double i = 0;
    *dprt = i;
    std::cout << dprt << ' ' << *dprt << std::endl;
    dprt = dprt - 3; 
    std::cout << dprt << ' ' << *dprt << std::endl;
    dprt = dprt + 5; 
    std::cout << dprt << ' ' << *dprt << std::endl; 
}
