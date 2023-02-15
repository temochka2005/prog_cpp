#include <iostream>

bool is_leap(int N) {
   return ( (N%4 == 0 and N%100 != 0) or (N%400 == 0) );
}

int main() {
    int N;
    std::cin >> N;
    if ( is_leap(N) ) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}