#pragma once

#include "header.h"

extern int frameSizeX ; // Frame size along X axis of the main window
extern int frameSizeY ; // Frame size along Y axis of the main window
extern const float recSize; // Size of each rectangle
extern size_t rowSize; // No of rectangles in each row
extern size_t columnSize; // No of rectangles in each column
extern float noOfOne; // No of 1s in each row of random generated grid
extern std::vector<std::pair<int,int>> result; // vector to store shortest path
extern std::vector<std::pair<int,int>> temp; // vector to store current path
extern std::vector<std::vector<bool>> visitedArray; // visitedArray used to trace visited nodes
extern std::vector<std::vector<sf::RectangleShape>> recArr; // Array in which all the rectangle objects are saved
extern sf::RenderWindow window; // Main window which will display all objects

extern sf::Color backGroundColor ;
extern sf::Color movableCellColor ;
extern sf::Color nonMovableCellColor ;
extern sf::Color startCellColor ;
extern sf::Color endCellColor ;
extern sf::Color traversingCellColor;

void fillVisitedArray();
void solveBFS(const std::vector<std::vector<bool>>& vec,const int startX,const int startY,const int endX ,const int endY);
void delaySmall();
void delayLarge();
void fillVisitedArray();
void drawRec();
void solve(const std::vector<std::vector<bool>>& vec,int startX,int startY,int endX ,int endY);
bool isValidIndex(const int x,const int y);
bool isValidIndexToVisit(const std::vector<std::vector<bool>>& vec,const int startX,const int startY);
void printVec(const std::vector<std::vector<int>>& vec);
std::vector<int> randomGen(const int min, const int max,const int noOfElements);
void generateRandomGrid(std::vector<std::vector<bool>>& vec);
void setRecColor(const std::vector<std::vector<bool>>& vec);
void createRectangles();
void setRectanglePosition(std::vector<std::vector<sf::RectangleShape>>& recArr);
std::vector<int> genStartandEnd(const std::vector<std::vector<bool>>& vec);
void colorResultCells(std::vector<std::vector<sf::RectangleShape>>& recArr);
void decolorResultCells();
void updateRowAndColumnSize(float x,float y);
void colorSearchCells(const std::vector<int>& search);
void decolorSearchCells(const std::vector<int>& search);

