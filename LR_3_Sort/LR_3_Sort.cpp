// LR_3_Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>


using namespace std;



void printArray(int arr[], int size)
{
	int i;
	
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already 
		// in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

void quickSort(int* array, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = array[(i+j) / 2];
	int temp=0;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		quickSort(array, low, j);
	if (i < high)
		quickSort(array, i, high);
}

void minmaxSort(int arr[], int n) {
	int i;
	int imin, imax;
	imin = i = 0;
	imax = i = 0;

	for (i = 0; i < n - 1; i++) {
		imin = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[imin]) imin = j;
		}
		int t = arr[i];
		arr[i] = arr[imin];
		arr[imin] = t;
	}

}

void fillArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() / 10.;
	}
}

void print_menu() {
	system("cls"); // очищаем экран
	cout << "Operation with matrix" << endl;
	cout << "1. Mini-Max Sorting" << endl;
	cout << "2. Bubble Srting" << endl;
	cout << "3. Quick Sorting" << endl;
	cout << "4. Sorting by increase in even descending odd" << endl;
	cout << "5. Sorting by increase from N1 to N5" << endl;
	cout << "6. Sorting by descending from N1 to N5" << endl;
}

//--------- Получаем меню   -----
int get_variant(int count) {
	int variant;
	string s; // строка для считывания введённых данных
	getline(cin, s); // считываем строку                                                                    // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
		cout << "Incorrect input. Try again: ";                                             // выводим сообщение об ошибке
		getline(cin, s);                                                                    // считываем строку повторно
	}

	return variant;
}

int main()
{
	int mas[20]{};
	int variant = 0;
	int N = sizeof(mas) / sizeof(int);

	do {
		print_menu();

		cout << endl;

		fillArray(mas, N);
		cout << "Array of random numbers: ";
		printArray(mas, N);
		variant = get_variant(4);



		switch (variant) {
		case 1:
			minmaxSort(mas, N);
			cout << "Mini max Sorted: ";
			printArray(mas, N);
			break;
		case 2:
			bubbleSort(mas, N);
			cout << "Bubble Sorted: ";
			printArray(mas, N);
			break;
		case 3:
			quickSort(mas, 0, N-1);
			cout << "Quick Sorted: ";
			printArray(mas, N);
			break;
		case 4:
			quickSort(mas, 0, N);
			cout << "Sorting by increase in even descending odd: ";
			printArray(mas, N);
			break;
		case 5:
			quickSort(mas, 0, N);
			cout << "Sorting by increase from N1 to N5: ";
			printArray(mas, N);
			break;
		case 6:
			quickSort(mas, 0, N);
			cout << "Sorting by descending from N1 to N5 ";
			printArray(mas, N);
			break;
		}

	if (variant != 7)
		system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
	} while (variant != 7);

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
