#include <iostream>
using namespace std;
/*Задание 1. Написать рекурсивную функцию нахождения
степени числа.*/
int Power(int num, int power)
{
    if (power == 0)
    {
        return 1;
    }
    return num * Power(num, power - 1);
}

int main()
{
    int num, power;
    cout << "Enter num ";
    cin >> num;
    cout << "\nEnter power ";
    cin >> power;
    cout <<"Result = " <<Power(num, power) << endl;
}

