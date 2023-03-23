#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 1000-7;
std::default_random_engine rng(seed);

int random_number_in_array(int a[], int actual_size) {
    std::uniform_int_distribution<unsigned> dstr(0 , actual_size);
    return a[dstr(rng)];
}


int strategy_A(int a[], int number, int actual_size) {
    for (int i = 0; i < actual_size; i++)
    {
        if (a[i] == number) {
            std::swap(a[i], a[0]);
            return i;
        } 
    } 
    return -1;
}


int time_measure_A(int a[], int number, int multiplier, int actual_size) { 
    auto begin = std::chrono::steady_clock::now();
    for(int cnt = multiplier; cnt != 0 ; --cnt)
        strategy_A(a, number, actual_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return time_span.count()/multiplier;
    
}


int main() {
    int N=100000;
    for (int n = 512; n < N; n*=2){

        auto begin = std::chrono::steady_clock::now();
        int * a = new int[n];
        auto end = std::chrono::steady_clock::now();
        auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        std::cout << "Время на выделение массива: " << time_span.count() << " нс; Время поиска: ";
        for (int i = 0; i < n; ++i){
            a[i] = i;
        }
        //int number = random_number_in_array(a, n);
        int number = n+1;
        std::cout <<  "A " << time_measure_A(a, number, 100, n) << std::endl;
    }

}