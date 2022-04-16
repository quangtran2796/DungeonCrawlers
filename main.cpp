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

    vector<string> switchDoor{
        "4 6 D 2 9 S"
    };

    GameEngine ge(10,10,1,map, switchDoor);
    ge.run();
    return 0;
}
