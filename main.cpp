#include <iostream>
#include <vector>
#include "GameEngine.h"
using namespace std;
int main() {
    vector<string> map{
        "##########",
        "####.....#",
        "###......#",
        "##########",
        "#........#",
        "#........#",
        "#........#",
        "#........#",
        "#........#",
        "##########",
    };
    // Add vector switch door
    vector<string> switchDoor{
        "4 6 D 2 9 S"
    };

    vector<string> specialTiles{
        "Character @ 5 5 ConsoleController 9 9",
        "Character % 2 3 StationaryController 3 4",
        "Greatsword 1 4",
        "Door 13 9 Lever 11 9",
        "Trap 10 9"
    };

    GameEngine ge(10,10,1,map, switchDoor);
    ge.run();
    return 0;
}
