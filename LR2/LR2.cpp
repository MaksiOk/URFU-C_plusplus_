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

    float m[N][N]{};
    float min = 0.0;
    float max = 0.0;
    
    void print_menu();
    int get_variant(int);

    float min_matrix(float(*)[N]);              //1
    float max_matrix(float(*)[N]);              //2
    float max_L(float(*)[N]);                   //3
    float max_U(float(*)[N]);                   //4
    float min_L(float(*)[N]);                   //5
    float min_U(float(*)[N]);                   //6
    float min_MainDiag(float(*)[N]);            //7
    float max_MainDiag(float(*)[N]);            //8
    float min_SecondaryDiag(float(*)[N]);       //9
    float max_SecondaryDiag(float(*)[N]);       //10
    float average_matrix(float(*)[N]);          //11
    float average_L(float(*)[N]);               //12
    float average_U(float(*)[N]);               //13
    float rows_sum(float(*)[N]);                //14
    float columns_sum(float(*)[N]);             //15
    float rows_min(float(*)[N]);                //16
    float columns_min(float(*)[N]);             //17
    float rows_max(float(*)[N]);                //18
    float columns_max(float(*)[N]);             //19
    float rows_average(float(*)[N]);            //20
    float columns_average(float(*)[N]);         //21
    float sum_L(float(*)[N]);                   //22
    float sum_U(float(*)[N]);                   //23
    float closest_to_average(float(*)[N], int); //24
    

    int i, j;
    int variant;

    srand(time(NULL)); 

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = rand() / 10.;
            //m[i][j] = MIN_VALUE + (m[i][j] / pow(10, 2)) * (MAX_VALUE - MIN_VALUE);
        }
    }
    
    //cout << max << endl;
    
    do {
        cout << endl;

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++)
                cout << setw(8) << setprecision(5) << m[i][j];
            cout << endl;
        }

        cout << endl;

        print_menu();

        variant = get_variant(25); // получаем номер выбранного пункта меню

        switch (variant) {
        case 1:
            min = min_matrix(m);
            cout << "Minimum of matrix: " << max;
            cout << endl;
            break;

        case 2:
            max = max_matrix(m);
            cout << "Maximum of matrix: " << max;
            cout << endl;
            break;

        case 3:
            max = max_L(m);
            cout << "Maximum of the lower triangular part of the matrix: " << max;
            cout << endl;
            break;

        case 4:
            max = max_U(m);
            cout << "Maximum of the upper triangular part of the matrix: " << max;
            cout << endl;
            break;

        case 5:
            max = min_L(m);
            cout << "Minimum of the lower triangular part of the matrix: " << max;
            cout << endl;
            break;

        case 6:
            max = min_U(m);
            cout << "Minimum of the upper triangular part of the matrix: " << max;
            cout << endl;
            break;

        case 7:
            max = min_MainDiag(m);
            cout << "Minimum of the main diagonal: " << max;
            cout << endl;
            break;
        case 8:
            max = max_MainDiag(m);
            cout << "Maximum of the main diagonal: " << max;
            cout << endl;
            break;

        case 9:
            max = min_SecondaryDiag(m);
            cout << "Minimum of the secondary diagonal: " << max;
            cout << endl;
            break;

        case 10:
            max = max_SecondaryDiag(m);
            cout << "Maximum of the secondary diagonal: " << max;
            cout << endl;
            break;

        case 11:
            max = average_matrix(m);
            cout << "Average of Matrix: " << max;
            cout << endl;
            break;

        case 12:
            max = average_L(m);
            cout << "Average of the lower triangular part of the matrix: " << max;
            cout << endl;
            break;

        case 13:
            max = average_U(m);
            cout << "Average of the upper triangular part of the matrix: " << max;
            cout << endl;
            break;

        case 14:
            max = rows_sum(m);

            break;

        case 15:
            max = columns_sum(m);

            break;

        case 16:
            max = rows_min(m);

            break;

        case 17:
            max = columns_min(m);

            break;

        case 18:
            max = rows_max(m);

            break;

        case 19:
            max = columns_max(m);

            break;

        case 20:
            max = rows_average(m);

            break;

        case 21:
            max = columns_average(m);

            break;

        case 22:
            max = sum_L(m);
            cout << "Sum of the lower triangular part of the matrix: " << max;
            cout << endl;
            break;

        case 23:
            max = sum_U(m);
            cout << "Sum of the upper triangular part of the matrix: " << max;
            cout << endl;
            break;

        case 24:

            max = closest_to_average(m, average_matrix(m));
            cout <<"Closest to average: " << max;
            cout << endl;
            break;
        }


        if (variant != 25)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 25);
    
}

//------------------------ 1. Минимум матрицы -------------------------------
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

//------------------------ 2. Максимум матрицы   ------------------------------
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

//------------------------ 3. Максимум нижнетреугольной части матрицы    --------------
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

