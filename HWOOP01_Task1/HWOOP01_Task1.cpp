#include <iostream>
#include "Fraction.h"
using namespace std;

void Action(int choice, Fraction f1, Fraction f2)
{
    Fraction result;
    switch (choice)
    {
    case 1:
    {
        result = f1.Summand(f2);        
    }
    case 2:
    {
        result = f1.Subtraction(f2);
    }
    case 3:
    {
        result =  f1.Multiply(f2);
    }
    case 4:
    {
        result = f1.Division(f2);
    }
    default:
        break;
    }

    cout << "result: " << result.getNumerator() << "/" << result.getDenominator() << endl;
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
        cout << "\ndenominator: ";
        cin >> temp;
        f1.setDenominator(temp);

        cout << "Fraction 2:\n numerator: ";
        cin >> temp;
        f2.setNumerator(temp);
        cout << "\ndenominator: ";
        cin >> temp;
        f2.setDenominator(temp);

        do
        {
            cout << "Choose mathematical action with fractions\n";
            cout << "1. Summand\n2. Subtraction\n 3. Multiply\n 4. Division\n";
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
    }
}
