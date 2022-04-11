#include <iostream>
#include <time.h>

using namespace std;
/*Задание 1. Написать перегруженные функции (int, double,
char) для выполнения следующих задач:
■ Инициализация квадратной матрицы;
■ Вывод матрицы на экран;
■ Определение максимального и минимального элемента
на главной диагонали матрицы;
■ Сортировка элементов по возрастанию отдельно для
каждой строки матрицы*/
const int arrLength = 3;

void DefineArr(int arr[arrLength][arrLength])
{
	srand(time(0));
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			arr[i][j] = rand() % 100;			
		}		
	}
}

void DefineArr(double arr[arrLength][arrLength])
{
	srand(time(0));
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			arr[i][j] = (double)rand() / 10;			
		}		
	}
}

void DefineArr(char arr[arrLength][arrLength])
{
	srand(time(0));
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			arr[i][j] = (char)rand() % 127;			
		}		
	}
}

template <typename T>		
void PrintArr(T arr[arrLength][arrLength])
{
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{			
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------\n";
}

template <typename T>
T FindMax(T arr[arrLength][arrLength])
{
	T max = arr[0][0];
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = i; j <= i; j++)
		{
			max = max > arr[i][j] ? max : arr[i][j];
		}
	}
	return max;
}

template <typename T>
T FindMin(T arr[arrLength][arrLength])
{
	T min = arr[0][0];
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = i; j <= i; j++)
		{
			min = min < arr[i][j] ? min : arr[i][j];
		}
	}
	return min;
}

template <typename T>
void SortArr(T arr[arrLength][arrLength])
{	
	T temp;
	for (int i = 0; i < arrLength; i++)
	{
		for (int k = 0; k < arrLength; k++)
		{
			for (int j = 0; j < arrLength - 1; j++)
			{
				if (arr[i][j] > arr[i][j + 1])
				{
					swap(arr[i][j], arr[i][j + 1]);
				}
			}
		}		
	}	
}

int main()
{
	int arrInt[arrLength][arrLength];
	double arrDouble[arrLength][arrLength];
	char arrChar[arrLength][arrLength];

	DefineArr(arrInt);
	DefineArr(arrDouble);
	DefineArr(arrChar);

	PrintArr(arrInt);
	PrintArr(arrDouble);
	PrintArr(arrChar);

	cout << "max int = " << FindMax(arrInt) << endl;
	cout << "max double = " << FindMax(arrDouble) << endl;
	cout << "max char = " << FindMax(arrChar) << endl;
	
	cout << "min int = " << FindMin(arrInt) << endl;
	cout << "min double = " << FindMin(arrDouble) << endl;
	cout << "min char = " << FindMin(arrChar) << endl;

	SortArr(arrInt);
	SortArr(arrDouble);
	SortArr(arrChar);

	PrintArr(arrInt);
	PrintArr(arrDouble);
	PrintArr(arrChar);
}

