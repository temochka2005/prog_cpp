#include <iostream>

void input_array(int* ptr, size_t N);
void reverse(int* ptr, size_t N);
void print(const int* ptr, size_t N);

void input_array(int* ptr, size_t N){
    for(int i = 0;i<N; ++i){
        std::cin >> ptr[i];
    }
}

void reverse(int* ptr, size_t N){
    for(int i = 0;i<N/2; ++i){
        int tmp = ptr[i];
        ptr[i] = ptr[N-i-1];
        ptr[N-i-1] = tmp;
    }
}

void print(const int* ptr, size_t N){
    for(int i = 0;i<N; ++i){
        std::cout << ptr[i] << " ";
    }
}

int main() {
    int N = 0;
    std::cin >> N;
    int* ptr = new int[N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
}