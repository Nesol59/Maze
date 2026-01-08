#ifndef INPUT_OUTPUT_HEAD
#define INPUT_OUTPUT_HEAD
#include <vector>
void ShowMaze(std::vector<std::vector<char>> maze, int size_of_maze);
void SetColor(int colorCode);
void ResetColor();
void PrintColoredSymbol(char symbol);
void InputFile(std::vector<std::vector<char>>& maze, int & size_of_maze);
void OutputWaveFile(std::vector<std::vector<int>> wave, int size_of_maze,
                int curret_step);
bool CheckIsNumber(int& number, int min_eval, int max_eval);
void OutputShortestWay(std::vector<std::vector<char>> maze, int size_of_maze);
void OutputMaze(std::vector<std::vector<char>> maze, int size_of_maze);
const int full_screen = 237;
void OutputWaveConsole(std::vector<std::vector<int>> wave, int size_of_maze,
                       int curret_step);
#endif