//------------------------ 4. Максимум верхнетреугольной части матрицы   --------------
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

//------------------------ 5. Минимум нижнетреугольной части матрицы     --------------
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

//------------------------ 6. Минимум верхнетреугольной части матрицы    --------------
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

//------------------------ 7. Минимум главной диагонали матрицы   ------------------
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

//------------------------ 8. Максимум главной диагонали матрицы  ------------------
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

//------------------------ 9. Минимум главной диагонали матрицы   ------------------
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

//----------------------- 10. Максимум второстипенной диагонали матрицы   ----------
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

//----------------------- 11. Срденее арифметическое    ------------------
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

//----------------------- 12. Срденее арифметическое нижнетреугольной части матрицы    -----
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

//----------------------- 13. Срденее арифметическое верхнетреугольной части матрицы    -----
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

//----------------------- 14. Суммы строк матрицы    -----
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
        cout << "Sum of elements Row " << i << ":" << setw(8) << setprecision(5) << max << endl;
        max = 0;
    }
    
    return (0);
}

//----------------------- 15. Суммы столбцов матрицы    -----
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
        cout << "Sum of elements Column " << j << ":" << setw(8) << setprecision(5) << max << endl;
        max = 0;
    }

    return (0);
}

//----------------------- 16. Минимум строк матрицы    -----
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
        cout << "Minimum of Row " << i << ":" << setw(8) << setprecision(5) << min << endl;
        min = nm[i][j];
    }

    return (0);
}

//----------------------- 17. Минимум столбцов матрицы    -----
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
        cout << "Minimum of Column " << j << ":" << setw(8) << setprecision(5) << min << endl;
        min = nm[i][j];
    }

    return (0);
}

//----------------------- 18. Максимум строк матрицы    -----
float rows_max(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            if (nm[i][j] > max) max = nm[i][j];
        }
        cout << "Maximum of Row " << i << ":" << setw(8) << setprecision(5) << max << endl;
        max = nm[i][j];
    }

    return (0);
}

//----------------------- 19. Минимум столбцов матрицы    -----
float columns_max(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float min = nm[i][j];

    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++)
        {
            if (nm[i][j] < min) min = nm[i][j];
        }
        cout << "Maximum of column " << j << ":" << setw(8) << setprecision(5) << min << endl;
        min = nm[i][j];
    }

    return (0);
}

//----------------------- 20. Средне арифметическое строк матрицы    -----
float rows_average(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            max += nm[i][j];
        }
        max = max / N;
        cout << "Rows average" << j << ":" << setw(8) << setprecision(5) << max << endl;
        max = nm[i][j];
    }

    return (0);
}

//----------------------- 21. Среднеарифметическое столбцов матрицы    -----
float columns_average(float(*nm)[N]) {
    int i = 0;
    int j = 0;
    int c = -1;

    float max = nm[i][j];

    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++)
        {
            max += nm[i][j];
        }
        max = max / N;
        cout << "Column average " << j << ":" << setw(8) << setprecision(5) << max << endl;
        max = nm[i][j];
    }

    return (0);
}

//----------------------- 22. Сумма нижнетреугольной части матрицы    -----
float sum_L(float(*nm)[N]) {
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
    return max;
}

//----------------------- 23. Сумма верхнетреугольной части матрицы -----
float sum_U(float(*nm)[N]) {
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
    return max;
}

//----------------------- 24. Элемент наиболее близкий к среднеарифметическому -----
float closest_to_average(float(*nm)[N], int average) {
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
   

    float max = nm[i][j];

    float diff = nm[i][j]-average;             //переменная для разности

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++)
        {
            if ((max = nm[i][j] - average) < diff ) {
                diff = max;
            }
        }
    }
    return diff;
}


//--------- Вывод меню    -----
void print_menu() {
    system("cls"); // очищаем экран
    cout << "Operation with matrix" << endl;
    cout << "1. Minimum of matrix" << endl;
    cout << "2. Maxim of matrix" << endl;
    cout << "3. Print the highest price" << endl;
    cout << "4. Print the lowest price" << endl;
    cout << "5. Print the lowest price" << endl;
    cout << "6. Print the lowest price" << endl;
    cout << "7. Print the lowest price" << endl;
    cout << "8. Print the lowest price" << endl;
    cout << "9. Print the lowest price" << endl;
    cout << "10. Exit" << endl;
    cout << "11. Exit" << endl;
    cout << "12. Exit" << endl;
    cout << "13. Exit" << endl;
    cout << "14. Exit" << endl;
    cout << "15. Exit" << endl;
    cout << "16. Exit" << endl;
    cout << "17. Exit" << endl;
    cout << "18. Exit" << endl;
    cout << "19. Exit" << endl;
    cout << "20. Exit" << endl;
    cout << "21. Exit" << endl;
    cout << "22. Exit" << endl;
    cout << "23. Exit" << endl;
    cout << "24. Exit" << endl;
    cout << "25. Exit" << endl;
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
