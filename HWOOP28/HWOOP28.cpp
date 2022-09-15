/*Тема: STL часть 1 
Задание.
Написать программу формирования частотного словаря 
появления отдельных слов в некотором тексте. Обеспечить:
1. Чтение исходного текста из файла;
2. Вывод информации обо всех словах;
3. Вывод информации о наиболее часто встречающемся 
слове;
4. Запись результата в файл.
При разработке программы использовать словарь типа map.*/

#include <iostream>
#include <fstream>
#include <map>
#include <Windows.h> // для работы SetConsoleCP, SetConsoleOutputCP
using namespace std;

int main()
{    
    ifstream in;
    ofstream out;
    string path;
    string pathResult;
    string temp;
    int count;
    map<string, int> text;
    map<int, string> res;
    map<string, int> ::iterator it;
    map<int, string> ::iterator it2;

    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    setlocale(LC_ALL, "Rus"); 
    
    pathResult = "Result.txt";
    path = "Text.txt";

    //считываем файл и при обнаружении одинаковых слов(ключей) добавляем этому слову значение
    in.open(path);
    if (in.is_open())
    {
        while (in >> temp)
        {
            it = text.find(temp);
            if (it == text.end())
            {
                text.insert(make_pair(temp, 1));
            }
            else
            {
                it->second++;
            }            
        }
    }
    in.close();

    //переписываем результаты в другой map, чтобы отсортировать слова по частоте появления
    for (it = text.begin();it != text.end();it++)
    {
        res.insert(make_pair(it->second, it->first));
    }
    
    //выводим в файл
    out.open(pathResult);
    if (out.is_open())
    {
        out << "Частота появления слов:\n";
        for (it2 = --res.end(); it2 != --res.begin(); it2--)
        {
            if (it2->first == 1)
            {
                break;
            }
            out << "слово " << it2->second << " - " << it2->first << " раз\n";
        }
    }
    out.close();

    cout << "Программа завершена\n";
}