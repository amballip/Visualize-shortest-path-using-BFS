#include "header.h"
#include "functions.h"

int frameSizeX = 800; // Frame size along X axis of the main window
int frameSizeY = 600; // Frame size along Y axis of the main window
const float recSize =25.0f; // Size of each rectangle
size_t rowSize; // No of rectangles in each row
size_t columnSize; // No of rectangles in each column
float noOfOne = 0.9f ; // No of 1s in each row of random generated grid
std::vector<std::pair<int,int>> result; // vector to store shortest path
std::vector<std::pair<int,int>> temp; // vector to store current path
std::vector<std::vector<bool>> visitedArray; // visitedArray used to trace visited nodes
std::vector<std::vector<sf::RectangleShape>> recArr; // Array in which all the rectangle objects are saved
sf::RenderWindow window; // Main window which will display all objects

sf::Color backGroundColor = sf::Color::White;
sf::Color movableCellColor = sf::Color::White;
sf::Color nonMovableCellColor = sf::Color(147,23,255);
sf::Color startCellColor = sf::Color::Red;
sf::Color endCellColor = sf::Color::Green;
sf::Color traversingCellColor = sf::Color::Yellow;

int main()
{
    updateRowAndColumnSize(frameSizeX,frameSizeY);

    createRectangles();
    setRectanglePosition(recArr);

    std::vector<std::vector<bool>> vec;

    std::vector<int> search;

    window.create(sf::VideoMode(frameSizeX,frameSizeY), "Maze search",sf::Style::Default);

    bool isMazeGenerated = false;
    bool isSearchGenerated = false;

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch(event.type)
            {

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.code==sf::Keyboard::A)
                    {
                        isMazeGenerated = false;
                        isSearchGenerated = false;
                        window.clear(backGroundColor);
                        vec.clear();
                        generateRandomGrid(vec); 
                        setRecColor(vec);
                        isMazeGenerated = true;
                    }
                    else if(event.key.code==sf::Keyboard::S)
                    {
                        if(isMazeGenerated)
                        {
                            if(!search.empty())
                            {
                                decolorSearchCells(search);
                            }
                            if(result.size()>1)
                            {
                                decolorResultCells();
                            }
                            search.clear();
                            window.clear(backGroundColor);
                            search = genStartandEnd(vec);
                            setRecColor(vec);
                            colorSearchCells(search);
                            isSearchGenerated = true;
                        }
                        else
                            std::cout<<"Maze not generated. Press a to generate maze"<<std::endl;
                    }
                    else if(event.key.code==sf::Keyboard::D)
                    {
                        if(isMazeGenerated && isSearchGenerated)
                        {
                            window.clear(backGroundColor);
                            setRecColor(vec);
                            colorSearchCells(search);
                            result.clear();
                            visitedArray.clear();
                            fillVisitedArray();
                            solveBFS(vec,search[0],search[1],search[2],search[3]);
                            colorResultCells(recArr);
                        }
                        else
                        {
                            std::cout<<"Maze or search not generated"<<std::endl;
                        }
                    }
                    break;

              case sf::Event::Resized:
                    isMazeGenerated = false;
                    isSearchGenerated = false;
                    frameSizeX = event.size.width;
                    frameSizeY = event.size.height;
                    updateRowAndColumnSize(frameSizeX,frameSizeY);
                    window.clear(backGroundColor);
                    recArr.clear();
                    createRectangles();
                    setRectanglePosition(recArr);
                    window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                    break;

              default:
                    break;

            }
        }

        window.clear(backGroundColor);
        drawRec();
        window.display();
    }

    return 0;
}

