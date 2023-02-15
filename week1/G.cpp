#include <iostream>


int main() {
    int counter_for_local_max = 0;
    int counter_for_local_min = 0;
    int N;
    int number;
    int previous;
    int next;
    std::cin >> N;
    for (int i = 0; i <= N/2; i+= 1) {
        std::cin >> number;
        if (i>0) {
            std::cin >> next;
            if ( (number > previous) and (number > next) ) {
                counter_for_local_max+=1;
            } else if ( (number < previous) and (number < next) ) {
                counter_for_local_min+=1;
            }
        }
        previous = number;

    }
    if (counter_for_local_max > counter_for_local_min){
        std::cout << "MAX" << std::endl;
    } else if (counter_for_local_max < counter_for_local_min){
        std::cout << "MIN" << std::endl;
    } else  {
        std::cout << "EQUAL" << std::endl;
    }
       
}