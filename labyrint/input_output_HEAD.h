#ifndef INPUT_OUTPUT_HEAD
#define INPUT_OUTPUT_HEAD
#include <vector>
void ShowMaze(std::vector<std::vector<char>> maze, int size_of_maze);
void SetColor(int colorCode);
void ResetColor();
void PrintColoredSymbol(char symbol);

#endif
