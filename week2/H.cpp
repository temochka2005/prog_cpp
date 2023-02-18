#include <iostream>

#ifndef N
#define N 2// actual size of the array
#endif

#ifndef M
#define M 2// actual size of the array
#endif

void read_array(int (&a)[N][M]){
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j){
            std::cin >> a[i][j];
        }
    }
}

void print_transposed(int (&array)[N][M]){
    int array_T[M][N]={0};
     for(int i=0;i<N;i++){// Транспонируем
        for(int j=0;j<M;j++){
            array_T[j][i]=array[i][j];
            }
        }

    for(int i = 0; i < M; ++i) {  // Выводим на экран строку i
        for(int j = 0; j < N; ++j) {
            std::cout << array_T[i][j] << " ";}
        std::cout << std::endl;// Строка завершается символом перехода на новую строку
    }

}


int main(){
    int array[N][M];
    read_array(array);
    print_transposed(array);
}

