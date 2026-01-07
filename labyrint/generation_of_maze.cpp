#include <iostream>
#include <vector>
#include <time.h>
void GenerateMaze(std::vector<std::vector<char>>& maze, int size_of_maze) {
  std::srand(std::time(NULL));
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
  // генерация стенок в самом лабиринте
  for (int i = 1; i < size_of_maze-1; i++) {
    for (int j = 1; j < size_of_maze-1; j++) {
      if (i % 2 == 0 && j % 2 == 0) {
        int random_direction = rand() % 4 + 1;
        int shall_we_stop;
        if (random_direction == 1) { //вверх
          for (int up = i; up > 0 && maze[up][j] != '#'; up--) {
              shall_we_stop = rand() % 7;
              if (shall_we_stop)
                maze[up][j] = '#';
              else
                break;
            
          }
        }
        if (random_direction == 2) {  // вправо
          for (int right = j; right < size_of_maze - 1 && maze[i][right] != '#'; right++) {
            shall_we_stop = rand() % 6;
            if (shall_we_stop) maze[i][right] = '#';
            else
              break;
          }
        }
        if (random_direction == 3) {  // вниз
          for (int down = i; down < size_of_maze - 1 && maze[down][j] != '#'; down++) {
            shall_we_stop = rand() % 6;
            if (shall_we_stop) maze[down][j] = '#';
            else
              break;
          }
        }
        if (random_direction == 4) {  // влево
          for (int left = j; left != 0 && maze[i][left] != '#'; left--) {
            shall_we_stop = rand() %6;
            if (shall_we_stop) maze[i][left] = '#';
            else
              break;
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
  int which_side = (rand() % 2); //0 слева, 1 снизу
  if (!which_side) {
    maze[size_of_maze - 2][enter] = '/';
  } else {
    maze[enter][1] = '/';

  }
  //выход
  int exit = 0;

  while (exit % 2 == 0 || exit == size_of_maze - 1 ) {
    exit = rand() % (size_of_maze );
  }
  which_side = (rand() % 3) + 2;  // 3 спрва , 4 сверху
  if (which_side==3) {
    maze[exit][size_of_maze-2] = '/';
  } else {
    maze[1][exit] = '/';
  }
  return;
}