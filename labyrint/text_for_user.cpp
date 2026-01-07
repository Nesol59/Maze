#include <iostream>
#include <string>
#include <iomanip>
#include "input_output_HEAD.h"
const int full_screen = 237;
void FirstStep() {
  SetColor(10);
  std::cout << std::string(full_screen, '=') << "\n\n"
            << std::right << std::setw(140);
  ResetColor();
  std::cout << "Добро пожаловать в меню выбора задач :) " << "\n\n\n";
  SetColor(10);
  std::cout<< std::string(full_screen, '=');
  SetColor(9);
  std::cout<< "\n\n    1. Cгенерировать лабиринт ( можно использовать как пример для файла ) \n\n"
            << "    2. Загрузить лабиринт (двери должны быть символом < / > , тропа < . > , остальное будет считаться стенками)\n\n\n";
  SetColor(10);
  std::cout << std::string(full_screen, '=');
  ResetColor();
}
void SecondStep() {
  SetColor(10);
  std::cout << std::string(full_screen, '=') << "\n\n\n"
            << std::string(100, ' ');
  ResetColor();

  std::cout << "Добро пожаловать в меню выбора задач :)" << "\n\n\n";
  SetColor(10);
  std::cout << std::string(full_screen, '=');
  SetColor(9);
  std::cout << "\n\n\n    1. Вывести лабиринт на экран\n\n"
            << "    2. Загрузить этот лабиринт в файл\n\n"
            << "    3. Cледующий шаг\n\n\n";
  SetColor(10);
  std::cout << std::string(full_screen, '=');
  ResetColor();
}
void ThirdStep() {
  SetColor(10);
  std::cout << std::string(full_screen, '=') << "\n\n\n" << std::string(100, ' ');
  ResetColor();
  std::cout << "Добро пожаловать в меню выбора задач :)" << "\n\n\n";
  SetColor(10);
  std::cout << std::string(full_screen, '=');
  SetColor(9);
  std::cout << "\n\n\n    1. Вывести пошагово работу волнового алгоритма до нахождения выхода на экран (9999 - это стенки, -1 - это тропы, 2025 - это выход, 0 - это вход)\n\n"
            << "    2. Вывести кратчайший путь , если он есть, на экран (кратчайший путь обозначен "
               "символом"
            << " < * > " << ")\n\n"
            << "    3. Вывести пошагово работу волнового алгоритма до нахождения выхода в файл (9999 - это стенки, -1 - это тропы, 2025 - это выход, 0 - это вход)\n\n"
            << "    4. Вывести кратчайший путь , если он есть , в файл (кратчайший путь обозначен "
               "символом"
            << " <   > " << ")\n\n"
            << "    5. Закончить работу программы\n\n\n";
  SetColor(10);
  std::cout << std::string(full_screen, '=');
  ResetColor();
}