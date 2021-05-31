#include "functions.h"
#include <SFML/System/Clock.hpp>

// to intruduce delay for graphics
void delay(int milliSeconds)
{
    sf::Clock clock;
    clock.restart();
    while(clock.getElapsedTime().asMilliseconds()<milliSeconds)
    {
    }
    clock.restart();
}


