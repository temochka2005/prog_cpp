#include <iostream>


int main(){
    short int * sprt = new short int[10];
    for(short int i = 0; i<10; ++i){
        sprt[i] = i;
        std::cout << &sprt[i] << " ";
    }
    std::cout << std::endl;
    for(short int k = 0; k<10; ++k){
        std::cout << sprt[k] << " ";
    }
    std::cout << std::endl;
    for(short int i = 0; i<9; i+=2){
        sprt[i] = sprt[i] * sprt[i];
        std::cout << sprt[i] << " " << sprt[i+1] << " ";
    }
}
