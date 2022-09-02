#include <iostream>
#include "Komplex.h"
using namespace std;
/*Домашнее задание №6(2)
Используя перегрузку операторов, реализуйте в классе арифметические операции для работы с комплексными числами +,-,*,/ */
void Action(int choice, Komplex num1, Komplex num2)
{
    Komplex result;
    switch (choice)
    {
    case 1:
    {
        result = num1 + num2;
        break;
    }
    case 2:
    {
        result = num1 - num2;
        break;
    }
    case 3:
    {
        result = num1 * num2;
        break;
    }
    case 4:
    {
        result = num1 / num2;
        break;
    }
    default:
        break;
    }

    cout << "result: " << result << endl;
    
}
int main()
{
    while (true)
    {
        Komplex num1;
        Komplex num2;
        double temp;
        cout << "Enter Komplex values\n";
        cout << "Komplex 1:\n real: ";
        cin >> temp;
        num1.Real(temp);
        cout << "imaginary: ";
        cin >> temp;
        num1.Imaginary(temp);

        cout << "Komplex 2:\n real: ";
        cin >> temp;
        num2.Real(temp);
        cout << "imaginary: ";
        cin >> temp;
        num2.Imaginary(temp);

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

        Action(temp, num1, num2);

        cout << "do you want to continue? yes - 1, no - any number\n";
        cin >> temp;
        if (temp != 1)
            break;
        system("cls");
    }
}