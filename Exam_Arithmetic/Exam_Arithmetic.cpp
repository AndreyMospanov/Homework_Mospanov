/*Создайте приложение для подсчета арифметического выражения пользователя.
Пользователь вводит с клавиатуры некоторое арифметическое выражение. Выражение может содержать: (), +, -, *, /.
Приложение рассчитывает результат выражения с учетом скобок, приоритетов. Результат отображается на экране.
Например, если пользователь ввел: 5 * 2 + 1 Результат: 11 Если пользователь ввел: 5 * (2 + 1) Результат: 15*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T operation(T a, char c, T b)
{
    switch (c)
    {
    case '+':
    {
        return a + b;
    }
    case '-':
    {
        return a - b;
    }
    case '*':
    {
        return a * b;
    }
    case '/':
    {
        return a / b;
    }
    default:
        break;
    }
}

int main()
{
    string input;
    vector<int> nums;
    vector<char> signs;
    bool lastWasNum = false;           //показывает был ли предыдущий член input[i] цифрой
    int temp;
    cout << "Enter arithmetic expression\n";    
    getline(cin, input);

    //создаём базу из чисел и знаков
    for (int i = 0; i < input.size(); i++)
    {
        temp = (int)(input[i]);       
        if (temp > 47 && temp < 58 && lastWasNum == false)
        {
            nums.push_back(temp - 48);
            lastWasNum = true;
        }
        else if (temp > 47 && temp < 58 && lastWasNum == true)
        {            
            nums[nums.size() - 1] *= 10;
            nums[nums.size() - 1] += temp - 48;            
        }
        else
        {
            if (input[i] != ' ')
            {
                //сразу же избавляемся от скобок
                if (input[i] == ')')
                {
                    while (signs[signs.size() - 1] != '(')
                    {                        
                        if (signs.at(signs.size() - 2) != '*' || signs.at(signs.size() - 2) != '/')
                        {                            
                            temp = operation(nums[nums.size() - 2], signs[signs.size() - 1], nums[nums.size() - 1]);                            
                            nums.pop_back();
                            nums.pop_back();
                            signs.pop_back();
                            nums.push_back(temp);
                        }
                    }
                    signs.pop_back();
                }
                else
                {
                    signs.push_back(input[i]);
                }                
            }            
            lastWasNum = false;
        }               
    }    
    
    //используем входные данные
    
    //решаем операции * и /
    for (int i = 0; i < signs.size(); i++)
    {
        if (signs[i] == '*' || signs[i] == '/')
        {
            temp = operation(nums[i], signs[i], nums[i + 1]);
            
            if (i > 0 && signs[i - 1] == '+')
            {
                signs.push_back('+');
            }
            else if (i > 0 && signs[i - 1] == '-')
            {
                signs.push_back('-');
            }

            signs.erase(signs.begin() + i);
            signs.erase(signs.begin() + (i - 1));
            nums.erase(nums.begin() + i + 1);
            nums.erase(nums.begin() + i);            
            nums.push_back(temp);
        }

    }

    while (signs.size() != 0)
    { 
        for (int i = signs.size() - 1; i >= 0; i--)
        {            
            if (i == 0)
            {
                temp = operation(nums[nums.size() - 2], signs[i], nums[nums.size() - 1]);
                nums.pop_back();
                nums.pop_back();
                signs.pop_back();                
                nums.push_back(temp);
                break;
            }
            else //if (signs[i - 1] != '*' && signs[i - 1] != '/')
            {
                temp = operation(nums[nums.size() - 2], signs[i], nums[nums.size() - 1]);                
                nums.pop_back();
                nums.pop_back();
                signs.pop_back();                
                nums.push_back(temp);
            }      
        }
    }

    cout << "result = " << nums[0];
}
