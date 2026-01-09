#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "input_output_HEAD.h"
#include <thread>
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
//вывод цветного лабиритнка
void ShowMaze(std::vector<std::vector<char>> maze, int size_of_maze) {
  SetColor(10);
  std::cout << kLineOfEval << "\n\n\n"
            << std::string(100, ' ');
  ResetColor();

  std::cout << "Ваш лабиринт" << "\n\n\n";
  SetColor(10);
  std::cout << kLineOfEval;
  ResetColor();
  std::cout << "\n\n\n";
  char part_of_maze;
  for (int i = 0; i < size_of_maze; i++) {
    std::cout << "    ";
    for (int j = 0; j < size_of_maze; j++) {
      part_of_maze = maze[i][j];
      switch (part_of_maze) {
        case '/': {
          SetColor(1);
          std::cout << std::right << std::setw(6) << (maze[i][j]);
          ResetColor();
          break;
        }
        case '*': {
          SetColor(1);
          std::cout << std::right << std::setw(6) << (maze[i][j]);
          ResetColor();
          break;
        }
        case '.': {
          SetColor(10);
          std::cout << std::right << std::setw(6) << '.';
          ResetColor();
          break;
        } 
        default: {
          std::cout << std::right << std::setw(6) << "####";
          break;
        }
      }
      std::cout << " ";
    }
    std::cout << "\n\n";
  }
  std::cout << "\n\n";

}
//либиринт из файла 
void InputFile(std::vector<std::vector<char>> & maze, int & size_of_maze) {
  std::ifstream input_maze("input_maze.txt");
  if (!input_maze.is_open()) {
    SetColor(4);
    std::cout << "Ошибка открытия файла для записи////" << "\n\n";
    ResetColor();
    return;
  }
  size_of_maze = 0;
  std::string part_of_maze;
  float copy_size;
  //из-за юникода 1 символ скип
  for (int i = 0; i < 1; i++) {
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
    // из-за юникода 1 символ скип
    for (int i = 0; i < 1; i++) {
      input_maze >> part_of_maze;
    }
    for (int i = 0 ; i < size;i++) {
      for (int j = 0; j < size; j++) {
          
        

        
        input_maze >> part_of_maze;
        //все стены кроме точек и дверей
        if (part_of_maze.size() == 1 && (part_of_maze[0] == '.' || part_of_maze[0] =='/')) 
            maze[i][j] = part_of_maze[0];
        else 
            maze[i][j] = '#';
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
//проверка на ввод цифры, а так же граничные значения
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
//вывод волны в файл
void OutputWaveFile(std::vector<std::vector<int>> wave, int size_of_maze,
                int curret_step) {
  std::ofstream output_file;
  output_file.open("output_wave.txt", std::ofstream::out | std::ofstream::app);
  if (!output_file.is_open()) {
    SetColor(4);
    std::cout << "Ошибка открытия файла для записи////" << "\n\n";
    ResetColor();
    return;
  }
  output_file << kLineOfEval;

  output_file << "\n\n  ";
  output_file << "    Волна номер: " << curret_step << "\n\n";

  output_file << kLineOfEval;
  output_file << "\n\n\n\n";
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
        //перевожу из списка волны в более - менее читаемый вариант
      if (wave[i][j] == 9999) {
          output_file << std::right << std::setw(6) << "####";
      
      }
      else if (wave[i][j] == -1) {
        output_file << std::right << std::setw(6) << '.';

      } else
        output_file << std::right << std::setw(6) << wave[i][j];
      output_file << " ";
    }
    output_file << "\n\n";
  }
  output_file << "\n\n\n";
  output_file.close();
}
//вывод кратчайшего пути в файл
void OutputShortestWay(std::vector<std::vector<char>> maze, int size_of_maze) {
  std::ofstream output_file;
  output_file.open("shortest_way.txt" , std::ofstream::out | std::ofstream::app);
  
  if (!output_file.is_open()) {
    SetColor(4);
    std::cout << "Ошибка открытия файла для записи////" << "\n\n";
    ResetColor();
    return;
  }
  char part_of_maze;
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      part_of_maze = maze[i][j];
      switch (part_of_maze) {
        case '#': {
          output_file << std::right << std::setw(6) << "####";
          break;
        }
        case '.': {
          SetColor(10);
          output_file << std::right << std::setw(6) << '.';
          ResetColor();
          break;
        }
        default: {
          SetColor(1);
          output_file << std::right << std::setw(6) << (maze[i][j]);
          ResetColor();
        }
      }
      output_file << " ";
    } 
  output_file << "\n\n";
  } 
  output_file.close();
}
//вывод лаб. в файл
void OutputMaze(std::vector<std::vector<char>> maze, int size_of_maze) {
  std::ofstream output_file;
  output_file.open(("output_maze.txt") , std::ofstream::out | std::ofstream::app);
  
  if (!output_file.is_open()) {
    SetColor(4);
    std::cout << "Ошибка открытия файла для записи////" << "\n\n";
    ResetColor();
    return;
  }
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      if (maze[i][j] == '#') {
        output_file << std::right << std::setw(6) << "####";
      } else if (maze[i][j] == -1) {
        output_file << std::right << std::setw(6) << '.';

        ResetColor();
      } else if (maze[i][j] == 2026) {
        SetColor(11);
        output_file << std::right << std::setw(6) << 2026;

        ResetColor();
      } else if (maze[i][j] == 0) {
        SetColor(5);
        output_file << std::right << std::setw(6) << 0;

        ResetColor();
      } else {
        SetColor(1);
        output_file << std::right << std::setw(6) << (maze[i][j]);

        ResetColor();
      }
      std::cout << " ";
    }
    output_file << "\n\n";
  }
  output_file.close();
}
//вывод поэтапно волны в консоль
void OutputWaveConsole(std::vector<std::vector<int>> wave, int size_of_maze,int curret_step) {
  SetColor(10);
  std::cout << kLineOfEval;
  SetColor(9);
  std::cout << "\n\n  ";
  std::cout << "  Волна номер: " << curret_step << "\n\n";
  SetColor(10);
  std::cout << kLineOfEval;
  std::cout << "\n\n\n\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(650));
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      if (wave[i][j] == 9999) {
        SetColor(7);
        std::cout << std::right << std::setw(6) << "####";
        std::cout << " ";
        ResetColor();
      } else if (wave[i][j] == -1) {
        SetColor(11);
        SetColor(10);
        std::cout << std::right << std::setw(6) << '.';
        std::cout << " ";
        ResetColor();
      } else if (wave[i][j] == 2026) {
        SetColor(11);
        std::cout << std::right << std::setw(6) << 2026;
        std::cout << " ";
        ResetColor();
      } else if (wave[i][j] == 0) {
        SetColor(5);
        std::cout << std::right << std::setw(6) << 0;
        std::cout << " ";
        ResetColor();
      } else {
        SetColor(1);
        std::cout << std::right << std::setw(6) << (wave[i][j]);
        std::cout << " ";
        ResetColor();
      }
    }
    std::cout << "\n\n";
  }
  std::cout << "\n\n\n";
}