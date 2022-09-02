#include <iostream>
/*Реализуйте шаблонные функции для поиска максимума, минимума, сортировки массива, двоичного поиска в массиве, замены элемента массива на переданное значение*/
using namespace std;
template<typename T>
T getMax(T* arr, int length)
{
	T max = arr[0];
	for (int i = 0; i < length; i++)
	{
		max = arr[i] > max ? (arr[i]) : max;
	}
	return max;
}

template<typename T>
T getMin(T* arr, int length)
{
	T min = arr[0];
	for (int i = 0; i < length; i++)
	{
		min = arr[i] < min ? (arr [i]) : min;
	}
	return min;
}

template<typename T>
void Sort(T* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if(arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

template<typename T>
void ChangeVar(T* arr, int index, T value)
{
	arr[index] = value;
}

template<typename T>
void ShowArr(T* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<typename T> 
int binarySearch(T* arr, int length, T search)
{
	int left = 0;
	int right = length - 1;
	int middle;
	do
	{
		middle = (left + right) / 2;
		if (arr[middle] == search)
			return middle;

		if (arr[middle] < search)
			left = middle + 1;
		else
			right = middle - 1;
	} while (left <= right);
	return -1;
}

int main()
{
	const int length = 11;
	int arr[length]{58, 35, 64, 6, 2, 8, 4, 9, 99, 43, 32 };
	cout << "max = " << getMax(arr, length) << endl;
	cout << "min = " << getMin(arr, length) << endl;
	Sort(arr, length);
	ShowArr(arr, length);
	cout << "index of number 64 in arr is " << binarySearch(arr, length, 64) << endl;
	ChangeVar(arr, 0, 7);
	ShowArr(arr, length);

}
