#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
/*Задание 3. Написать игру «Быки и коровы». Программа
«загадывает» четырёхзначное число и играющий должен
угадать его. После ввода пользователем числа программа
сообщает, сколько цифр числа угадано (быки) и сколько
цифр угадано и стоит на нужном месте (коровы). После
отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток. В программе
необходимо использовать рекурсию.*/
void DefineNum(int arr[4])
{ 
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        arr[i] = rand() % 9;
        //cout << arr[i];
    }
}
int CowBullsLogic(int num, int arr[], int count = 0)
{
    int cows = 0;
    int bulls = 0;
    int userNum[4];
    for (int i = 3; i >= 0; i--)
    {
        userNum[i] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < 4; i++)
    {        
        for (int j = 0; j < 4; j++)
        {
            if (arr[i] == userNum[j] && i == j)
            {                
                cows++;                
            }            
            else if (arr[i] == userNum[j])
            {
                bulls++;
            }
        }
    }
    cout << "Быки = " << bulls << ", Коровы = " << cows << endl;
    count++;
    if (cows != 4)
    {
        cout << "Введите четырёхзначное число\n";
        cin >> num;
        CowBullsLogic(num, arr, count);
    }
    else
    {
        return count;
    }        
}
void ParseNum(int num, int userNum[])
{
    for (int i = 3; i >= 0; i--)
    {
        userNum[i] = num % 10;
        num /= 10;
    }
}
int NoCycleLogic( int num, int arr[], int count = 0)
{    
    

}
int main()
{
    setlocale(0, "");
    int arr[4];
    int userNum[4];
    int num, bulls, cows;    

    DefineNum(arr);
    cout << "\nУгадайте четырёхзначное число\n";
    /*cin >> num;
    cout << "\nУ вас было "<< CowBullsLogic(num, arr) <<" попыток";*/
    cout << "\nУ вас было "<< NoCycleLogic(num, arr) <<" попыток";
    while (cows != 4) 
    {
        bulls = 0;
        cows = 0;
        cout << "Введите четырёхзначное число\n";
        cin >> num;
        ParseNum(num, userNum);
        CowBullsLogic(num, arr);
    }
}

