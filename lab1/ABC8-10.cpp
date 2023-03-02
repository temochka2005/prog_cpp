#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 1000-7;
std::default_random_engine rng(seed);

int random_number_in_array(int a[], int actual_size) {
    std::uniform_int_distribution<unsigned> dstr(0 , actual_size);
    return a[dstr(rng)];
}


int lin_search(int a[], int number, int actual_size) {
    for (int i = 0; i < actual_size; i++)
    {
        if (a[i] == number) {
            return i;
        }
    }
    return -1;
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


int strategy_B(int a[], int number, int actual_size) {
    for (int i = 0; i < actual_size; i++)
    {
        if (a[i] == number) {
            if (i != 0) std::swap(a[i], a[i-1]);
            return i;
        } 
    } 
    return -1;
}


int strategy_C(int a[], int number, int actual_size) {
    int counter_list[actual_size] = {0};
    for (int i = 0; i < actual_size; i++)
    {
        if (a[i] == number) {
            counter_list[i] += 1;
            if (i != 0 and counter_list[i] > counter_list[i-1]) {
                std::swap(a[i], a[i-1]);
                std::swap(counter_list[i], counter_list[i-1]);}
            return i;
        }
    } 
    return -1;
}


int time_measure_linr(int a[], int number, int multiplier, int actual_size) { 
    auto begin = std::chrono::steady_clock::now();
    for(int cnt = multiplier; cnt != 0 ; --cnt)
        lin_search(a, number, actual_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return time_span.count()/multiplier;
    
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

int time_measure_B(int a[], int number, int multiplier, int actual_size) { 
    auto begin = std::chrono::steady_clock::now();
    for(int cnt = multiplier; cnt != 0 ; --cnt)
        strategy_B(a, number, actual_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return time_span.count()/multiplier;
    
}

int time_measure_C(int a[], int number, int multiplier, int actual_size) { 
    auto begin = std::chrono::steady_clock::now();
    for(int cnt = multiplier; cnt != 0 ; --cnt)
        strategy_C(a, number, actual_size);
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return time_span.count()/multiplier;
    
}

int main() {
    int N = 100000;
    int a[N]={0};
    for (int n = 512; n < N; n*=2){
        
        for (int i = 0; i < n; i++){
            a[i] = i;
        }
    
        int number = n+1;
        std::cout <<  "Lin " << time_measure_linr(a, number, 100, n) << std::endl;
        std::cout <<  "A " << time_measure_A(a, number, 100, n) << std::endl;
        std::cout <<  "B " << time_measure_B(a, number, 100, n) << std::endl;
        std::cout <<  "C " << time_measure_C(a, number, 100, n) << std::endl;  
        // Если я правильно понял замечания, которые говорили для Саши, то вот попробовал сделать так, 
        // чтобы на одном и том же массиве данных сравнить предложенные стратегии и линейный поиск
    }

}