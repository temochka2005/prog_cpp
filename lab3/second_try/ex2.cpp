#include <fstream>
#include <random>
#include <iostream>

const int crystal_size = 1000;
const int disloc_count_max = crystal_size * crystal_size / 2;


int unsigned seed = 1000-7;
std::default_random_engine rng(seed);
std::uniform_int_distribution<unsigned> dstr(1, crystal_size);
std::uniform_int_distribution<unsigned> dir(1, 5);


struct Dislocasions{
    int x =0,y=0, dx = 0, dy = 0;
    bool stop = false;
};


void randDirection(Dislocasions* dis, int disloc_count)
{
    for (int i = 0; i < disloc_count; i++)
    {
        int direction = dir(rng);
        if (direction == 1) dis[i].dx = -1;
        if (direction == 2) dis[i].dx = 1;
        if (direction == 3) dis[i].dy = 1;
        if (direction == 4) dis[i].dy = -1;
        
    }
}


void randPosition(Dislocasions* dis, int disloc_count)
{
    for (int i = 0; i < disloc_count; i++){
        dis[i].x = dstr(rng);
        dis[i].y = dstr(rng);
    }
}


void Move(Dislocasions* dis, int disloc_count){
    for (int i = 0; i < disloc_count; i++){
        if(!dis[i].stop){
            dis[i].x+=dis[i].dx;
            dis[i].y+=dis[i].dy;
            dis[i].dx = 0;
            dis[i].dy = 0;
        }
    }
}


void checker(Dislocasions* dis, int disloc_count, bool &finished){
    int stopped_counter = 0;
    for (int i = 0; i < disloc_count; i++){
       if(     dis[i].x == 0 or ( dis[i].x == crystal_size - 1 )
           or  dis[i].y == 0 or ( dis[i].y == crystal_size - 1 )
         )  
        {  
            dis[i].stop = true;
            stopped_counter++;
        }
    }
    if (stopped_counter == disloc_count) finished = true;
}


void Step(Dislocasions* dis, int disloc_count, int &counter, bool &finished)
{
    checker(dis, disloc_count, finished);
    if(finished) return;
    randDirection(dis, disloc_count);
    Move(dis, disloc_count);
    checker(dis, disloc_count, finished);
    if(finished) return;
    counter++;
}

int main()
{
    std::ofstream f("F:/progaCPP/lab3/second_try/ex2reworked.txt", std::ios::out);
    // int disloc_count = disloc_count_max;
    int disloc_count = 2;

    while (disloc_count > 0)
    {
        Dislocasions* dis = new Dislocasions[disloc_count];
        int counter = 0;
        for (int i = 0; i < 2   ; ++i)
        {
            randPosition(dis, disloc_count);
            bool finished = false;
            std::cout << "rand position OK" << std::endl;
            while (!finished)
            {
                Step(dis, disloc_count, counter, finished);
            }
            std::cout << "Out of while {Step} OK " << std::endl;
        }
        f<< counter <<  " " << static_cast<float>(disloc_count)  << std::endl;
        std::cout << "printed txt" << std::endl;
        disloc_count--;
        delete dis;
    }
    std::cout << "Out of while discloc_count" << disloc_count << std::endl;
    return 0;
}