#include <iostream>

void forward_step(unsigned (&arr)[], unsigned const begin_idx, unsigned const end_idx) {
    for (int i = begin_idx; i < end_idx; i++) {
        if (i != end_idx-1){
            if (arr[i+1] < arr[i]) std::swap(arr[i], arr[i+1]);
        }
    } 
}

void backward_step(unsigned (&arr)[], unsigned const begin_idx, unsigned const end_idx) {
    if (begin_idx != end_idx)
    {
        for (int i = begin_idx; i > end_idx; i--) {
            if (arr[i-1] > arr[i]) std::swap(arr[i], arr[i-1]);
        } 
    } 
}


void shaker_sort(unsigned (&arr)[], unsigned const begin_idx, unsigned const end_idx) {
    for (int i = 0; i <= (end_idx - begin_idx) / 2; i++) {
        forward_step(arr, begin_idx, end_idx);
        if (end_idx != 0) {
            backward_step(arr, end_idx-1, begin_idx);
        }
    } 
}



int main() {
    unsigned N=6;
    unsigned arr[N]={0};
    unsigned tmp[N]={5, 4, 3, 2, 1, 0};
    for (unsigned i = 0; i < N; i++){
        arr[i] = i;
    }
    shaker_sort(tmp, 0, N);
    for (unsigned i = 0; i<N; i++){
        if (arr[i] != tmp[i]){
            std::cout << "test failed" << std::endl;
            break;
        }
    }
    std::cout<< "test completed" << std::endl;
    
}