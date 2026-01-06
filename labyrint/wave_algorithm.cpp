#include <iostream>
#include <vector>
#include <iomanip>
void WaveAlgorithm(std::vector<std::vector<char>> maze, int size_of_maze) {
  std::vector<std::vector<int>> wave(size_of_maze,
                                     std::vector<int>(size_of_maze));
  int start_y, start_x, end_x, end_y;
  for (int i = 1; i < size_of_maze-1; i++) {
    if (maze[i][size_of_maze - 2] == '/'){
      end_y = i;
      end_x = size_of_maze - 2;
    }
    if (maze[1][i] == '/') {
      end_y = 1;
      end_x = i;
    }
    if (maze[size_of_maze - 2][i] == '/') {
      start_x = i;
      start_y = size_of_maze - 2;
    }
    if (maze[i][1] == '/') {
      start_y =i;
      start_x = 1;
    }
      
  }
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
  wave[end_y][end_x] = 2025;

  int curret_step = 0;
  bool flag = 1;
  while (flag) {
    for (int i = 1; i < size_of_maze - 1; i++) {
      for (int j = 1; j < size_of_maze - 1; j++) {
        if (wave[i][j] == curret_step) {
          if (wave[i][j + 1] == 2025 || wave[i][j - 1] == 2025 ||
              wave[i - 1][j] == 2025 || wave[i + 1][j] == 2025) {
            flag = 0;
          }
          if (wave[i][j + 1] != 9999 && wave[i][j + 1] != 0 && wave[i][j + 1]<0) {
            wave[i][j + 1] = curret_step + 1;

          }
          if (wave[i][j - 1] != 9999 && wave[i][j - 1] != 0 &&
              wave[i][j - 1] < 0) {
            wave[i][j - 1] = curret_step + 1;

          }
          if (wave[i + 1][j] != 9999 && wave[i + 1][j] != 0 &&
              wave[i+1][j] < 0) {
            wave[i + 1][j] = curret_step + 1;

          }
          if (wave[i - 1][j] != 9999 && wave[i - 1][j] != 0 &&
              wave[i-1][j] < 0) {
            wave[i - 1][j] = curret_step + 1;

          }
        }
      }
    }
    curret_step++;
    for (int i = 0; i < 1000000000; i++) {
    }
    for (int i = 0; i < size_of_maze; i++) {
      for (int j = 0; j < size_of_maze; j++) {
        std::cout << std::right << std::setw(6) << (wave[i][j]);
        std::cout << " ";
      }
      std::cout << "\n";
    }
    std::cout << "\n\n\n";
  }
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      std::cout << std::right << std::setw(6) << (wave[i][j]);
      std::cout << " ";
    }
    std::cout << "\n";
  }
}