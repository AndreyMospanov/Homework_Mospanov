/*Третье задание 
Создайте приложение «Список дел». Приложение должно позволять: 
■ Добавление дел. У дела есть: • название; • приоритет; • описание; • дата, время исполнения. 
■ Удаление дел. 
■ Редактирование дел.
■ Поиск дел по: • названию; • приоритету; • описанию; • дате и времени исполнения. 
■ Отображение списка дел: • на день; • на неделю; • на месяц. 
■ При отображении должна быть возможность сортировки: • по приоритету; • по дате и времени исполнения.*/

#include <iostream>
#include <vector>
#include <string>
#include "Case.h"
using namespace std;

void printMainMenu()
{    
    cout << "0. Exit menu\n1. Add case\n2. Delete case\n3. Edit case\n4. Find case\n5. Print list\n";
    cout << "enter a number of choice\n";
}

void printNames(vector<Case> &database)
{
    for (int i = 0; i < database.size(); i++)
    {
        cout << i + 1 << ". " << database[i].getName();
    }
    cout << endl;
}

void findInDB(vector<Case> database, int choice)
{        
    int index = 1;
    switch (choice)
    {
        //find by name
    case 1:
    {
        string name;
        
        cout << "enter string to find\n";
        cin >> name;
        for (int i = 0; i < database.size(); i++)
        {            
            if (database[i].getName().find(name) != string::npos)
            {                
                database[i].Print();
            }
        }
        break;
    }
    //find by priority
    case 2:
    {
        int priority;        
        cout << "enter priority find\n1: high\n2: normal\n3: low\n";
        cin >> priority;
        for (int i = 0; i < database.size(); i++)
        {
            if (database[i].getPriority() == priority - 1)
            {
                cout << index <<". ";
                index++;
                database[i].Print();
            }
            cout << endl;
        }
        break;
    }
    //find by description
    case 3:
    {
        string description;
        cin.ignore(1024, '\n');
        cout << "enter string to find\n";
        getline(cin, description);

        for (int i = 0; i < database.size(); i++)
        {
            if (database[i].getDescription().find(description) != string::npos)
            {
                database[i].Print();
            }
        }
        break;
    }
    //find by date
    case 4:
    {
        SYSTEMTIME toFind;
        cout << "Enter deadline time to find\n year: ";
        cin >> toFind.wYear;
        cout << "\nmonth ";
        cin >> toFind.wMonth;

        for (int i = 0; i < database.size(); i++)
        {
            if (database[i].getDeadline().wYear == toFind.wYear && database[i].getDeadline().wMonth == toFind.wMonth)
            {
                database[i].Print();
            }
        }
    }
    default:
        break;
    }
    
    
}

int main()
{ 
    int choice;
    vector<Case> database;
    Case temp = Case();
    
    do
    {
        printMainMenu();
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            database.push_back(temp);
            cout << "Add new case:\n";
            database.at(database.size() - 1).Edit();
            cout << "-------------\n";
            database.at(database.size() - 1).Print();
            break;
        }
        case 2:
        {
            int numberToDelete;
            do
            {                
                cout << "Choose case to erase\n";
                cin >> numberToDelete;
                numberToDelete--;
                if (numberToDelete < database.size())
                {
                    database.erase(database.begin() + numberToDelete);
                }
                else
                {
                    cout << "number of case to erase does not exist\n";
                }
            } while (numberToDelete < database.size());
            break;
        }
        case 3:
        {
            int numberToEdit;
            do
            {
                cout << "Choose case to edit\n";
                printNames(database);
                cin >> numberToEdit;
                numberToEdit--;
                if (numberToEdit < database.size())
                {
                    database.erase(database.begin() + numberToEdit);
                }
                else
                {
                    cout << "number of case to edit does not exist\n";
                }
            } while (numberToEdit < database.size());
            break;
        }
        case 4:
        {     
            cout << "Find case by\n1. name\n2. priority\n3. description\n4. Deadline\n";
            int choice;            
            do
            {
                cin >> choice;

                if (choice < 5)
                {
                    findInDB(database, choice);
                }
                else if (choice == 0)
                {
                    break;
                }
                else
                {
                    cout << "number of choice is not correct\n";
                }
            } while (choice > 0 && choice < 5);            
        }
        }
    } while (choice != 0);
}