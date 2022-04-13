#include <iostream>
#include <time.h>
using namespace std;
/*Задание 1. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного размера, в котором нужно 
собрать элементы обоих массивов. */
void CreateArr(int arr[], int arrLength)
{    
    for (int i = 0; i < arrLength; i++)
    {        
        arr[i] = rand() % 100;        
    }
}

template <typename T>
void PrintArr(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n-----------------\n";
}
void SumArr(int* A, int m, int* B, int n, int* C, int o)
{
    for (int i = 0; i < o; i++)
    {
        if (i < m)
        {
            *(C + i) = *(A + i);
        }
        else
        {
            *(C + i) = *(B + i - m);
        }
    }
}
int main()
{    
    srand(time(NULL));
    int m, n, o;
    setlocale(0,"");
    cout << "Введите размер первого и второго массива\n";
    cin >> m >> n;
    o = m + n;
    int* A = new int[m];
    int* B = new int[n];
    int* C = new int[o];
    CreateArr(A, m);
    CreateArr(B, n);
    SumArr(A, m, B, n, C, o);
    PrintArr(A, m);
    PrintArr(B, n);
    delete[] A;
    delete[] B;
    PrintArr(C, o);
}
