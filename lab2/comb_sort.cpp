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


void combSort(int (&a)[], int step, int N) {
    bubble_step(a, step, N);
    bubble_step(a, 1, N);
}


int time_measure(int (&a)[], int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) combSort(a, 4, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = 
        std::chrono::duration_cast <std::chrono::milliseconds>(end - begin);
        sum += time_span.count();
    }
    return sum / 5;
    
}


int main() {
    for (int N = 100; N < 5000; N+=100)
    {
        int a[N] = {0};
        for (int i = 0; i < N; i++){
            a[i] = random_number(N);
        }
        std::cout << time_measure(a, 15, N) << '\n';  
    }
}