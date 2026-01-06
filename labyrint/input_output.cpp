#include <iostream>
#include <vector>
#include <Windows.h>
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
    default:
      SetColor(13);  // белый для других символов
      break;
  }
  std::cout << symbol;
  ResetColor();
}

void ShowMaze(std::vector<std::vector<char>> maze, int size_of_maze) {
  for (int i = 0; i < size_of_maze; i++) {
    for (int j = 0; j < size_of_maze; j++) {
      PrintColoredSymbol(maze[i][j]);
      std::cout << " ";
    }
    std::cout << "\n";
  }

}