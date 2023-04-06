#include <fstream>
#include <random>

const int max_crystal_size = 5000;
const int disloc_count = 1;

int unsigned seed = 1000-7;
std::default_random_engine rng(seed);
std::uniform_int_distribution<unsigned> dstr(1, 5);

int main()
{
std::ofstream f("F:/progaCPP/lab3/ex1.txt", std::ios::out);
for (int crystal_size = 10; crystal_size<max_crystal_size; crystal_size*=2)
{
    int disloc_x = crystal_size/2, disloc_y = crystal_size/2;
    int count = 0;
    for (int i = 0; i<100; i++){
        while (disloc_x !=0 && disloc_x != crystal_size && disloc_y !=0 && disloc_y != crystal_size)
        {
            int direction = dstr(rng);
            if (direction == 1) disloc_x++;
            if (direction == 2) disloc_x--;
            if (direction == 3) disloc_y++;
            if (direction == 4) disloc_y--;
            count++;
        }
    }
    f<< crystal_size << ' ' << count << std::endl;
    }
}