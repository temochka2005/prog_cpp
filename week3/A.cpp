#include <iostream>

#ifndef N
#define N 5// actual size of the array
#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
    }
}

void selectSort(int (&a)[N]){
    for (int i = 0; i < N - 1; i++){
        int min_index = i;
        for (int k = i + 1; k < N; k++){
            if (a[k] < a[min_index]){
                min_index = k;
                }
        }
        if (min_index != i){
            std::swap(a[i], a[min_index]);
        }
    }
    for (int i = 0; i < N; i++) std::cout << a[i] << ' ';
}

int main(){
    int a[N];
    read_array(a);
    selectSort(a);
}
