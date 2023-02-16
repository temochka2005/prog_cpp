#include <iostream>

#ifndef N
#define N 3 // actual size of the array
#endif

void print_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cout << a[i] << " ";
    }
}

void moveNegativeToEnd(int (&a)[N]){
    int tmp_plus[N]={0};
    int tmp_minus[N]={0};
    int negative_counter = 0;
    int positive_counter = 0; 
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
        if (a[i] >= 0){
            tmp_plus[positive_counter]=a[i];
            positive_counter++;
        } else {
            tmp_minus[negative_counter]=a[i];
            negative_counter++;
        }
    }
    for (int i = 0; i < N; i++){
        a[i] = tmp_plus[i];
    }
    int j=0;
    for (int k = N - negative_counter; k < N; k++){
        a[k] = tmp_minus[j];
        j++;
    }
}


int main(){
    int a[N];
    moveNegativeToEnd(a);
    print_array(a);

}