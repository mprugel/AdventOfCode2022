#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>
#include <exception>
#include <vector>

struct sElve
{
    uint32_t u32pos = 0U;
    uint32_t u32Sum = 0U;
};

int main(int argc, char** args)
{
    std::ifstream inputStream(args[1]);
    std::string sline;
    uint32_t u32number;
    sElve sMaxElve;
    uint32_t u32i = 0U;
    uint32_t u32currentSum = 0U;

    while(std::getline(inputStream, sline))
    {
        if(sline.size() == 0)
        {
            if(u32currentSum > sMaxElve.u32Sum)
            {
                sMaxElve.u32Sum = u32currentSum;
                sMaxElve.u32pos = u32i;
            }
            u32i++;
            u32currentSum = 0U;
        }
        else
        {
            u32number = std::stoi(std::string(sline));
            u32currentSum += u32number;
        }
        
    }
    std::cout << "Max Elve: " << (sMaxElve.u32Sum) << std::endl;

    return 0;
}