#include <cstring>

char *resize(const char *buf, size_t size, size_t new_size)
{
    char *ptr = new char[new_size];
    if (new_size > size) {
        for(int i=0; i < size; ++i){
        ptr[i] = buf[i];
            
        }
        }
        else { 
            for(int i = 0 ; i < new_size; ++i) { ptr[i]=buf[i];}
            }
    return ptr;
    }
    

int main() {
    char *a = new char[10];
    resize(a, 4, 5);
    delete[] a;
}