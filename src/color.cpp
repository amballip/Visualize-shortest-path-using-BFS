#include "functions.h"


// sets the color of the maze based on the random vector generated
void setRecColor(const std::vector<std::vector<bool>>& vec)
{
    for(size_t i = 0;i<rowSize;++i)
    {
        for(size_t j = 0;j<columnSize;++j)
        {
            if(vec[i][j]==true)
                recArr[i][j].setFillColor(movableCellColor);
            else if(vec[i][j]==false)
                recArr[i][j].setFillColor(nonMovableCellColor);
        }
    }

}

// Sets vertices in the result to 4
void colorResultCells(std::vector<std::vector<sf::RectangleShape>>& recArr)
{
    if(result.empty())
    {
        std::cout<<"No fesible results"<<std::endl;
    }
    else if(result.size()==1)
    {
        std::cout<<"Nodes are adjacent"<<std::endl;
    }
    else
    {
        std::cout<<"success"<<std::endl;
        for(size_t i = 1;i<result.size()-1;++i)
        {
            delayLarge();
            window.clear(backGroundColor);
            recArr[result[i].second][result[i].first].setFillColor(sf::Color::Magenta);
            drawRec();
            window.display();
        }
    }

}

void decolorResultCells()
{
    for(size_t i = 1;i<result.size();++i)
    {
        recArr[result[i].second][result[i].first].setFillColor(movableCellColor);
    }

}

// colors the search cells using search vector
void colorSearchCells(const std::vector<int>& search)
{
    recArr[search[1]][search[0]].setFillColor(startCellColor);
    recArr[search[3]][search[2]].setFillColor(endCellColor);
}

void decolorSearchCells(const std::vector<int>& search)
{
    recArr[search[1]][search[0]].setFillColor(movableCellColor);
    recArr[search[3]][search[2]].setFillColor(movableCellColor);
}

