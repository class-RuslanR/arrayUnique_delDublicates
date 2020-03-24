#include "pch.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void funcEnter(int *arr, int s)
{
	for (int i = 0; i < s; ++i)
	{
		arr[i] = rand() % s;
	}
}

void funcShow(int *arr, int s)
{
	for (int i = 0; i < s; ++i)
	{
		cout << arr[i] << "   ";
	}
	cout << "\n";
}
int arrayUnique(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int count = 1; count < size; ++count)
		{
			if (array[i] == array[i + count])
			{
				for (int j = i + count; j < size; ++j)
				{
					array[j] = array[j + 1];
				}
				--size;
			}
		}
	}
	return size;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size;
	cout << "Введите размерность массива: ";
	cin >> size;
	int *array = new int[size];
	funcEnter(array, size);
	cout << "Массив до удаления элементов-дубликатов:" << endl;
	funcShow(array, size);
	int newSize = arrayUnique(array, size);
	cout << "Новый размер массива: " << newSize << endl;
	delete[] array;
	system("pause");
	return 0;
}
