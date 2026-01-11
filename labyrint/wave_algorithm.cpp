#include <iostream>
#include <vector>
#include <iomanip>
#include "input_output_HEAD.h"
#include <math.h>
#include <thread>
#include <fstream>
void WaveAlgorithm(std::vector<std::vector<char>> maze,
                    int size_of_maze,
                   int user) {
  std::vector<std::vector<int>> wave(size_of_maze,
                                     std::vector<int>(size_of_maze));
  int start_y=0, start_x=0, end_x=0, end_y=0;
  
  //нахожу начало и конец
  for (int i = 1; i < size_of_maze-1; i++) {
    for (int j = 1; j < size_of_maze - 1; j++) {
        if (maze[i][j] == '/') {
            if (!start_x) {
              start_y = i;
              start_x = j;
            } else {
              end_y = i;
              end_x = j;
            
            }
            
        }
      
    
    }
    
      
  }
  //создаю массив для волны
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      if (i == 0 || j == 0 || j == size_of_maze - 1 || i == size_of_maze - 1 ||
          maze[i][j] =='#') {
        wave[i][j] = 9999;
      } else if (maze[i][j] =='.') {
        wave[i][j] = -1;
      } else
        wave[i][j] = 0;
    }
  }
  //конец типо 2026 нг все дела
  wave[end_y][end_x] = 2026;
  //текущий номер волны
  int curret_step = 0;
  bool flag = 1;
  // старая волна, мало ли выхода нет
  std::vector<std::vector<int>> old_wave = wave;
  //сам алгоритм волны, идущий пока волна не достигнет выхода (можно сделать,чтоб шла , пока еще есть еще есть неопсещенный волной клетки)
  while (flag) {
    for (int i = 1; i < size_of_maze - 1; i++) {
      for (int j = 1; j < size_of_maze - 1; j++) {
        if (wave[i][j] == curret_step) {
          if (wave[i][j + 1] == 2026 || wave[i][j - 1] == 2026 ||
              wave[i - 1][j] == 2026 || wave[i + 1][j] == 2026) {
            flag = 0;
          }
          if (wave[i][j + 1] != 9999 && wave[i][j + 1] != 0 &&
              wave[i][j + 1] < 0) {
            wave[i][j + 1] = curret_step + 1;
          }
          if (wave[i][j - 1] != 9999 && wave[i][j - 1] != 0 &&
              wave[i][j - 1] < 0) {
            wave[i][j - 1] = curret_step + 1;
          }
          if (wave[i + 1][j] != 9999 && wave[i + 1][j] != 0 &&
              wave[i + 1][j] < 0) {
            wave[i + 1][j] = curret_step + 1;
          }
          if (wave[i - 1][j] != 9999 && wave[i - 1][j] != 0 &&
              wave[i - 1][j] < 0) {
            wave[i - 1][j] = curret_step + 1;
          }
        }
      }
    }

    curret_step++;
    if (old_wave == wave && flag) {
      if (user == 3)
        std::cout << "    Волновой алгоритм загружен до обнаружения отсутствия "
                     "выхода\n\n";
      setColor(4);
      std::cout << "    Из лабиринта нет выхода!\n\n";
      resetColor();
      flag = 0;
      return;
    } else old_wave = wave;
    //если надо вывод wave поэтапно
    switch (user) {
      case 1: {
        outputWaveConsole(wave, size_of_maze, curret_step);
        
      }
      case 3: {
        outputWaveFile(wave, size_of_maze, curret_step);

        break;
      }
      default: {
        break;
      }
    }
  }
  /*поиск кратчайшего пути (начинает с выохда и каждый раз выбирает путь, у которого мин_знач не равно стенке(стенка = 9999) 
   *и тропе без волны(-1) , а так же значение,меньше текущего)
  */
  std::vector<std::vector <int>> restore_path;
  int num1, num2, num3, num4,min_num;
  while (true) {
    num1 =9998;
    num2 = 9998;
    num3 = 9998;
    num4 = 9998;
    if (wave[end_y + 1][end_x] != 9999 && wave[end_y + 1][end_x]!=-1)
      num1 = wave[end_y + 1][end_x];
    if (wave[end_y][end_x + 1] != 9999 && wave[end_y][end_x + 1] != -1)
      num2 = wave[end_y][end_x + 1];
    if (wave[end_y][end_x - 1] != 9999 && wave[end_y][end_x - 1] != -1)
      num3 = wave[end_y][end_x - 1];
    if (wave[end_y-1][end_x] != 9999 && wave[end_y - 1][end_x] != -1)
      num4 = wave[end_y - 1][end_x];

    min_num = 10000000;
    min_num = min(min_num, num1);
    min_num = min(min_num, num2);
    min_num = min(min_num, num3);
    min_num = min(min_num, num4);
    restore_path.push_back(std::vector<int>(2));
    if (min_num == 0) break;
    if (min_num == num1) {
      restore_path.back()[0] = end_y+1;
      restore_path.back()[1] = end_x ;
      end_y++;
      continue;
    }
    if (min_num == num2) {
      restore_path.back()[0] = end_y;
      restore_path.back()[1] = end_x + 1;
      end_x++;
      continue;
    }
    if (min_num == num3) {
      restore_path.back()[0] = end_y;
      restore_path.back()[1] = end_x-1;
      end_x--;
      continue;
    }
    if (min_num == num4) {
      restore_path.back()[0] = end_y-1;
      restore_path.back()[1] = end_x;
      end_y--;
      continue;
    }
  }
  //в консоль
  switch (user) {
    case 2: {
      for (int i = 0; i < restore_path.size(); i++) {
        int x = restore_path[i][1];
        int y = restore_path[i][0];
        maze[y][x] = '*';
        maze[0][0] = '#';
      }
      showMaze(maze, size_of_maze);
      break;
    }
    case 3: {
      std::cout << "    Волна успешно загружена!\n\n";
      break;
    }
    // просто символ звездочки в файле плохо видно без голубого цвета
    case 4: {
      for (int i = 0; i < restore_path.size(); i++) {
        int x = restore_path[i][1];
        int y = restore_path[i][0];
        maze[y][x] = ' ';
        maze[0][0] = '#';
      }
      std::cout << "    Кратчайший путь успешно загружен!\n\n";
      outputShortestWay(maze, size_of_maze);
      break;
    }
  }


}