#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 1000-7;
std::default_random_engine rng(seed);

int random_number_in_array(int a[], int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return a[dstr(rng)];
}

int lin_search(int a[], int number, int N){
    for (int i = 0; i < N; i++){
        if (a[i] == number){
            return i;
        }
        if ( (a[i] != number) and (i = N - 1) ){
            return -1;
        }
    }
}

int bin_search(int a[], int number, int N){
    int left = -1;
    int right = N - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (a[mid] <= number) {
            left = mid;
        } else {
            right = mid;
        } 
    }
    if (left > -1 && a[left] == number) {
        return left;
    } else {
        return -1;
    }
}


int time_measure(int a[], int number, int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i <5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) lin_search(a, number, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = 
        std::chrono::duration_cast <std::chrono::milliseconds>(end - begin);
        sum += time_span.count();
    }
    return sum / 5;
    
}

int main() { 
    for (int N = 512; N < 1000000; N*=2){
        int a[N];
        for (int i = 0; i < N; i++){
            a[i] = i;
        }
        int number = N;
        std::cout << time_measure(a, number, 10000, N) << '\n';  
    }

}