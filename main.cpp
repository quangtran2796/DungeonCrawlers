#include <iostream>
#include <vector>
#include "GameEngine.h"
using namespace std;
int main() {
    vector<string> data{
        "##########",
        "####.....#",
        "###......#",
        "##.......#",
        "#........#",
        "#........#",
        "#........#",
        "#........#",
        "#........#",
        "##########",
    };

    GameEngine ge(10,10,data);
    ge.run();
    return 0;
}
