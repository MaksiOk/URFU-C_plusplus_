// LR5_File.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#define ESC "\x1b"
#define CSI "\x1b["


#include <iostream>
#include <fstream>
#include <string>
#include <wchar.h>
#include <windows.h>
#include <stdio.h>

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

void SubString_Search(char* name, std::string WordToFind) {
    std::string line;
    std::ifstream in(name); // окрываем файл для чтения
    size_t substring_length;
    int NumOfChar = WordToFind.length();
   
    std::cout << NumOfChar << std::endl;
    if (in.is_open()) {
        while (getline(in, line)) {
            int index = 0;
            while ((substring_length = line.find(WordToFind, index)) != std::string::npos) {
                std::cout << line.substr(index, substring_length-index);
                wprintf(L"\x1b[34;46m");
                std::cout << line.substr(substring_length, NumOfChar);
                wprintf(L"\x1b[m");
                //std::cout << "Length - " << substring_length << std::endl;
                index = NumOfChar + substring_length;
            } 
            if (index != 0) {
                std::cout << line.substr(index) << std::endl;
            }
            else {
                std::cout << line << std::endl;
            }
            
            }
            
        }
    in.close();     // закрываем файл
}

int main()
{
    
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }

    // Try some Set Graphics Rendition (SGR) terminal escape sequences
    /*wprintf(L"\x1b[31mThis text has a red foreground using SGR.31.\r\n");
    wprintf(L"\x1b[1mThis text has a bright (bold) red foreground using SGR.1 to affect the previous color setting.\r\n");
    wprintf(L"\x1b[mThis text has returned to default colors using SGR.0 implicitly.\r\n");
    wprintf(L"\x1b[34;46mThis text shows the foreground and background change at the same time.\r\n");
    wprintf(L"\x1b[0mThis text has returned to default colors using SGR.0 explicitly.\r\n");
    wprintf(L"\x1b[31;32;33;34;35;36;101;102;103;104;105;106;107mThis text attempts to apply many colors in the same command. Note the colors are applied from left to right so only the right-most option of foreground cyan (SGR.36) and background bright white (SGR.107) is effective.\r\n");
    wprintf(L"\x1b[39mThis text has restored the foreground color only.\r\n");
    wprintf(L"\x1b[49mThis text has restored the background color only.\r\n");*/
    std::string line;
    char ch, name[50] = "Test.txt";
    std::string WordToFind;
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

    std::cout << "Insert word to find - ";
    std::cin >> WordToFind;

    SubString_Search(name, WordToFind);

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
