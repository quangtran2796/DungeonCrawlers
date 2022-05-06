cmake_minimum_required(VERSION 3.21)
project(DungeonCrawlers)

set(CMAKE_CXX_STANDARD 14)

add_executable(DungeonCrawlers main.cpp Tile.cpp Tile.h DungeonMap.cpp DungeonMap.h Character.cpp Character.h GameEngine.cpp GameEngine.h Floor.cpp Floor.h Wall.cpp Wall.h Passive.h Active.h Switch.cpp Switch.h Door.cpp Door.h Controller.h ConsoleController.cpp ConsoleController.h Item.h Lever.cpp Lever.h Trap.cpp Trap.h StationaryController.h)
