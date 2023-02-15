#include <iostream>


int main() {
    int counter_for_max = 0;
    int counter_for_min = 0;
    int N;
    int number;
    int previous;
    std::cin >> N;
    for (int i = 0; i < N; i+=1) {
        std::cin >> number;
            if (number > previous){
                counter_for_max+=1;
            } else {
                counter_for_min+=1;
            }
        previous = number;
    }
    if (counter_for_max >= counter_for_min){
        std::cout << "MAX" << std::endl;
    } else{
        std::cout << "MIN" << std::endl;
    }
       
}