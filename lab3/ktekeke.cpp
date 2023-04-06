#include <iostream>
#include <fstream>
#include <random> 

using namespace std;

const int disloc_count_max = 5000;
const int crystal_size = 100 ;

int unsigned seed = 1;
default_random_engine rng(seed);
uniform_int_distribution<unsigned> dstr(1, crystal_size);
uniform_int_distribution<unsigned> dir(0, 4);


struct Dislocasions
{
    int x,y,dx,dy;
    bool stop = false;
};


int main()
{
    ofstream f("F:/progaCPP/lab3/ex22.txt", ios::out);
    for(int disloc_count = disloc_count_max; disloc_count>0;disloc_count--){
        Dislocasions* dis = new Dislocasions[disloc_count_max];
        for (int k = 0;k < disloc_count; ++k) 
        { 
            dis[k].x = dstr(rng);
            dis[k].y = dstr(rng);
        }
        bool all_stop = false;
        int time = 0; 
        while (!all_stop) 
        { 
            all_stop = true; 
            for (int i = 0; i < disloc_count; ++i) 
            {
                
                if (!dis[i].stop){
                int p = dir(rng), dx = 0, dy = 0;
                
                switch (p) 
                {
                    case 0: dis[i].dx = -1;
                    case 1: dis[i].dx = 1; 
                    case 2: dis[i].dy = -1; 
                    case 3: dis[i].dy = 1; 
                }
                if (dis[i].x < 1 || dis[i].x >= crystal_size  -1 || dis[i].y < 1 || dis[i].y >= crystal_size-1)  
                {
                    dis[i].dx=0;
                    dis[i].dy=0;
                    dis[i].stop = true;
                }
                else{
                all_stop = false;
            }}}
            for (int i = 0; i < disloc_count; i++) 
            {
                bool cross = false;
                for (int j = 0; j < disloc_count; j++)
                {
                    if(j!=i && !dis[i].stop)
                    {
                        if((dis[i].x+dis[i].dx==dis[j].x+dis[j].dx && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy)||(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy-1)||(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy+1)||(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx+1 && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy)||(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx-1 && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy)){
                            dis[i].stop=true;
                        }
                        if(dis[i].x+dis[i].dx==dis[j].x+dis[j].dx && dis[i].y+dis[i].dy==dis[j].y+dis[j].dy){
                            cross = true;
                        }
                    }
                }
                if(!cross){
                    dis[i].x+=dis[i].dx;
                    dis[i].y+=dis[i].dy;
                }
                dis[i].dx=0;
                dis[i].dy=0;
            } 
            time++;
        }
        f<<time<<' '<<disloc_count<<endl;
    delete dis;
    }

    
}

