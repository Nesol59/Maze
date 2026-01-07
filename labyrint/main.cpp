#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "generation_of_maze_HEAD.h"
#include "input_output_HEAD.h"
#include "wave_algorithm_HEAD.h"
#include "text_for_user_HEAD.h"
#include <iomanip>
#include <fstream>
const int full_screen = 237;
int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int size_of_maze=0;
  FirstStep();
  std::cout << "\n\n";
  int user;
  while (true) {
    std::cout << "    Выберите опцию от 1 до 2: ";
    if (!CheckIsNumber(user, 1, 2)) {
      SetColor(4);
      std::cout << "    Некорретный ввод!\n\n";
      ResetColor();
      continue;
    } 
    break;
    std::cout << "\n\n";
  }
  system("cls");
  std::vector<std::vector<char>> maze;
  switch (user) {
    case 1: {
      SetColor(10);
      std::cout << std::string(full_screen, '=') << "\n\n"
                << std::right << std::setw(130);
      ResetColor();
      std::cout << "Для генерации лабиринта  " << "\n\n\n";
      SetColor(10);
      std::cout << std::string(full_screen, '=');
      SetColor(9);
      std::cout << "\n\n";
      while (true) {
        ResetColor();
        std::cout << "    Введите размер лабиринта (он должен быть нечетным от 5 до 25 ): ";
        if (!CheckIsNumber(size_of_maze, 5, 25) || size_of_maze%2==0) {
          SetColor(4);
          std::cout << "    Некорретный ввод!\n\n";
          ResetColor();
          continue;
        }
        break;
        std::cout << "\n\n";
      }
      maze.resize(size_of_maze, std::vector<char>(size_of_maze));
      GenerateMaze(maze, size_of_maze);
      break;
    }
    case 2: {
      InputFile(maze, size_of_maze);
      if (!size_of_maze) {
        SetColor(4);
        std::cout << "  Завершение работы программы из-за некорректного "
                     "лабиринта в файле//\n\n";
        ResetColor();
        return -1;
      }
      break;
    }
    default: {
      SetColor(4);
      std::cout << "  Такой опции не обнаружено, возврат к выбору задачи ///\n\n";
      ResetColor();
    }
  }
  bool flag = 1;
  while (flag) {
    SecondStep();
    std::cout << "\n\n";
    while (true) {
      std::cout << "    Выберите опцию от 1 до 3: ";
      if (!CheckIsNumber(user, 1, 3)) {
        SetColor(4);
        std::cout << "    Некорретный ввод!\n\n";
        ResetColor();
        continue;
      }
      break;
      std::cout << "\n\n";
    }
    switch (user) {
      case 1: {
        ShowMaze(maze, maze.size());
        break;
      }
      case 2: {
        OutputMaze(maze, size_of_maze);
        break;
      }
      case 3: {
        flag = 0;
        break;
      }
      default: {
        SetColor(4);
        std::cout
            << "    Такой опции не обнаружено, возврат к выбору задачи ///\n\n";
        ResetColor();
      }
      
    }
  }
  flag = 1;
  while (flag) {

    ThirdStep();
    std::cout << "\n\n";
    while (true) {
      std::cout << "    Выберите опцию от 1 до 5: ";
      if (!CheckIsNumber(user, 1, 5)) {
        SetColor(4);
        std::cout << "    Некорретный ввод!\n\n";
        ResetColor();
        continue;
      }
      break;
      std::cout << "\n\n";
    }
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
        int clean;
        SetColor(10);
        std::cout << std::string(full_screen, '=') << "\n\n\n"
                  << std::string(100, ' ');
        ResetColor();

        std::cout << "  Очистить файл?" << "\n\n\n";
        SetColor(10);
        std::cout << std::string(full_screen, '=');
        SetColor(9);
        
        
        while (true) {
          
          std::cout << "\n\n    1.Да\n\n    2.Нет\n\n";
          ResetColor();
          std::cout << "    Выберите опцию от 1 до 2: ";

          if (!CheckIsNumber(clean, 1, 2)) {
            SetColor(4);
            std::cout << "    Некорретный ввод!\n\n";
            ResetColor();
            continue;
          }
          break;
          std::cout << "\n\n";
        }
        if (clean == 1) {
          std::fstream("output_wave.txt", std::fstream::out);
        }
        WaveAlgorithm(maze, maze.size(), 3);
        break;
      }
      case 4: {
        WaveAlgorithm(maze, maze.size(), 4);
        break;
      }
      case 5: {
        flag = 0;
        break;
      }
      default: {
        SetColor(4);
        std::cout
            << "    Такой опции не обнаружено, возврат к выбору задачи ///\n\n";
        ResetColor();
      }
    }
  }
}