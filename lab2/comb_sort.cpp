#include <iostream>
#include <chrono>
#include <random>


unsigned seed = 1000-7;
std::default_random_engine rng(seed);
int random_number(int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return dstr(rng);
}


void bubble_step(int (&a)[], int step, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j+=step) {
            if (a[j] < a[i]) std::swap(a[i], a[j]);
        }
    }
}


void combSort(int (&a)[], int step, int actual_size) {
   // bubble_step(a, step, actual_size);
    bubble_step(a, 1, actual_size);
}


int time_measure(int (&a)[], int step, int multiplier, int actual_size) { 
    auto begin = std::chrono::steady_clock::now();
    for(int cnt = multiplier; cnt != 0 ; --cnt)
        combSort(a, step , actual_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    return time_span.count()/multiplier;
    
}


int main() {
    int N = 5000;
    int a[N]={0};
    for (int n = 100; n < N; n+=100){
        
        for (int i = 0; i < n; i++){
            a[i] = random_number(n);
        }
        std::cout <<  time_measure(a, 4, 100, n) << std::endl;  
    }
}