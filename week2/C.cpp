#include <iostream>

#ifndef N
#define N 6 // actual size of the array

#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
    }
}
void print_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cout << a[i] << " ";
    }
}

void shiftRight(int (&a)[N],unsigned k){
    for (k; k>0; k--){
        int tmp=a[N-1];
        for (int i = N-1; i > 0; i--){
            a[i]=a[i-1];
        }
        a[0]=tmp;
    }
}


int main(){
    int a[N];
    unsigned k;
    std::cin >> k;
    read_array(a);
    shiftRight(a, k);
    print_array(a);
}