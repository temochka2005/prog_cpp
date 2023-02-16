#include <iostream>

#ifndef N
#define N 4 // actual size of the array
#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
    }
}

void print_reversed_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cout << a[N-i-1] << " ";
    }
}

void reverseArray(int (&a)[N]){
read_array(a);
print_reversed_array(a);
}

int main(){
    int a[N];
 reverseArray(a);
}