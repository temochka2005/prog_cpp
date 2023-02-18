#include <iostream>

#ifndef N
#define N 3 // actual size of the array
#endif

void read_array(int (&a)[N]) {
    for (int i = 0; i < N; ++i){
        std::cin >> a[i];
    } 
}


void print_array(int (&result_array)[ 2 * N ]){
    for (int i = 0; i < 2 * N; i++){
        std::cout << result_array[i] << " ";
    }
}

void sort(int (&result_array)[2 * N]){
    int temp;
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = 0; j < 2 * N - i - 1; j++) {
            if (result_array[j] > result_array[j + 1]) {
                temp = result_array[j];
                result_array[j] = result_array[j + 1];
                result_array[j + 1] = temp;
            }
        }
    }
}

void mergeArrays(int (&a)[N], int (&b)[N], int (&result_array)[2 * N]){
    for (int i = 0; i < N; i++){
        result_array[i] = a [i];
        result_array[2 *N - i - 1] = b[i];
    }   
    sort(result_array);
}


int main(){
    int a[N];
    int b[N];
    int result_array[2 * N];  
    read_array(a);
    read_array(b);  
    mergeArrays(a,b,result_array);
    print_array(result_array);

}