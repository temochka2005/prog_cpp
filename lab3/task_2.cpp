#include <fstream>
#include <random>
const int crystal_size = 100;
const int disloc_count_max = crystal_size * crystal_size / 2;


using namespace std;

int unsigned seed = 1000-7;
default_random_engine rng(seed);
uniform_int_distribution<unsigned> dstr(1, crystal_size);
uniform_int_distribution<unsigned> dir(1, 5);


struct Dislocasions
{
    int x,y, dx = 0, dy = 0;
    bool stop = false;
};


int main()
{
    std::ofstream f("F:/progaCPP/lab3/ex2.txt", std::ios::out);
    for(float disloc_count = disloc_count_max; disloc_count>0;disloc_count-=100){
        Dislocasions* dis = new Dislocasions[disloc_count_max];

        for (int k = 0;k < disloc_count; ++k) 
        { 
            dis[k].x = dstr(rng);
            dis[k].y = dstr(rng);
        }
        bool all_stop = false;  
        int counter = 0; 

        while (!all_stop) 
        { 
            all_stop = true; 
            for (int i = 0; i < disloc_count; ++i) 
            {
        
                if (!dis[i].stop){
                    int direction = dir(rng), dx = 0, dy = 0;
                    if (direction == 1) dis[i].dx = -1;
                    if (direction == 2) dis[i].dx = 1;
                    if (direction == 3) dis[i].dy = 1;
                    if (direction == 4) dis[i].dy = -1;

                    if (dis[i].x < 1 or dis[i].x >= crystal_size - 1 or dis[i].y < 1 or dis[i].y >= crystal_size - 1)  
                    {
                        dis[i].dx=0;
                        dis[i].dy=0;
                        dis[i].stop = true;
                    }
                    else all_stop = false;
                }
            } 
            for (int i = 0; i < disloc_count; i++){
                bool cross = false;
                for (int j = 0; j < disloc_count; j++)
                {
                    if(j!=i && !dis[i].stop)
                    {
                        if((dis[i].x+dis[i].dx==dis[j].x+dis[j].dx
                            && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy)
                         ||(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx 
                            && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy-1)
                         ||(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx 
                            && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy+1)
                         ||(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx+1
                            && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy)
                         ||(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx-1
                            && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy))
                            dis[i].stop=true;
                        if(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy)
                           cross = true;
                    }
                }
                if(!cross){
                    dis[i].x+=dis[i].dx;
                    dis[i].y+=dis[i].dy;
                }
                dis[i].dx=0;
                dis[i].dy=0;
            
            }
            counter++;
        }
        float q = disloc_count / (crystal_size * crystal_size);
        f<< q <<' '<< counter <<endl;
    delete dis;
    }

    
}

