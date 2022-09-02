#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
/*есть строка символов, с окончанием ;
Скобки: фигурные, круглые и квадратные
проверить корректность */
bool ScobesCorrect(char previous, char closeScobe)
{
    switch (previous)
    {
    case '{':
    {
        if (closeScobe != '}')
        {
            cout << "Error: " << "} expected ";
            return false;
        }
        else
            return true;
        break;
    }
    case '(':
    {
        if (closeScobe != ')')
        {
            cout << "Error: " << ") expected ";
            return false;
        }
        else
            return true;
        break;
    }
    case '[':
    {
        if (closeScobe != ']')
        {
            cout << "Error: " << "] expected ";
            return false;
        }
        else
            return true;
        break;
    }
    default:
        break;
    }
}

void CheckCorrect(string input)
{
    Stack st;
    cout << "checking correct of string: ";
    cout << input << endl;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '{' || input[i] == '(' || input[i] == '[')
            st.Push(input[i]);
        else if (input[i] == '}' || input[i] == ')' || input[i] == ']')
        {
            if (ScobesCorrect(st.Peek(), input[i]))
            {
                st.Pop();
            }
            else
            {
                cout << "  after " << st.Peek() << " at position " << i << endl;
            }
        }
    }
    if (st.isEmpty())
    {
        cout << "string is correct\n\n";
    }
}

int main()
{
    string input1 = "({x - y - z}*[x + 2y] - (z + 4x));";
    string input2 = "([x - y - z}*[x + 2y) - {z + 4x)].";
    CheckCorrect(input1);
    CheckCorrect(input2);
    system("pause");
}
