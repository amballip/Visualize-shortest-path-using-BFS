#include "functions.h"


//generates noOfElements(this will be size of return vector) random numbers in range [min,max]
std::vector<int> randomGen(const int min, const int max,const int noOfElements)
{
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution dist(min,max);
    std::vector<int> vec;
    vec.reserve(noOfElements);

    for(int i = 0;i<noOfElements;++i)
    {
        vec.push_back(dist(gen));
    }

    return vec;
}



// generates random numbers and fills the vector
void generateRandomGrid(std::vector<std::vector<bool>>& vec)
{
    for(size_t i = 0;i<rowSize;++i)
    {
        std::vector<int> randVec = randomGen(1,100,1);
        std::vector<bool> temp;

        for(size_t j = 0;j<columnSize;++j)
        {
            if(j<noOfOne*columnSize)
                temp.push_back(true);
            if(j<columnSize-noOfOne*columnSize)
                temp.push_back(false);
        }

        std::shuffle(temp.begin(),temp.end(),std::default_random_engine(randVec.front()));
        vec.push_back(temp);
    }
}


// generates distint start and end vertices
std::vector<int> genStartandEnd(const std::vector<std::vector<bool>>& vec)
{

    std::vector<int> xCordinate = randomGen(0,columnSize-1,2);
    std::vector<int> yCordinate = randomGen(0,rowSize-1,2);

    while(true)
    {
        if(vec.at(yCordinate[0]).at(xCordinate[0]) && vec.at(yCordinate[1]).at(xCordinate[1]))
        {
            if(xCordinate[0]!=xCordinate[1])
                break;
            else
            {
                xCordinate = randomGen(0,columnSize-1,2);
                yCordinate = randomGen(0,rowSize-1,2);
            }
        }
        else
        {
            xCordinate = randomGen(0,columnSize-1,2);
            yCordinate = randomGen(0,rowSize-1,2);
        }
    }

    std::vector<int> cordinateVector = {xCordinate[0],yCordinate[0],xCordinate[1],yCordinate[1]};
    return cordinateVector;
}




