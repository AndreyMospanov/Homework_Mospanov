#include <iostream>
using namespace std;
/*Задание 2. Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). 
Необходимо создать третий массив минимально возможного размера, в котором 
нужно собрать общие элементы двух массивов без повторений. */
void CreateArr(int arr[], int arrLength)
{
    
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = rand() % 10;
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

bool Unique(int* A, int* C, int i, int m = 0)
{    
    for (int j = 0; j < i + m; j++)
    {        
        if (C[j] == A[i])
        {            
            return false;            
        }
    }
    return true;
}

void SumUniqArr(int* A, int* m, int* B, int* n, int* C, int* o)
{
    int index = 0;
    for (int i = 0; i < *o; i++)
    {
        if (i < *m)
        {  
            if (Unique(A, C, i))
            {
                *(C + index) = *(A + i);
                index++;
            }            
        }
        else
        {            
            if (Unique(B, C, i-*m, *m))
            {
                *(C + index) = *(B + i - *m);
                index++;
            }           
        }
    }
    *o = index;
}
int main()
{
    srand(time(NULL));
    int m, n, o;
    setlocale(0, "");
    cout << "Введите размер первого и второго массива\n";
    cin >> m >> n;
    o = m + n;
    int* A = new int[m];
    int* B = new int[n];
    int* C = new int[o];
    CreateArr(A, m);
    CreateArr(B, n);
    SumUniqArr(A, &m, B, &n, C, &o);
    PrintArr(A, m);
    PrintArr(B, n);
    delete[] A;
    delete[] B;
    PrintArr(C, o);
}
