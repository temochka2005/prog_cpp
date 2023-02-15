#include <iostream>

int amount(int N) {
        int fives=5;
        int counter=0;
        while( (N/fives) > 0){
                counter = counter + N/fives;
                fives = fives * 5;      
        }
        return(counter);
}

int main() { 
        int N;
        std::cin >> N;
        std::cout << amount(N) << std::endl;
}