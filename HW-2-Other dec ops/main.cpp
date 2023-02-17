// main.cpp

/*
  17.02.2023
  ���� 2, ������� 9
  ������ 1, ��������� � ������
  CPP-07
  @j1n4ed
*/

import <iostream>;
import fraction;

#include <Windows.h>

int main(int argc, char** argv)
{
	// console settings ----------------
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ---------------------------------

	int num1 = 0, 
		num2 = 0,
		denum1 = 0,
		denum2 = 0;

	/*
������� ��������� ����� 1: 3
������� ����������� ����� 1: 4
������� ��������� ����� 2: 4
������� ����������� ����� 2: 5
3/4 + 4/5 = 31/20
3/4 - 4/5 = -1/20
3/4 * 4/5 = 3/5
3/4 / 4/5 = 15/16
++3/4 * 4/5 = 7/5
�������� ����� 1 = 7/4
7/4-- * 4/5 = 7/5
������� ����� 1 = 3/4
	*/

	std::cout << "������� ��������� ����� 1: ";
	std::cin >> num1;
	std::cout << "������� ����������� ����� 1:  ";
	std::cin >> denum1;

	Fraction frac1(num1, denum1);

	std::cout << "������� ��������� ����� 2: ";
	std::cin >> num2;
	std::cout << "������� ����������� ����� 2:  ";
	std::cin >> denum2;

	Fraction frac2(num2, denum2);

	
	std::cout << frac1 << " + " << frac2 << " = " << (frac1 + frac2) << '\n';
	std::cout << frac1 << " - " << frac2 << " = " << (frac1 - frac2) << '\n';
	std::cout << frac1 << " * " << frac2 << " = " << (frac1 * frac2) << '\n';
	std::cout << frac1 << " / " << frac2 << " = " << (frac1 / frac2) << '\n';
	std::cout << "++" << frac1 << " * " << frac2 << " = " << (++frac1 * frac2) << '\n';
	std::cout << "�������� ����� 1: " << frac1 << '\n';
	std::cout << frac1 << "--" << " * " << frac2 << " = " << (frac1-- * frac2) << '\n';
	std::cout << "�������� ����� 1: " << frac1 << '\n';

	// Clena && exit
	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}