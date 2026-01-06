#include <iostream>
#include <Windows.h>
#include <vector>
#include "generation_of_maze_HEAD.h"
#include "input_output_HEAD.h"
int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int size_of_maze;

  std::cout << "Введите размер лабиринта: ";
  std::cin >> size_of_maze;
  std::cout << "\n\n";
  std::vector<std::vector<char>> maze(size_of_maze,
                                      std::vector<char>(size_of_maze));
  GenerateMaze(maze, size_of_maze);
  ShowMaze(maze, size_of_maze);

}