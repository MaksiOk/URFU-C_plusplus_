#pragma once
#define _CRT_SECURE_NO_WARNINGS
class Stroka
{
private:
	char str[80];
public:
	Stroka(const char*);
	Stroka(){}
	Stroka(const Stroka&);
	//Stroka& operator=(const Stroka&);
	Stroka& operator+(const Stroka&);
	int operator==(const Stroka&);
	int dlina();
	void input();
	void output();
};

