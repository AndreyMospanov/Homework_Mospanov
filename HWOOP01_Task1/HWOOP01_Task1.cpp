#include <iostream>
#include "Fraction.h"
using namespace std;

/*Тема: Введение в объектно-ориентированное программирование.
Задание.
Реализуйте класс Дробь. Необходимо хранить числитель 
и знаменатель в качестве переменных-членов. Реализуйте 
функции-члены для ввода данных в переменные-члены, 
для выполнения арифметических операций (сложение, 
вычитание, умножение, деление, и т.д.)*/

void Action(int choice, Fraction f1, Fraction f2)
{
    Fraction result;
    switch (choice)
    {
    case 1:
    {
        result = f1.Sum(f2); 
        break;
    }
    case 2:
    {
        result = f1.Subtraction(f2);
        break;
    }
    case 3:
    {
        result =  f1.Multiply(f2);
        break;
    }
    case 4:
    {
        result = f1.Division(f2);
        break;
    }
    default:
        break;
    }

    cout << "result: ";
    result.Print();
}

int main()
{
    while (true)
    {
        Fraction f1;
        Fraction f2;
        int temp;
        cout << "Enter Fractions values\n";
        cout << "Fraction 1:\n numerator: ";
        cin >> temp;
        f1.setNumerator(temp);
        cout << "denominator: ";
        cin >> temp;
        f1.setDenominator(temp);

        cout << "Fraction 2:\n numerator: ";
        cin >> temp;
        f2.setNumerator(temp);
        cout << "denominator: ";
        cin >> temp;
        f2.setDenominator(temp);

        do
        {
            cout << "Choose mathematical action with fractions\n";
            cout << "1. Sum\n2. Subtraction\n3. Multiply\n4. Division\n";
            cin >> temp;
            if (temp < 1 || temp > 4)
            {
                cout << " value is not correct\n";
            }
        } while (temp < 1 || temp > 4);
        
        Action(temp, f1, f2);

        cout << "do you want to continue? yes - 1, no - any number\n";
        cin >> temp;
        if (temp != 1)
            break;
        system("cls");
    }
}
