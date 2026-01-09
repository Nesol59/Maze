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
#include <thread>

int main() {

  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int size_of_maze=0;
  
  int user;
  std::vector<std::vector<char>> maze;
  bool flag = 1;
  bool is_user_made_maze = 0;
  while (flag) {
    while (true) {
      FirstStep();
      std::cout << "\n\n";
      std::cout << "    Выберите опцию от 1 до 5: ";
      if (!CheckIsNumber(user, 1, 6)) {
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
        
        size_of_maze = 0;
        maze.resize(0, std::vector<char>(0));
        SetColor(10);
        std::cout << kLineOfEval << "\n\n\n" <<
            std::string(100, ' ');
        ResetColor();
        std::cout << "Для генерации лабиринта  " << "\n\n\n";
        SetColor(10);
        std::cout << kLineOfEval;
        SetColor(9);
        std::cout << "\n\n";
        while (true) {
          ResetColor();
          std::cout << "    Введите размер лабиринта (он должен быть нечетным "
                       "от 5 до 25 ): ";
          if (!CheckIsNumber(size_of_maze, 5, 25) || size_of_maze % 2 == 0) {
            SetColor(4);
            std::cout << "    Некорретный ввод!\n\n";
            ResetColor();
            continue;
          }
          break;
          std::cout << "\n\n";
        }
        int see_generate;
        SetColor(10);
        std::cout << kLineOfEval << "\n\n\n"
                  << std::string(100, ' ');
        ResetColor();

        std::cout << "Хотите увидеть пошаговую генерацию лабиринта?" << "\n\n\n";
        SetColor(10);
        std::cout << kLineOfEval;
        SetColor(9);

        while (true) {
          std::cout << "\n\n    1.Да\n\n    2.Нет\n\n";
          SetColor(10);
          std::cout << kLineOfEval << "\n\n\n";
          ResetColor();
          std::cout << "    Выберите опцию от 1 до 2: ";
          
        
          if (!CheckIsNumber(see_generate, 1, 2)) {
            SetColor(4);
            std::cout << "    Некорретный ввод!\n\n";
            SetColor(10);
            std::cout << kLineOfEval << "\n";
            ResetColor();
            continue;
          }
          break;
          std::cout << "\n\n";
        }
        switch (see_generate) {
          case 1: {
            maze.resize(size_of_maze, std::vector<char>(size_of_maze));
            GenerateMaze(maze, size_of_maze,see_generate);
            is_user_made_maze = 1;
            break;
  
          
          }
          case 2: {
            maze.resize(size_of_maze, std::vector<char>(size_of_maze));
            GenerateMaze(maze, size_of_maze, see_generate);
            is_user_made_maze = 1;
            break;
          }

                
        }
        std::cout << "    Лабиринт успешно сгенериован!\n\n";
        break;
      }
      case 2: {
        std::vector<std::vector<char>> copy_maze;
        copy_maze.resize(0, std::vector<char>(0));
        int copy_size_of_maze = 0;
        InputFile(copy_maze, copy_size_of_maze);
        if (!copy_size_of_maze) {
          if (!is_user_made_maze) {
            size_of_maze = 0;
            maze.resize(0, std::vector<char>(0));
          }
          SetColor(4);
          std::cout << "    Данный лабиринт не подходит под описание, возврат к "
                       "выбору задачи\n\n";
          ResetColor();
        } else {
          size_of_maze = copy_size_of_maze;
          maze = copy_maze;
          std::cout << "    Лабиринт успешно загружен!\n\n";
          is_user_made_maze = 1;
        }
        break;
      }
      case 3: {
        if (is_user_made_maze) {
          ShowMaze(maze, size_of_maze);
        } else {
          std::cout << "    Мы не можем продолжить без генерации "
                        "лабиринта..................\n\n";
        }
        break;
        
      
      }
      case 4: {
        if (is_user_made_maze) {
          
          int clean;
          SetColor(10);
          std::cout << kLineOfEval << "\n\n\n" << std::string(100, ' ');
          ResetColor();

          std::cout << "  Очистить файл?" << "\n\n\n";
          SetColor(10);
          std::cout << kLineOfEval << "\n\n\n";
          ResetColor();

          while (true) {
            std::cout << "    1.Да\n\n    2.Нет\n\n";
            SetColor(10);
            std::cout << kLineOfEval << "\n\n\n";
            ResetColor();
            std::cout << "    Выберите опцию от 1 до 2: ";

            if (!CheckIsNumber(clean, 1, 2)) {
              SetColor(4);
              std::cout << "    Некорретный ввод!\n\n";
              SetColor(10);
              std::cout << kLineOfEval << "\n";
              ResetColor();
              continue;
            }
            break;
            std::cout << "\n\n";
          }
          SetColor(10);
          std::cout << kLineOfEval << "\n\n\n" << std::string(100, ' ');
          ResetColor();
          std::cout << "\n\n";
          if (clean == 1) {
            std::fstream("output_maze.txt", std::fstream::out);
          }
          
          std::cout << "    Лабиринт успешно загружен!\n\n";
          OutputMaze(maze, size_of_maze);
        } else
          std::cout << "    Мы не можем продолжить без генерации "
                       "лабиринта..................\n\n";
        break;
        
      } 
      case 5: {
        if (is_user_made_maze)
          flag = 0;
        else
          (std::cout << "    Мы не можем продолжить без генерации "
                        "лабиринта..................\n\n");
        break;
      }


      default: {
        SetColor(4);
        std::cout
            << "  Такой опции не обнаружено, возврат к выбору задачи ///\n\n";
        ResetColor();
      }
    }
  }
  flag = 1;
  while (flag) {

    SecondStep();
    std::cout << "\n\n";
    while (true) {
      std::cout << "    Выберите опцию от 1 до 5: ";
      if (!CheckIsNumber(user, 1, 5)) {
        std::cout << "\n";
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
        std::cout << kLineOfEval << "\n\n\n"
                  << std::string(100, ' ');
        ResetColor();

        std::cout << "  Очистить файл?" << "\n\n\n";
        SetColor(10);
        std::cout << kLineOfEval << "\n\n\n";
        ResetColor();

       

        while (true) {
          std::cout << "    1.Да\n\n    2.Нет\n\n";
          SetColor(10);
          std::cout << kLineOfEval << "\n\n\n";
          ResetColor();
          std::cout << "    Выберите опцию от 1 до 2: ";

          if (!CheckIsNumber(clean, 1, 2)) {
            SetColor(4);
            std::cout << "    Некорретный ввод!\n\n";
            SetColor(10);
            std::cout << kLineOfEval << "\n";
            ResetColor();
            continue;
          }
          break;
          std::cout << "\n\n";
        }
        SetColor(10);
        std::cout << kLineOfEval << "\n\n\n"
                  << std::string(100, ' ');
        ResetColor();
        std::cout<< "\n\n";
        if (clean == 1) {
          std::fstream("output_wave.txt", std::fstream::out);
        }
        WaveAlgorithm(maze, maze.size(), 3);
 
        break;
      }
      case 4: {
        int clean;
        SetColor(10);
        std::cout << kLineOfEval << "\n\n\n" << std::string(100, ' ');
        ResetColor();

        std::cout << "  Очистить файл?" << "\n\n\n";
        SetColor(10);
        std::cout << kLineOfEval << "\n\n\n";
        ResetColor();

        while (true) {
          std::cout << "    1.Да\n\n    2.Нет\n\n";
          SetColor(10);
          std::cout << kLineOfEval << "\n\n\n";
          ResetColor();
          std::cout << "    Выберите опцию от 1 до 2: ";

          if (!CheckIsNumber(clean, 1, 2)) {
            SetColor(4);
            std::cout << "    Некорретный ввод!\n\n";
            SetColor(10);
            std::cout << kLineOfEval << "\n";
            ResetColor();
            continue;
          }
          break;
          std::cout << "\n\n";
        }
        SetColor(10);
        std::cout << kLineOfEval << "\n\n\n" << std::string(100, ' ');
        ResetColor();
        std::cout << "\n\n";
        if (clean == 1) {
          std::fstream("shortest_way.txt", std::fstream::out);
        }
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