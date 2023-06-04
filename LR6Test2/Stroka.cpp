#include "Stroka.h"
#include <string>
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

Stroka::Stroka(const char *string)
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
    //std::strcpy(str, s.str);
    int n2 = 0;
    int i = 0;
    for (n2; s.str[n2] != '\0'; n2++) {};
    for (i; i < n2; i++) {
        str[i] = s.str[i];
    }
    str[i] = '\0';
}

Stroka::~Stroka()
{
}

void* Stroka::operator new(size_t size)
{
    return malloc(size);
}

void* Stroka::operator new[](size_t size)
{
    return malloc(size);
}

void Stroka::operator delete(void* p)
{
    free(p);
}

void Stroka::operator delete[](void* p)
{
    free(p);
}

Stroka& Stroka::operator=(const Stroka& s)
{
   /* std::strcat(str, s.str);
    return *this;*/

        int n2 = 0;
        int i = 0;
        for (n2; s.str[n2] != '\0'; n2++) {};
        for (i; i < n2; i++) {
            str[i] = s.str[i];
        }
        str[i] = '\0';
    return *this;
}

Stroka& Stroka::operator+(const Stroka& s)
{
    /*strcat_s(str, s.str);
    return *this;*/
    int i = 0;
    while (str[i] != '\0' && i < 80) {
        i++;
    }
    int j = 0;
    while (s.str[j] != '\0' && i + j < 80) {
        str[i + j] = s.str[j];
        j++;
    }
    str[i + j] = '\0';
    return *this;
}

int Stroka::operator==(const Stroka& s) 
{
    //if ((strcmp(str, s.str)) == 0)
    //    return 1;
    //else
    //    return 0;
    int i = 0;
    int n2 = 0;
    for (n2; s.str[n2] != '\0'; n2++) {};
    while (str[i] == s.str[i] && i < n2) {
        i++;
    }
    if (i == n2) {
        return 1;
    }
    else {
        return 0;
    }
}

int Stroka::dlina()
{
    //return strlen(str);
    //return 0;
    int i = 0;
    for (i; str[i] != '\0'; i++) {};
    return (i);
    
}


//void Stroka::input()
//{
//    std::cin >> str;
//}


void Stroka::output()
{
    std::cout << str;
}

