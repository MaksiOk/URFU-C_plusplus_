// LR_4_StringProcessing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>


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
    int counter = 0;
    while (strok[++counter]) {
    }
    return counter;
}

void copy(char* str1, char* str2) {
    int n1 = StringLength1(str1);
    int n2 = StringLength1(str2);
    int i = 0;
    
    for (i = 0; i < n2; i++ ) {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
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
    int i = 0;
    char x;
    char *str1;
    char *str2;
    str1 = (char*)malloc(100);
    str2 = (char*)malloc(100);
    //str1 = (char*)calloc(100, sizeof(char));
    //str2 = (char*)calloc(100, sizeof(char));
    //str1 = "qwerty", 
    //str2 = "1234567890";

    cout << "Insert String 1" << endl;
    cin >> str1;
    cout << "Insert String 2" << endl;
    cin >> str2;

    cout << str1 << endl;
    cout << str2 << endl;
    
    int lenght = 0;

    lenght = StringLength1(str1);
    cout << "String Length 1 metod 1:" << lenght << endl;

    lenght = StringLength1(str2);
    cout << "String Length 2 metod 1:" << lenght << endl;


    lenght = StringLength2(str1);
    cout << "String Length 1 metod 2:" << lenght << endl;

    lenght = StringLength2(str2);
    cout << "String Length 2 metod 2:" << lenght << endl;

    lenght = StringLength3(str1);
    cout << "String Length 1 metod 3:" << lenght << endl;

    lenght = StringLength3(str2);
    cout << "String Length 2 metod 3:" << lenght << endl;
    
    copy(str2, str1);
    cout << "Copy str 1 in str 2: " << str2 << endl;

   // char str11[256] = "qwerty", str12[] = "75031";

    comparison(str1, str2);

    konkat(str1, str2);
    cout << "concotenation: str1=" << str1;
    cout << ", str2=" << str2 << endl;

    vector <string> Strings = { "cat","dog","rabbit" };
    for (auto word : Strings) {
        char str[sizeof(word) / sizeof(char)];
        strcpy(str, word.c_str());
        cout << str << endl;
        cout << str2 << endl;
        copy(str2, str);
        cout << str2 << endl;
        lenght = StringLength1(str);
        cout << lenght << endl;
    }
    

   free(str1);
   free(str2);
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
