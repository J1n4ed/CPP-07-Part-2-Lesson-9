// main.cpp

/*
  17.02.2023
  Тема 2, Занятие 9
  Работа 1, Сравнения в дробях
  CPP-07
  @j1n4ed
*/

#include <Windows.h>
#include <iostream>

import fraction;

int main(int argc, char** argv)
{
	// console settings ----------------
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ---------------------------------

	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	// Clena && exit
	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}