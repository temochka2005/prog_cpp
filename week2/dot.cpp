#include <iostream>
#ifndef N
#define N 10
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
int dot(int (&a)[N], int (&b)[N]) {
    int res = 0;
    for (int i = 0; i<N; ++i){
      res += a[i] * b[i];  
    }
    return res;
}


int main(){
    int a[N];
    read_array(a);
    print_array(a);
}