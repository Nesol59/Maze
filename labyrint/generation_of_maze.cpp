#include <iostream>
#include <vector>
#include <time.h>
#include "input_output_HEAD.h"
#include <thread>
void generateMaze(std::vector<std::vector<char>>& maze, int size_of_maze,
                  int see_generate) {
  srand(time(NULL));
  // генерация внешних стенок

  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      if (i == 0 || j == 0 || j == size_of_maze-1 || i == size_of_maze-1) {
        maze[i][j] = '#';
      } else {
        maze[i][j] = '.';
      }

    }
  }
  // если надо вывод поэтапно генерации лабиринта
  std::vector<std::vector<char>> copy_maze = maze;

  if (see_generate == 1) {
    
    std::this_thread::sleep_for(std::chrono::milliseconds(550));
    showMaze(maze, size_of_maze);
  }
  // генерация стенок в самом лабиринте
  for (int i = 1; i < size_of_maze-1; i++) {
    for (int j = 1; j < size_of_maze-1; j++) {
      if (i % 2 == 0 && j % 2 == 0) {
        int random_direction = rand() % 4 + 1;
        int shall_we_stop = 1;
        switch (random_direction) {
          case 1: {  // вверх
            for (int up = i; up > 0 && maze[up][j] != '#'; up--) {
              if (up % 2 == 0 && up != i) {
                shall_we_stop = rand() % 3;
              }
              if (shall_we_stop)
                maze[up][j] = '#';
              else
                break;
            }
            break;
          }
          case 2: {  // вправо
            for (int right = j;
                 right < size_of_maze - 1 && maze[i][right] != '#'; right++) {
              if (right % 2 == 0 && right != j) {
                shall_we_stop = rand() % 3;
              }
              if (shall_we_stop)
                maze[i][right] = '#';
              else
                break;
            }
            break;
          }
          case 3: {  // вниз
            for (int down = i; down < size_of_maze - 1 && maze[down][j] != '#';
                 down++) {
              if (down % 2 == 0 && down != i) {
                shall_we_stop = rand() % 3;
              }
              if (shall_we_stop)
                maze[down][j] = '#';
              else
                break;
            }
            break;
          }
          case 4: {  // влево
            for (int left = j; left != 0 && maze[i][left] != '#'; left--) {
              if (left % 2 == 0 && left != j) {
                shall_we_stop = rand() % 3;
              }
              if (shall_we_stop)
                maze[i][left] = '#';
              else
                break;
            }
            break;
          }
          default: {
            break;
          }
        }
        // если надо вывод поэтапно генерации лабиринта
        if (see_generate == 1) {
          if (copy_maze != maze) {
            copy_maze = maze;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            showMaze(maze, size_of_maze);
          }
        }
      }
      
    }
  }
  //вход
  int enter = 0;
  while (enter % 2 == 0 || enter == size_of_maze - 1 ) {
    enter = rand() % (size_of_maze-1);

  }

  int which_side_enter = (rand() % 2); //0 слева, 1 снизу
  if (!which_side_enter) {
    maze[size_of_maze - 2][enter] = '/';
  } else {
    maze[enter][1] = '/';

  }
  //выход
  int exit = 0;
  int which_size_exit;
  while (exit % 2 == 0 || exit == size_of_maze - 1 ) {
    exit = rand() % (size_of_maze );
  }
  if (which_side_enter) {
    which_size_exit = 2; // 2 справа
  } else
    which_size_exit = 3;
  if (which_size_exit == 2) {
    maze[exit][size_of_maze-2] = '/';
  } else {
    maze[1][exit] = '/'; //  слева
  }
  // если надо вывод поэтапно генерации лабиринта
  if (see_generate == 1) {
    if (copy_maze != maze) {
      copy_maze = maze;
      std::this_thread::sleep_for(std::chrono::milliseconds(550));
      showMaze(maze, size_of_maze);
    }
  }
  return;
}