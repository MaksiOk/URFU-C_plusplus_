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
#include <regex>

std::string PathWithLabels(std::string srcPath, std::string postfix) {
    reverse(srcPath.begin(), srcPath.end());
    std::string strPathWithOldLabels;
    if (srcPath.find('.') != std::string::npos & srcPath.find('.') < srcPath.length() - 2) {
        std::string format = srcPath.substr(0, srcPath.find('.'));
        std::string baseName = srcPath.substr(srcPath.find('.') + 1, srcPath.length());;
        reverse(format.begin(), format.end());
        reverse(baseName.begin(), baseName.end());
        std::cout << "format = " << format << std::endl;
        std::cout << "baseName = " << baseName << std::endl;
        strPathWithOldLabels = baseName + "_" + postfix + "." + format;
        std::cout << "strPathWithLabel = " << strPathWithOldLabels << std::endl;
    }
    else {
        reverse(srcPath.begin(), srcPath.end());
        strPathWithOldLabels = srcPath + "_" + postfix;
        std::cout << "new FILE with label = " << strPathWithOldLabels << std::endl;
    }
    return strPathWithOldLabels;
}

void CreateFileForTaskFour(std::string srcPath, std::string dstFileName, int countOfString) {
    std::ifstream inputFile(srcPath);
    std::ofstream rezultFile(dstFileName);
    std::string line;
    int numberOfString = 1;
    if (inputFile) {
        while (countOfString--) {
            getline(inputFile, line, char(0));
            rezultFile << "-" << numberOfString++ << "-\n" << line << "\f\n";
        }
    }
}

//Считает непечатемые символы
int Count_Empty(char* name) { 
    int space = 0;
    char ch;
    std::ifstream in(name);     //открытие

    while (in.get(ch))
    {
        if (ch < 33) space++;
    }
    in.close();
    return space;
}

//Считает печатемые символы
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

//Ищет и подсвечивает подстроку в строке
void SubString_Search(char* name, std::string WordToFind) {
    system("cls");
    std::string line;
    std::ifstream in(name); // окрываем файл для чтения
    size_t substring_length;
    int NumOfChar = WordToFind.length();
   
    //std::cout << NumOfChar << std::endl;
    if (in.is_open()) {
        while (getline(in, line)) {
            int index = 0;
            while ((substring_length = line.find(WordToFind, index)) != std::string::npos) {
                //std::cout << substring_length << std::endl;
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


void PageNumberReverse(std::string name) {
    std::string srcPath_old = PathWithLabels(name, "old");
    rename(name.c_str(), srcPath_old.c_str());
    std::ifstream input(srcPath_old);
    std::ofstream output(name, std::ios::app);
    std::string line;
    std::cmatch result;
    std::regex regular("([\\n]?-)""([\\d]+)""(-\\n)""([.|\\s|\\w|\\S|\\W]*)");

    if (input) {  //если поток открылся без ошибок, то true
        while (getline(input, line, '\f')) {
            if (regex_match(line.c_str(), result, regular)) {
                std::cout << "Regex done" << std::endl;
                for (int i = 0; i < result.size(); ++i) {
                    std::cout << "I= " << i << " result: " << result[i] << std::endl;
                }
                output << result[4] << '\n' << result[2] << "\n\f\n";

            }
            else {
                std::cout << "\nRegex didn't work\n";
            }
        }
    }
}

void Encoder(std::string postfixForNewFile) {
    std::string path;
    std::string key;
    std::cout << "Insert File Name to Encode";
    std::cin >> path;
    std::ifstream inputFile(path);
    std::string line;
    if (inputFile) {  //если поток открылся без ошибок, то true
        std::cout << "File Load" << std::endl;
    }
    else {
        std::cout << "can't load file" << std::endl;
    }
    std::cout << "Insert key:" << std::endl;
    std::cin >> key;

    std::ofstream encryptedFile(PathWithLabels(path, postfixForNewFile));
    encryptedFile.setf(std::ios::app);
    int x = 3;
    getline(inputFile, line, char(0));
    int index = 0;
    //char k = key[index];
    for (auto alpha : line) {
        if (index < key.length()) {
            int charCode = int(alpha) ^ int(key[index++]);
            encryptedFile << char(charCode);


        }
        else {
            index = 0;
            int charCode = int(alpha) ^ int(key[index++]);
            encryptedFile << char(charCode);
        }
    }
    encryptedFile.close();


}


int main(){
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
    char ch = 0, name[50] = "Test.txt";
    std::string WordToFind;
    /*FILE* in;
    std::cout << "Open File Test.txt" << std::endl;
    //std::cin >> name;*/
   
    std::ifstream in(name); // окрываем файл для чтения
    if (in.is_open()){
        while (getline(in, line)){
            std::cout << line << std::endl;
        }
    }
    in.close();             // закрываем файл

    std::cout << "Empty symbols - ";
    std::cout << Count_Empty(name) << std::endl;
    std::cout << "Not Empty symbols - ";
    std::cout << Count_Not_Empty(name) << std::endl;

    //std::cout << "Insert word to find - ";
    //std::cin >> WordToFind;

    //SubString_Search(name, WordToFind);
    //CreateFileForTaskFour(name, "testi.txt", 5);

    //PageNumberReverse("testi.txt");
    Encoder("Coded");

    /*if ((in = fopen(name, "r")) == NULL) {
        cout << "File didn't open" << endl;
    } else{
        while (!feof(in)) {
            ch = getc(in);
            putchar(ch);
        }
    }*/
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
