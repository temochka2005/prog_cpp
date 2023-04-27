#include <iostream>


void Navar_limited(int length, int price[], int counter_rods[]){
    for (int i = 0; i < 10; i++)
    {   
        while (length - 10 + i >= 0)
        {
            switch (i){
                case 0: counter_rods[9]++;                    break;
                case 1: counter_rods[5]++; counter_rods[2]++; break;
                case 2: counter_rods[5]++; counter_rods[1]++; break;
                case 3: counter_rods[5]++; counter_rods[0]++; break;
                case 4: counter_rods[5]++;                    break;
                case 5: counter_rods[1]++; counter_rods[2]++; break;
                case 6: counter_rods[1]+=2;                   break;
                case 7: counter_rods[2]++;                    break;
                case 8: counter_rods[1]++;                    break;
                case 9: counter_rods[0]++;                    break;
            }
            length = length - 10 + i;
        }
    }

    for(int j= 0; j < 10; j++){ 
         while(counter_rods[j]>0){
            std::cout << j+1 << " ";
            counter_rods[j]--;
        }
    }

}


int main()
{
    int length = 0;
    std::cin >> length;
    int price[10]{30, 25, 22, 18, 17, 13, 10, 8, 5, 1};
    int counter_rods[10]={0};
    Navar_limited(length, price, counter_rods);
    return 0;

}