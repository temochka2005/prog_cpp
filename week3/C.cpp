#include <iostream>

#ifndef N
#define N 8// actual size of the array
#endif

void read_array(int (&a)[N]){
    for (int i = 0; i < N; i++){
        std::cin >> a[i];
    }
}

void flip(int (&a)[N], int n) {
	for (int i = 0; i < n; i++) {
		std::swap(a[i], a[n-1]);
        n--;
	}
}

void pancakeSort(int (&a)[N]){
    for (int i = N - 1; i >= 0; --i){
		int index = i;
		for (int j = 0; j < i; j++){
			if (a[j] > a[index]){ index = j;
            }
		}
		if (index == i){ 
            continue;
        }
		if (index != 0){
            flip(a, index + 1);
        }
		flip(a, i + 1);
	}
    for (int i = 0; i < N; i++) std::cout << a[i] << ' ';
}


int main(){
    int a[N];
    read_array(a);
    pancakeSort(a);
}
