#include <iostream>

#ifndef N
#define N 7// actual size of the array
#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
    }
}

void findLastZero(int (&a)[N]){
    int i = 0;
    int k = N;
    while ( k > 0 ){ 
         if ( (a[i+1] == 1) and (a[i] == 0) ){
             std::cout<<i;
             return;
             }
        if ( a[i]== 0 ){
            i = (N+i)/2;
        } else { i = i/2;
        }
        k = k/2;
    }
    std::cout << i;
}

int main(){
    int a[N];
    read_array(a);
    findLastZero(a);
}