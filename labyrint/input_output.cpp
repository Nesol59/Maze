#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "input_output_HEAD.h"

// ставит цвет
void SetColor(int colorCode) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, colorCode);
}
// функция для сброса цвета текста
void ResetColor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(
      hConsole, 7);  // делает белый цвет по дефолту, что другое не было цветным
}

// функция для вывода цветных символов
void PrintColoredSymbol(char symbol) {
  switch (symbol) {
    case '#':
      SetColor(7);  // белый
      break;
    case '.':
      SetColor(10);  // зеленый
      break;
    case '/':
      SetColor(1);  // синий
      break;
    case '*':
      SetColor(1);  // синий
      break;
    default:
      SetColor(7);  // белый
      break;

  }
  std::cout << symbol;
  ResetColor();
}

void ShowMaze(std::vector<std::vector<char>> maze, int size_of_maze) {
  SetColor(10);
  std::cout << std::string(full_screen, '=') << "\n\n\n"
            << std::string(100, ' ');
  ResetColor();

  std::cout << "Ваш лабиринт" << "\n\n\n";
  SetColor(10);
  std::cout << std::string(full_screen, '=');
  SetColor(9);
  std::cout << "\n\n\n";
  for (int i = 0; i < size_of_maze; i++) {
    std::cout << "    ";
    for (int j = 0; j < size_of_maze; j++) {
      
      PrintColoredSymbol(maze[i][j]);
      std::cout << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n\n";

}
void InputFile(std::vector<std::vector<char>> & maze, int & size_of_maze) {
  std::ifstream input_maze("input_maze.txt");
  if (!input_maze.is_open()) {
    SetColor(4);
    std::cout << "Ошибка открытия файла для записи////" << "\n\n";
    ResetColor();
    return;
  }
  size_of_maze = 0;
  char part_of_maze;
  float copy_size;
  for (int i = 0; i < 3; i++) {
    input_maze >> part_of_maze;
  }
  while (input_maze >> part_of_maze) {
    size_of_maze++;
  }
  int count_doors = 0;
  input_maze.clear();
  input_maze.seekg(0, input_maze.beg);
  copy_size = size_of_maze;
  if (sqrt(size_of_maze) == sqrt(copy_size)) {
    
    int size = sqrt(size_of_maze);
    size_of_maze = size; 
    maze.resize(size,std::vector<char>(size));
    for (int i = 0; i < 3; i++) {
      input_maze >> part_of_maze;
    }
    for (int i = 0 ; i < size;i++) {
      for (int j = 0; j < size; j++) {
          
        

        
        input_maze >> part_of_maze;
        maze[i][j] = part_of_maze;
        if (maze[i][j] == '/') {
          count_doors++;
        }
        if (count_doors > 2 || count_doors < 0) {
          size_of_maze = 0;
          return;
        }
      }
    }
  } else {

    size_of_maze = 0;
  }
  if (count_doors==1) size_of_maze = 0;
  input_maze.close();
}
bool CheckIsNumber(int & number, int min_eval,int max_eval) {
  std::string s;
  std::getline(std::cin, s);
  std::cout << "\n";
  for (size_t i = 0; i < s.length(); i++)
    if (!iswdigit(s[i])) {
      return 0;
    }
  if (!s.empty()) {
    number = std::stoi(s);
    if (number <= max_eval && number >= min_eval) {
      return 1;
    }
  }
  return 0;
}

void OutputWave(std::vector<std::vector<int>> wave, int size_of_maze,
                int curret_step) {
  std::ofstream output_file;
  output_file.open("output_wave.txt", std::ofstream::out | std::ofstream::app);
  if (!output_file.is_open()) {
    SetColor(4);
    std::cout << "Ошибка открытия файла для записи////" << "\n\n";
    ResetColor();
    return;
  }
  output_file << std::string(full_screen, '=');

  output_file << "\n\n  ";
  output_file << "Волна номер: " << curret_step << "\n\n";

  output_file << std::string(full_screen, '=');
  output_file << "\n\n\n\n";
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      if (wave[i][j] == 9999) {

        output_file << std::right << std::setw(6) << (wave[i][j]);
        output_file << " ";

      } else if (wave[i][j] == -1) {
        output_file << std::right << std::setw(6) << (wave[i][j]);
        output_file << " ";
      } else if (wave[i][j] == 2025) {

        output_file << std::right << std::setw(6) << (wave[i][j]);
        output_file << " ";

      } else if (wave[i][j] == 0) {

        output_file << std::right << std::setw(6) << (wave[i][j]);
        output_file << " ";

      } else {

        output_file << std::right << std::setw(6) << (wave[i][j]);
        output_file << " ";

      }
    }
    output_file << "\n\n";
  }
  output_file << "\n\n\n";
  output_file.close();
}

void OutputShortestWay(std::vector<std::vector<char>> maze, int size_of_maze) {
  std::ofstream output_file("shortest_way.txt");
  if (!output_file.is_open()) {
    SetColor(4);
    std::cout << "Ошибка открытия файла для записи////" << "\n\n";
    ResetColor();
    return;
  }
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      output_file << maze[i][j] <<' ';
    } 
  output_file << "\n";
  } 
  output_file.close();
}
void OutputMaze(std::vector<std::vector<char>> maze, int size_of_maze) {
  std::ofstream output_file("output_maze.txt");
  if (!output_file.is_open()) {
    SetColor(4);
    std::cout << "Ошибка открытия файла для записи////" << "\n\n";
    ResetColor();
    return;
  }
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      output_file << maze[i][j] << ' ';
    }
    output_file << "\n";
  }
  output_file.close();
}
