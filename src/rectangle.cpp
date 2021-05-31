#include "functions.h"

// Creates rectangles based on no of 
void createRectangles()
{ 
    for(size_t i = 0;i<rowSize;++i)
    {
        std::vector<sf::RectangleShape> temp;

        for(size_t j = 0;j<columnSize;++j)
        {
            temp.push_back(sf::RectangleShape());
        }
        recArr.push_back(temp);
    }
}

// Sets the rectangle position
void setRectanglePosition(std::vector<std::vector<sf::RectangleShape>>& recArr)
{
    for(size_t i = 0;i<rowSize;++i)
    {
        for(size_t j = 0;j<columnSize;++j)
        {
            recArr[i][j].setSize(sf::Vector2(recSize,recSize));
            recArr[i][j].setPosition((j*recSize)+50,(i*recSize)+50);
            recArr[i][j].setOutlineThickness(1.0f);
            recArr[i][j].setOutlineColor(sf::Color::Black);
        }
    }
}


// updates row and column size by using FrameX and FrameY
void updateRowAndColumnSize(float x,float y)
{
    rowSize = (y-100)/recSize;
    columnSize = (x-100)/recSize;


}

// to check if a index is a valid index to visit
bool isValidIndexToVisit(const std::vector<std::vector<bool>>& vec,const int startX,const int startY)
{
    if(isValidIndex(startX,startY))
    {
        if(vec[startY][startX]==true)
        {
            if(visitedArray[startY][startX]==false)
                return true;
        }
    }
    return false;
}

// fill the visited array with all false
void fillVisitedArray()
{
    for(size_t i = 0;i<rowSize;++i)
    {
        std::vector<bool> visitedTemp;
        for(size_t j = 0;j<columnSize;++j)
        {
            visitedTemp.push_back(false);
        }
        visitedArray.push_back(visitedTemp);
    }
}

// draws all the rectanges on the background buffer
void drawRec()
{
    for(size_t i = 0;i<rowSize;++i)
    {
        for(size_t j = 0;j<columnSize;++j)
        {
            window.draw(recArr[i][j]);
        }
    }
}

// to check if a given index is a valid index
bool isValidIndex(const int x,const int y)
{
    if(x<0 || x>int(columnSize)-1 || y<0 || y>int(rowSize)-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}



