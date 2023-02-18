#include <iostream>

#ifndef N
#define N 9// actual size of the array
#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
    }
}

int findUnique(int (&a)[N]){
    int result = 0;
    for ( int i = 0; i<N; i++){
        result ^= a[i];
    }
    return result;
}


int main(){
    int a[N];
    read_array(a);
    std::cout << findUnique(a);

}

