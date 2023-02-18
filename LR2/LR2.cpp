// LR2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string>

#define N 5

using namespace std;



int main()
{
    const int MAX_N = 10;       // максимально-допустимая размерность матрицы
    const int MIN_VALUE = -5;   // максимальное значение элементов матрицы
    const int MAX_VALUE = 5;    // минимальное значение

    float m[N][N];
    float min = 0.0;
    float max = 0.0;

    float min_matrix(float(*)[N]);
    float max_matrix(float(*)[N]);
    float max_L(float(*)[N]);
    float max_U(float(*)[N]);
    float min_L(float(*)[N]);
    float min_U(float(*)[N]);
    float min_MainDiag(float(*)[N]);
    float max_MainDiag(float(*)[N]);
    float min_SecondaryDiag(float(*)[N]);
    float max_SecondaryDiag(float(*)[N]);
    float average_matrix(float(*)[N]);
    float rows_sum(float(*)[N]);
    float columns_sum(float(*)[N]);
    float rows_min(float(*)[N]);
    float columns_min(float(*)[N]);

    

    int i, j;
    int variant;

    

    srand(time(NULL)); 

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = rand() / 10.;
            //m[i][j] = MIN_VALUE + (m[i][j] / pow(10, 2)) * (MAX_VALUE - MIN_VALUE);
        }
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << setw(8) << setprecision(5) << m[i][j];
            cout << endl;
    }

    max = columns_min(m);
    //cout << max << endl;
    /*
    do {
        print_menu();

        variant = get_variant(5); // получаем номер выбранного пункта меню

        switch (variant) {
        case 1:
            min = min_matrix(m);
            cout << min;
            cout << endl;
            break;

        case 2:
            max = max_matrix(m);
            cout << max;
            cout << endl;
            break;

        case 3:
            print_highest(goods, size);
            break;

        case 4:
            print_lowest(goods, size);
            break;
        }

        if (variant != 5)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 5);
    */
}

//---------------------- Минимум матрицы -------------------------------
float min_matrix(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    float min = nm[i][j];

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            if (nm[i][j] < min) min = nm[i][j];
        }
    return min;
}

//---------------------- Максимум матрицы   ------------------------------
float max_matrix(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    float max = nm[i][j];

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            if (nm[i][j] > max) max = nm[i][j];
        }
    return max;
}

//-------------- Максимум нижнетреугольной части матрицы    --------------
float max_L(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        c++;
        for (j = 0; j < c; j++)
        {
            if (nm[i][j] > max) max = nm[i][j];
        }
    }
    return max;
}

//-------------- Максимум верхнетреугольной части матрицы   --------------
float max_U(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        c++;
        for (j = c; j < N; j++)
        {
            if (nm[i][j] > max) max = nm[i][j];
        }
    }
    return max;
}

//-------------- Минимум нижнетреугольной части матрицы     --------------
float min_L(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float min = nm[i][j];

    for (i = 0; i < N; i++) {
        c++;
        for (j = 0; j < c; j++)
        {
            if (nm[i][j] < min) min = nm[i][j];
        }
    }
    return min;
}

//-------------- Минимум верхнетреугольной части матрицы    --------------
float min_U(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float min = nm[i][j];

    for (i = 0; i < N; i++) {
        c++;
        for (j = c; j < N; j++)
        {
            if (nm[i][j] < min) min = nm[i][j];
        }
    }
    return min;
}

//----------------- Минимум главной диагонали матрицы   ------------------
float min_MainDiag(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    float min = nm[i][j];

    for (i = 0; i < N; i++) {
          if (nm[i][j] < min) min = nm[i][j];
          j++;
    }
    return min;
}

//----------------- Максимум главной диагонали матрицы  ------------------
float max_MainDiag(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        if (nm[i][j] > max) max = nm[i][j];
        j++;
    }
    return max;
}

//----------------- Минимум главной диагонали матрицы   ------------------
float min_SecondaryDiag(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    float min = nm[i][j];

    for (i = 4; i > 0; i--) {
        if (nm[i][j] < min) min = nm[i][j];
        j++;
    }
    return min;
}

//----------------- Максимум второстипенной диагонали матрицы   ----------
float max_SecondaryDiag(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    float max = nm[i][j];

    for (i = 4; i > 0; i--) {
        if (nm[i][j] > max) max = nm[i][j];
        j++;
    }
    return max;
}

//--------------------------- Срденее арифметическое    ------------------
float average_matrix(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            max += nm[i][j];
        }
    }
    max = max/(N * N);
    return max;
}

//--------- Срденее арифметическое нижнетреугольной части матрицы    -----
float average_L(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        c++;
        for (j = 0; j < c; j++)
        {
            max += nm[i][j];
        }
    }
    max = max / (N * N);
    return max;
}

//--------- Срденее арифметическое верхнетреугольной части матрицы    -----
float average_U(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        c++;
        for (j = c; j < N; j++)
        {
            max += nm[i][j];
        }
    }
    max = max / (N * N);
    return max;
}

//--------- Суммы строк матрицы    -----
float rows_sum(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            max += nm[i][j];
        }
        cout << "Row " << i << ":" << setw(8) << setprecision(5) << max << endl;
        max = 0;
    }
    
    return (0);
}

//--------- Суммы столбцов матрицы    -----
float columns_sum(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++)
        {
            max += nm[i][j];
        }
        cout << "Column " << j << ":" << setw(8) << setprecision(5) << max << endl;
        max = 0;
    }

    return (0);
}

//--------- Минимум строк матрицы    -----
float rows_min(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float min = nm[i][j];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            if (nm[i][j] < min) min = nm[i][j];
        }
        cout << "Row " << i << ":" << setw(8) << setprecision(5) << min << endl;
        min = nm[i][j];
    }

    return (0);
}

//--------- Минимум столбцов матрицы    -----
float columns_min(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float min = nm[i][j];

    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++)
        {
            if (nm[i][j] < min) min = nm[i][j];
        }
        cout << "Column " << j << ":" << setw(8) << setprecision(5) << min << endl;
        min = nm[i][j];
    }

    return (0);
}

//--------- Вывод меню    -----
void print_menu() {
    system("cls"); // очищаем экран
    cout << "Operation with matrix" << endl;
    cout << "1. Minimum of matrix" << endl;
    cout << "2. Maxim of matrix" << endl;
    cout << "3. Print the highest price" << endl;
    cout << "4. Print the lowest price" << endl;
    cout << "5. Exit" << endl;
    cout << ">";
}

//--------- Получаем меню   -----
int get_variant(int count) {
    int variant;
    string s;                                                                               // строка для считывания введённых данных
    getline(cin, s);                                                                        // считываем строку

                                                                                            // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (scanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        cout << "Incorrect input. Try again: ";                                             // выводим сообщение об ошибке
        getline(cin, s);                                                                    // считываем строку повторно
    }

    return variant;
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
