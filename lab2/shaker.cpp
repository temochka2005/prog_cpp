#include <iostream>

void forward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (int i = begin_idx; i < end_idx; i++) {
        if (i != end_idx-1){
            if (arr[i+1] < arr[i]) std::swap(arr[i], arr[i+1]);
        }
    } 
}

void test_forward() {
    unsigned test_arr1[1] = {10};
    unsigned arr2[3] = {1, 2, 3};
    unsigned arr3[5] = {5, 4, 3, 2, 1};
    unsigned tmp1[1] = {10};
    unsigned tmp2[3] = {1, 2, 3};
    unsigned tmp3[5] = {4, 3, 2, 1, 5};
    forward_step(test_arr1, 0, 1);
    forward_step(arr2, 0, 3);
    forward_step(arr3, 0, 5);
    for (int i = 0; i < 1; i++)
    {
        if (test_arr1[i] != tmp1[i]) {
            std::cout << "test1_forward failed" <<'\n';
            break;
        } else if (i == 0) {
            std::cout << "test1_forward passed" <<'\n';
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (arr2[i] != tmp2[i]) {
            std::cout << "test2_forward failed" <<'\n';
            break;
        } else if (i == 2) {
            std::cout << "test2_forward passed" <<'\n';
        }
    }

    for (int i = 0; i < 5; i++)
    {
         if (arr3[i] != tmp3[i]) {
            std::cout << "test3_forward failed" <<'\n';
            break;
        } else if (i == 4) {
            std::cout << "test3_forward passed" <<'\n';
        }
    }
}

void backward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    if (begin_idx != end_idx)
    {
        for (int i = begin_idx; i > end_idx; i--) {
            if (arr[i-1] > arr[i]) std::swap(arr[i], arr[i-1]);
        } 
    } 
}

void test_backward() {
    unsigned test_arr1[1] = {10};
    unsigned arr2[3] = {1, 2, 3};
    unsigned arr3[5] = {5, 4, 3, 2, 1};
    unsigned tmp1[1] = {10};
    unsigned tmp2[3] = {1, 2, 3};
    unsigned tmp3[5] = {1, 5, 4, 3, 2};
    backward_step(test_arr1, 0, 0);
    backward_step(arr2, 2, 0);
    backward_step(arr3, 4, 0);
    for (int i = 0; i < 1; i++)
    {
        if (test_arr1[i] != tmp1[i]) {
            std::cout << "test1_backward failed" <<'\n';
            break;
        } else if (i == 0) {
            std::cout << "test1_backward passed" <<'\n';
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (arr2[i] != tmp2[i]) {
            std::cout << "test2_backward failed" <<'\n';
            break;
        } else if (i == 2) {
            std::cout << "test2_backward passed" <<'\n';
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr3[i] != tmp3[i]) {
            std::cout << "test3_backward failed" <<'\n';
            break;
        } else if (i == 4) {
            std::cout << "test3_backward passed" <<'\n';
        }
    }
}


void shaker_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (int i = 0; i <= (end_idx - begin_idx) / 2; i++) {
        forward_step(arr, begin_idx, end_idx);
        if (end_idx != 0) {
            backward_step(arr, end_idx-1, begin_idx);
        }
    } 
}


void test_shaker() {
    unsigned test_arr1[1] = {2};
    unsigned arr2[3] = {1, 2, 3};
    unsigned arr3[5] = {5, 4, 3, 2, 1};
    unsigned tmp1[1] = {2};
    unsigned tmp2[3] = {1, 2, 3};
    unsigned tmp3[5] = {1, 2, 3, 4, 5};
    shaker_sort(test_arr1, 0, 1);
    shaker_sort(arr2, 0, 3);
    shaker_sort(arr3, 0, 5);
    for (int i = 0; i < 1; i++)
    {
        if (test_arr1[i] != tmp1[i]) {
            std::cout << "test1_shaker failed" <<'\n';
            break;
        } else if (i == 0) {
            std::cout << "test1_shaker passed" <<'\n';
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (arr2[i] != tmp2[i]) {
            std::cout << "test2_shaker failed" <<'\n';
            break;
        } else if (i == 2) {
            std::cout << "test2_shaker passed" <<'\n';
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr3[i] != tmp3[i]) {
            std::cout << "test3_shaker failed" <<'\n';
            break;
        } else if (i == 4) {
            std::cout << "test3_shaker passed" <<'\n';
        }
    }
}


int main() {
    test_backward();
    test_forward();
    test_shaker();
}