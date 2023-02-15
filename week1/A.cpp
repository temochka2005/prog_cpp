#include <iostream>
bool is_palindrome(int N){
    int c = 0;
    int number = N;
    int i = 0; 
    int amount = N;
    for(; amount>0;i+=1){
        amount=amount/10;
    }
    while (number > 0){
        int k = number%10;
        for(int d = i; d>1; d-=1)
        {

            k*=10;  
        }
        c+=k;
        i-=1;
        number=number/10;
    }
    return (c==N);
}

int main() {
    int N;
    std::cin >> N;
    if ( is_palindrome(N) ) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}