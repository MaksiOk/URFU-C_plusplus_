#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
class Stroka
{
	char str[80];
public:
	Stroka() = default;			//Конструктор по умолчанию
	Stroka(char);
	Stroka(const char *);		//Конструктор типа 
	Stroka(const Stroka&);
	//Stroka();					// конструктор, который создает экземпляр класса, используя заданный размер динамической памяти
	~Stroka();					// деструктор для избежания утечки памяти
	void* operator new(size_t);
	void* operator new[](size_t);
	void operator delete(void*);
	void operator delete[](void*);
	Stroka& operator=(const Stroka&);
	Stroka& operator+(const Stroka&);
	int operator==(const Stroka&);
	int dlina();
	void input();
	void output();
	friend std::ostream& operator<< (std::ostream& out, const Stroka& s) {  //перегрузка оператора <<
		out << s.str;
		return out;
	}
	friend std::istream& operator >> (std::istream& in, Stroka& s) {
		char h[80];
		//char dummy;
		// Считываем число и любой непробельный символ за ним
		in >> h;

		// У нас нет другого способа изменить время через публичный интерфейс
		// кроме присваивания нового значения
		s = Stroka(h);
		return in;
	}
};

