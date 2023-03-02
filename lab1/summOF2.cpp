#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 1000-7;
std::default_random_engine rng(seed);

int random_number_in_array(int a[], int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return a[dstr(rng)];
}

int random_number(int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return dstr(rng);
}

int lin_sum(int a[], int number, int N){
    int left = 0;
    int right = N - 1;
    while ( (a[left] + a[right] != number) and (left != right))
    {
        if (a[left] + a[right] > number) {
            right--;
        }
        if (a[left] + a[right] < number){
            left++;
        }        
    }
    if (a[left] + a[right] == number) return (a[left] + a[right]);
    return -1;
}

int sqr_finder(int a[], int k, int N) {
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (a[i] + a[j] == k){
                return 1;
            }
        }
        
    }
    return -1;
}



int time_measure(int a[], int number, int multiplier, int N) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 1; i < multiplier; i++) lin_sum(a, number, N);
        auto end = std::chrono::steady_clock::now();
        auto time_span = 
        std::chrono::duration_cast <std::chrono::milliseconds>(end - begin);
        sum += time_span.count();
    }
    return sum / 5;
    
}


int main() {
    for (int N = 512; N < 262144+1; N*=2)
    {
        int a[N];
        for (int i = 0; i < N; i++)
        {
            a[i] = i;
        }
        int number = random_number(N);
        std::cout << time_measure(a, number, 10000, N) << '\n';    
    }
}
