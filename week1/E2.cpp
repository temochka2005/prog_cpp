#include <iostream>

int recursive_power(int base, int power) {
    int result=base;
    if (power == 0){
        return 1;
    } else {
        while (power != 1){
        power-=1;
        result = result * base;
        }
    }
    return(result);  
}

int main() {
    int base, power;
    std::cin >> base >> power;
    std::cout << recursive_power(base, power)<< std::endl;   
}