#include <iostream>


int main(){
    int counter = 0;
    int * prt = new int();
    *(prt-1) = 1;
    while ( *(prt+counter-1) != 0 ){ 
         std::cin >> *(prt+counter);
        ++counter;
    }
    for (int i = 0; i < counter-2; ++i){
        std::cout << prt[i]-prt[i+1] << " ";
    }
}
