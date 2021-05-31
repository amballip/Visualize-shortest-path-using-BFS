#include "header.h"
#include "functions.h"

void solveBFS(const std::vector<std::vector<bool>>& vec,const int startX,const int startY,const int endX ,const int endY)
{
    result.clear();
    int x = startX;
    int y = startY;

    visitedArray.clear();
    fillVisitedArray();

    std::vector<std::vector<int>> distance;

    for(size_t i = 0;i<rowSize;++i)
    {
        std::vector<int> temp;
        for(size_t j = 0;j<columnSize;++j)
        {
            temp.push_back(-10);
        }
        distance.push_back(temp);
    }

    std::queue<std::pair<int,int>> q;

    q.push(std::make_pair<>(x,y));
    visitedArray[y][x]=true;
    distance[y][x]=0;

    std::vector<std::pair<int,int>> calVec={{1,0},{-1,0},{0,1},{0,-1}};

    bool found = false;

    while(true)
    {
        if(x==endX && y == endY)
        {
            found = true;
            break;
        }

        if(q.empty()) { break; }

        for(size_t i = 0;i<calVec.size();++i)
        {
            if(isValidIndexToVisit(vec,x+calVec[i].first,y+calVec[i].second))
            {
                if(x+calVec[i].first==endX && y+calVec[i].second == endY)
                {
                    distance[y+calVec[i].second][x+calVec[i].first] = distance[y][x]+1;
                    visitedArray[y+calVec[i].second][x+calVec[i].first]=true;
                    found = true;
                    goto start;
                }
                else
                {
                    q.push(std::make_pair<>(x+calVec[i].first,y+calVec[i].second));
                    distance[y+calVec[i].second][x+calVec[i].first] = distance[y][x]+1;
                    visitedArray[y+calVec[i].second][x+calVec[i].first]=true;
                    {
                        delay(10);
                        recArr[y+calVec[i].second][x+calVec[i].first].setFillColor(traversingCellColor);
                        window.clear(backGroundColor);
                        drawRec();
                        window.display();
                    }
                }
            }
        }

        q.pop();
        x = q.front().first;
        y = q.front().second;
    }

    start:
    std::vector<std::pair<int,int>> path;

    if(found)
    {
        x = endX;
        y = endY;
        while(!(x == startX && y==startY))
        {
            path.push_back(std::make_pair<>(x,y));
            for(size_t i = 0;i<calVec.size();++i)
            {
                if(isValidIndex(x+calVec[i].first,y+calVec[i].second))
                {
                    if(distance[y][x] - distance[y+calVec[i].second][x+calVec[i].first] == 1)
                    {
                        x = x+calVec[i].first;
                        y = y+calVec[i].second;
                        break;
                    }
                }
            }
        }
        path.push_back(std::make_pair<>(x,y));

        std::reverse(path.begin(),path.end());

        result = path;
    }

}


