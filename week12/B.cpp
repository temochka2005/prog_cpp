#include <iostream>


int Navar_limited(int length, int price[]){
    int pr = 0;
   
    for (int i = 0; i < 10; i++)
    {
        while (length - 10 + i >= 0)
        {
            pr = pr + price[i];
            length = length - 10 + i;
        }
    }
    return pr;
}


int main()
{
    int length = 0;
    std::cin >> length;
    int price[10]{30, 25, 22, 18, 17, 13, 10, 8, 5, 1};
    std::cout << Navar_limited(length, price) << std::endl;
    return 0;
}