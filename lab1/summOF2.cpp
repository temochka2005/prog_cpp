#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 1000-7;
std::default_random_engine rng(seed);

int random_number(int N) {
    std::uniform_int_distribution<unsigned> dstr(0 , N);
    return dstr(rng);
}

int lin_sum(int a[], int number, int actual_size){
    int left = 0;
    int right = actual_size - 1;
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

int sqr_finder(int a[], int k, int actual_size) {
    for (int i = 0; i < actual_size - 1; i++)
    {
        for (int j = i+1; j < actual_size; j++)
        {
            if (a[i] + a[j] == k){
                return 1;
            }
        }
        
    }
    return -1;
}



int time_measure(int a[], int number, int multiplier, int actual_size) { 
    auto begin = std::chrono::steady_clock::now();
    for(int cnt = multiplier; cnt != 0 ; --cnt)
        sqr_finder(a, number, actual_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    return time_span.count()/multiplier;
    
}


int main() {
    int N = 100000;
    int a[N]={0};
    for (int n = 128; n < N; n*=2){    
        for (int i = 0; i < n; i++){
            a[i] = i;
        }
        int number = -1;
        std::cout <<  time_measure(a, number, 100, n) << std::endl;  
    }

}
