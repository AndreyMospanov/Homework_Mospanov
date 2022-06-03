#include <iostream>
using namespace std;
/*Задание 2. Используя указатель на массив целых чисел, 
изменить порядок следования элементов массива на противоположный. 
Использовать в программе арифметику указателей для продвижения по массиву, 
а также оператор разыменования.*/
void SwapNums(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ReverseArr(int* arr, int size)
{
    int right = size - 1;
    for (int left = 0; left < right; left++ )
    {
        SwapNums(arr + left, arr + right);        
        right--;
    }
}

template <typename T>
void PrintArr(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    const int size = 5;
    int arr[size] = { 0,1,2,3,4 };
    int* ptr = arr;
    ReverseArr(ptr, size);
    PrintArr(arr, size);
}
