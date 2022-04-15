//
// Created by Tran on 4/15/2022.
//

#include "ConsoleController.h"
#include <iostream>
int ConsoleController::move() {
    char direction;
    std::cout << "Type console controller's next move direction 1-9:";
    std::cin >> direction;
    return direction - '0';
}
