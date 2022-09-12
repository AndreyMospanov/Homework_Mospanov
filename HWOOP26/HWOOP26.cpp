/*Тема: Потоки 
Задание.
Создать класс СПРАВОЧНИК со следующими полями:
1. Название фирмы;
2. Владелец;
3. Телефон;
4. Адрес;
5. Род деятельности.
Реализовать следующие возможности: 
1. Поиск по названию;
2. Поиск по владельцу; 
3. Поиск по номеру телефона; 
4. Поиск по роду деятельности; 
5. Показ всех записей и добавление. 
Вся информация, должна сохранятся в файле, должна 
быть реализована возможность добавления новых данных.*/
#include <iostream>
#include "Notebook.h"
#include "string"
//#include "HWOOP26.h"
using namespace std;

void Action(Notebook& nb, int choice)
{
    switch (choice)
    {
    case 1:
    {
        nb.Print();
        break;
    }
    case 2:
    {
        string name;
        string owner;
        string phone;
        string adress;
        string typeOfActivity;

        cout << "введите имя: ";
        cin.ignore(1024, '\n');
        getline(cin, name, '\n');

        cout << "введите владельца: ";
        getline(cin, owner, '\n');

        cout << "введите телефонный номер: ";
        //cin.ignore(1024, '\n');
        getline(cin, phone,'\n');

        cout << "введите адрес: ";
        //cin.ignore(1024, '\n');
        getline(cin, adress,'\n');

        cout << "введите род деятельности: ";
        //cin.ignore(1024, '\n');
        getline(cin, typeOfActivity,'\n');
        
        nb.Add(Note (name, owner, phone, adress, typeOfActivity));
        cout << "Запись добавлена\n";
        break;
    }

    case 3:
    {
        int num;
        cout << "Выберите номер записи, которую надо удалить\n\n";
        nb.Print();
        cin >> num;
        num--;
        nb.Erase(num);
        break;
    }
    case 4:
    {
        int num;
        string search;
        cout << "По какому параметру искать?\n";
        cout << "1. Поиск по названию\n2. Поиск по владельцу\n3. Поиск по номеру телефона\n4. Поиск по адресу\n5. Поиск по роду деятельности \n";
        try
        {
            cin >> num;            
            if (num > 5)
                throw num;

            cout << "Введите поисковый запрос\n";
            cin.ignore(1024, '\n');
            getline(cin, search);            
            nb.Find(search, num);
        }
        catch (int)
        {
            cout << "Неверный выбор!\n";
        }
        break;
    }

    case 5:
    {
        nb.Save();
    }
    default:
        
        break;
    }

    system("pause");
    system("cls");
}

int main()
{
    setlocale(0, "");
    Notebook nb;
    int choice;
    cout << "Выберите действие из меню\n";
    do
    {
        cout << "1. Показать список\n2. Добавить запись\n3. Удалить запись\n4. Поиск записи\n5. Сохранить\n0. Выход\n";
        try
        {
            cin >> choice;
            
            if (choice < 0 || choice > 5)
            {
                throw choice;
            }

            Action(nb, choice);
        }
        catch (int)
        {
            cout << "Неверный выбор\n";
            system("pause");
        }        
        system("cls");
    } while (choice != 0);
      
}