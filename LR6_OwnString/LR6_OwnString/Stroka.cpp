#include "Stroka.h"
#include <string>
#include <iostream>
#include "Stroka.h"
#define _CRT_SECURE_NO_WARNINGS



Stroka::Stroka(const char* string)
{
    //std::strcpy(str, string);
    int n2 = 0;
    int i = 0;
    for (n2; string[n2] != '\0'; n2++) {};
    for (i; i < n2; i++) {
        str[i] = string[i];
    }
    str[i] = '\0';
}

Stroka::Stroka(const Stroka& s)
{
    std::strcpy(str, s.str);
}

//Stroka& Stroka::operator=(const Stroka& s)
//{
//    std::strcat(str, s.str);
//    return *this;
//}

Stroka& Stroka::operator+(const Stroka& s)
{
    std::strcat(str, s.str);
    return *this;
}

int Stroka::operator==(const Stroka& s)
{
    if ((strcmp(str, s.str)) == 0)
        return 1;
    else
        return 0;
}

int Stroka::dlina()
{
    //return strlen(str);
    int i = 0;
    for (i; str[i] != '\0'; i++) {};
    return (i);
    //return 0;
}


void Stroka::input()
{
    std::cin >> str;
}


void Stroka::output()
{
    std::cout << str;
}
