#include <iostream>
#include <chrono>
#include <random>

unsigned seed = 1000-7;
std::default_random_engine rng(seed);

int random_number_in_array(int a[], int actual_size) {
    std::uniform_int_distribution<unsigned> dstr(0 , actual_size);
    return a[dstr(rng)];
}


int bin_search(int a[], int number, int actual_size){
    int left = -1;
    int right = actual_size - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (a[mid] <= number) {
            left = mid;
        } else {
            right = mid;
        } 
    }
    if ( (left > -1) and (a[left] == number) ) {
        return left;
    }      
    return -1;
}


int time_measure(int a[], int number, int multiplier, int actual_size) { 
    auto begin = std::chrono::steady_clock::now();
    for(int cnt = multiplier; cnt != 0 ; --cnt)
        bin_search(a, number, actual_size);
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
        std::cout <<  time_measure(a, number, 1000, n) << std::endl;
        delete[] a;  
    }

}