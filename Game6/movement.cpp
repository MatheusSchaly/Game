#include <iostream>
#include <algorithm>

#include "movement.h"

// Checks character's direction:

std::string checkDirection () {

    std::string direction;

    do {
        std::cout << "\nWhich direction do you want to move? (up / down / left / right)\n";
        std::cin >> direction;
        std::transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
    } while (direction != "up" && direction != "down" && direction != "left" & direction != "right");

    return direction;

}