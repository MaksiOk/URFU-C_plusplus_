// LR_4_StringProcessing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <stdlib.h>


using namespace std;

int StringLength1(char* strok) {
    int i = 0;
    for (i; strok[i] != '\0'; i++) {};
    return (i);
}

int StringLength2(char* strok) {
    int i = 0;
    while (strok[i] != '\0') {
        i++;
    }
    return (i);
}

int StringLength3(char* strok) {
    int i = 0;
   // i = end(strok);
    return (i);
}

void copy(char* str1, char* str2) {
    int n1 = StringLength1(str1);
    int n2 = StringLength1(str2);
    
    for (int i = 0; i < n2; i++ ) {
        str1[i] = str2[i];
    }
}

void comparison(char* str1, char* str2) {
    int i = 0;
    int n1 = StringLength1(str1);
    int n2 = StringLength1(str2);
    while (str1[i] == str2[i] && i<n2) {
        i++;
    }
    if (i == n2) {
        cout << "Strings are equal" << endl;
    }
    else {
        cout << "Strings are not equal" << endl;
    }
    
}

void konkat(char* str1, char* str2) {
    while (*str1 != '\0') {
        str1++;
    }
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main()
{
    //char* str1, * str2;
    //str1 = (char*)malloc(100);
    //str2 = (char*)malloc(100);
    char str1[] = "qwerty", str2[] = "1234567890";

    int lenght = 0;

    lenght = StringLength1(str1);

    cout << "String Length 1 metod 1:" << lenght << endl;

    lenght = StringLength1(str2);
    cout << "String Length 2 metod 1:" << lenght << endl;


    lenght = StringLength2(str1);

    cout << "String Length 1 metod 2:" << lenght << endl;

    lenght = StringLength2(str2);
    cout << "String Length 2 metod 2:" << lenght << endl;

   // lenght = StringLength3(str1);
    //lenght = (*(&str1+1) - str1)-1;
    cout << "String Length 1 metod 3:" << lenght << endl;

    //lenght = StringLength3(str2);
    //lenght = (*(&str2+1) - str2)-1;
    cout << "String Length 2 metod 3:" << lenght << endl;
    
    copy(str2, str1);
    cout << "Copy str 1 in str 2: " << str2 << endl;

    char str11[] = "qwerty", str12[] = "qwerty";

    comparison(str11, str12);

    konkat(str11, str12);
    cout << "concotenation: str1=" << str11;
    cout << ", str2=" << str12 << endl;

   // free(str1);
   // free(str2);
    return 0;
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
