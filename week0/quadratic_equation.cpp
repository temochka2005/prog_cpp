#include <iostream>

int main() {
    int a = 1; 
    int b = 5;
    int c = 6;
    const int D = b*b - 4*a*c;
    if (a==0){
        std::cout << (-c)/b << std::endl;
    } else {
        std::cout << "x1 =-b+D/(2a), x2 = (-b-D)/(2a), где b = " << b << ", a = " << a << ", D = " << b*b - 4*a*c << std::endl;
        std:: cout << "x1 = " << (-b+D)/(2*a) << " x2 = " << (-b-D)/(2*a) << std::endl;
    }
}
