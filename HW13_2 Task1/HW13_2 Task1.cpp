#include <iostream>
using namespace std;
/*Задание 1. Используя два указателя на массив целых чисел, 
скопировать один массив в другой. Использовать в программе 
арифметику указателей для продвижения по массиву, а также оператор разыменования. */
const int n = 5; // array length
template <typename T>
void PrintArr(T arr[n])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void CopyArr(int* orig, int* copy)
{
    for (int i = 0; i < n; i++)
    {
        *(copy + i) = *(orig + i);       
    }
}
int main()
{ 
    int arr1[n] = { 0,1,2,3,4 };
    int arr2[n];
    int* arr1Ptr = arr1;
    int* arr2Ptr = arr2;
    CopyArr(arr1Ptr, arr2Ptr);
    PrintArr(arr2);
}
