#include <iostream>

#ifndef N
#define N 6// actual size of the array
#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
    }
}

void doubleSelectSort(int (&a)[N]){
    int min_index = 0;
    int max_index = 0;

    for (int j = 0; j < N/2; j++){
       int min = 2147483647;
       int max = -2147483647;
       int tmp;
       for (int i = j; i < N - j; i++){
        if ( min > a [i]){
            min = a [i];
            min_index = i;
        }
        if ( a[i] > max){
            max = a [i];
            max_index = i;
        }

       }
       tmp = a[j];
       if ( j == max_index){
        max_index = min_index;
       }
        a[j] = min;
        a[min_index] = tmp;
        tmp = a[N - j - 1];
        a[N - j - 1] = max;
        a[max_index] = tmp;  
    }

    for (int i = 0; i < N; i++) std::cout << a[i] << ' ';
}

int main(){
    int a[N];
    read_array(a);
    doubleSelectSort(a);
}
