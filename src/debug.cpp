#include "functions.h"

// prints the 2d vector
void printVec(const std::vector<std::vector<int>>& vec)
{
    for(size_t i = 0;i<vec.size();++i)
    {
        for(size_t j = 0;j<vec[i].size();++j)
        {
            if(vec[i][j]>9 || vec[i][j]<0)
                std::cout<<vec[i][j]<<" ";
            else
                std::cout<<vec[i][j]<<"  ";

        }
        std::cout<<std::endl;

    }
}

