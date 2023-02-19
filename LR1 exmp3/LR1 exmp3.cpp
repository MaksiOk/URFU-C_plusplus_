﻿// LR1 exmp3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int a = 2, b = 5;
	void obmen1(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	std::cout << "Befor exchange:  a = " << a << "b = " << b << endl;
	obmen1(a, b);
	std::cout << "After exchange 1:  a = " << a << "b = " << b << endl;
	obmen2(&a, &b);
	std::cout << "After exchange 2:  a = " << a << "b = " << b << endl;
	obmen3(a, b);
	std::cout << "After exchange 3:  a = " << a << "b = " << b << endl;

}

void obmen1(int x, int y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void obmen2(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void obmen3(int &x, int &y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.