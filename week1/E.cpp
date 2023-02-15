#include <iostream>

int recursive_power(int base, int power) {
    if (power == 0){
        return 1;
    } else {
        while (power != 0){
        power-=1;
        return base * recursive_power(base, power);
        }
    }  
}

int main() {
    int base, power;
    std::cin >> base >> power;
    std::cout << recursive_power(base, power)<< std::endl;   
}