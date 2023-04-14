// LR5_File.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

//using namespace std;

int Count_Empty(char* name) {
    int space = 0;
    char ch;
    std::ifstream in(name);

    while (in.get(ch))
    {
        if (ch < 33) space++;
    }
    in.close();
    return space;
}

int Count_Not_Empty(char* name) {
    int space = 0;
    char ch;
    std::ifstream in(name);

    while (in.get(ch))
    {
        if (ch > 33) space++;
    }
    in.close();
    return space;
}

void SubString_Search(char* name, char desired) {

}

int main()
{
    std::string line;
    char ch, name[50] = "Test.txt";
    //FILE* in;
    std::cout << "Open File Test.txt" << std::endl;
    //std::cin >> name;

   

    std::ifstream in(name); // окрываем файл для чтения
    if (in.is_open()){
        while (getline(in, line)){
            std::cout << line << std::endl;
        }
    }
    in.close();     // закрываем файл

    std::cout << "Empty symbols - ";
    std::cout << Count_Empty(name) << std::endl;
    std::cout << "Not Empty symbols - ";
    std::cout << Count_Not_Empty(name) << std::endl;

    //if ((in = fopen(name, "r")) == NULL) {
    //    cout << "File didn't open" << endl;
    //} else{
    //    while (!feof(in)) {
    //        ch = getc(in);
    //        putchar(ch);
    //    }
    //}
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
