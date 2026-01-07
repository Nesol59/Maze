#include <iostream>
#include <Windows.h>
#include <vector>
#include "generation_of_maze_HEAD.h"
#include "input_output_HEAD.h"
#include "wave_algorithm_HEAD.h"
#include "text_for_user_HEAD.h"
int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int size_of_maze;
  FirstStep();
  std::cout << "\n\n";
  int user;
  std::cout << "Выберите опцию от 1 до 2: ";
  std::cin >> user;
  std::cout << "\n\n";
  system("cls");
  std::vector<std::vector<char>> maze;
  switch (user) {
    case 1: {
      std::cout << "Введите размер лабиринта (от 5 до 111 ): ";
      std::cin >> size_of_maze;
      std::cout << "\n\n";
      maze.resize(size_of_maze, std::vector<char>(size_of_maze));
      GenerateMaze(maze, size_of_maze);
      break;
    }
    case 2: {
      break;
    }
    default: {
      SetColor(4);
      std::cout << "Такой опции не обнаружено, возврат к выбору задачи ///\n\n";
      ResetColor();
    }
  }
  bool flag = 1;
  while (flag) {
    SecondStep();
    std::cout << "\n\n";
    std::cout << "Выберите опцию от 1 до 4: ";
    std::cin >> user;
    std::cout << "\n\n";
    system("cls");
    switch (user) {
      case 1: {
        ShowMaze(maze, maze.size());
        break;
      }
      case 2: {
        // make
        break;
      }
      case 3: {
        flag = 0;
        break;
      }
      default: {
        SetColor(4);
        std::cout
            << "Такой опции не обнаружено, возврат к выбору задачи ///\n\n";
        ResetColor();
      }
      
    }
  }
  flag = 1;
  while (flag) {

    ThirdStep();
    std::cout << "\n\n";
    std::cout << "Выберите опцию от 1 до 5: ";
    std::cin >> user;
    std::cout << "\n\n";
    switch (user) {
     
      case 1: {
        WaveAlgorithm(maze, maze.size(), 1);
        break;
      }
      case 2: {
        WaveAlgorithm(maze, maze.size(), 2);
        break;
      }
      case 3: {
        // make
        break;
      }
      case 4: {
        break;
      }
      case 5: {
        flag = 0;
        break;
      }
      default: {
        SetColor(4);
        std::cout
            << "Такой опции не обнаружено, возврат к выбору задачи ///\n\n";
        ResetColor();
      }
    }
  }
}