#include "functions.h"

// recursive function based on DFS - which actually finds the solution
void solve(const std::vector<std::vector<bool>>& vec,int startX,int startY,int endX ,int endY)
{ 
    if(startX<0 || startX>(int)rowSize-1 || startY<0 || startY>(int)columnSize-1)
    {
        return;
    }
    else if(vec[startX][startY]==false)
    {
        return;
    }
    else if(startX==endX && startY==endY)
    {
        if(result.size()==0)
        {
            result = temp;
        }
        else if(temp.size()<result.size())
        {
            result=temp;
        }
    }
    else if(result.size()>0 && temp.size()>result.size())
    {
        return;
    }
    else if(visitedArray[startX][startY]==true)
    {
        return;
    }
    else
    {
        temp.push_back(std::make_pair<>(startX,startY));
        visitedArray[startX][startY]=true;
        solve(vec,startX+1,startY,endX,endY);
        solve(vec,startX-1,startY,endX,endY);
        solve(vec,startX,startY+1,endX,endY);
        solve(vec,startX,startY-1,endX,endY);
        temp.pop_back();
        visitedArray[startX][startY]=false;
    }
}


