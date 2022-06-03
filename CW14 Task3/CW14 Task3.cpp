#include <iostream>
using namespace std;
/*Задание 3. Дан массив: А[M] (M вводится с клавиатуры). 
Необходимо удалить из массива четные или нечетные значения. 
Пользователь вводит данные в массив, а также с помощью меню решает, что нужно удалить.*/
void CreateArr(int arr[], int& arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = rand() % 10;
    }
}

template <typename T>
void PrintArr(T arr[], int& n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n-----------------\n";
}
int Options()
{
    int option;
    cout << "Введите 1 или 2, чтобы удалить\nнечётные или чётные значения соответственно\n";
    cin >> option;
    try
    {
        if (option > 2)
        {
            throw "Неверно введённое число\n";
        }
    }
    catch (...)
    {

    }
    return option;
}
void DeleteElements(int* arr, int* size, int* changedArr)
{
    int option;
    int index = 0;
    option = Options();
    if (option == 1)
    {
        for (int i = 0; i < *size; i++)
        {
            if (arr[i] % 2 == 0)
            {                
                changedArr[index] = arr[i];
                index++;
            }
        }        
    }
    else if (option == 2)
    {
        for (int i = 0; i < *size; i++)
        {
            if (arr[i] % 2 == 1)
            {
                changedArr[index] = arr[i];
                index++;
            }
        }
    }    
    *size = index;
}
int main()
{
    srand(time(NULL));
    int m, option;
    setlocale(0, "");
    cout << "Введите размер массива\n";
    cin >> m;    
    int* A = new int[m];
    int* B = new int[0];
    CreateArr(A, m);
    PrintArr(A, m);
    DeleteElements(A, &m, B);      
    PrintArr(B, m);
}
