#ifndef INPUT_OUTPUT_HEAD
#define INPUT_OUTPUT_HEAD
#include <vector>
#include <Windows.h>
void showMaze(std::vector<std::vector<char>> maze, int size_of_maze);
void setColor(int colorCode);
void resetColor();
void printColoredSymbol(char symbol);
void inputFile(std::vector<std::vector<char>>& maze, int & size_of_maze);
void outputWaveFile(std::vector<std::vector<int>> wave, int size_of_maze,
                int curret_step);
bool checkIsNumber(int& number, int min_eval, int max_eval);
void outputShortestWay(std::vector<std::vector<char>> maze, int size_of_maze);
void outputMaze(std::vector<std::vector<char>> maze, int size_of_maze);
const int kFullScreen = GetSystemMetrics(SM_CXSCREEN)/8.1;
const std::string kLineOfEval = std::string(kFullScreen, '=');
void outputWaveConsole(std::vector<std::vector<int>> wave, int size_of_maze,
                       int curret_step);
#endif
