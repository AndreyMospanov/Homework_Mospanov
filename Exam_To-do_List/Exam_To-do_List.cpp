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
    system("cls");
    cout << "0. Exit menu\n1. Add case\n2. Delete case\n3. Edit case\n4. Find case\n5. Print list\n6. Add DEMO to-do's\n";
    cout << "enter a number of choice\n";
    
}

void printNames(vector<Case> &database)
{
    for (int i = 0; i < database.size(); i++)
    {
        cout << i + 1 << ". " << database[i].getName() << endl;
    }
    cout << endl;
    cout << "press 0 to exit in main menu\n";
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
        cout << " month ";
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
    cout << "press 0 to exit in main menu\n";
}

void PrintDB(vector<Case> database, int choice)
{
    int sort;
    SYSTEMTIME timeNow;
    GetLocalTime(&timeNow);

    switch (choice)
    {
    //print all
    case 1:
    {
        for (int i = 0; i < database.size(); i++)
        {
            database[i].Print();
        }
        break;
    }
    //print to do this day
    case 2:
    {
        for (int i = 0; i < database.size(); i++)
        {
            if (database[i].getDeadline().wYear == timeNow.wYear && database[i].getDeadline().wMonth == timeNow.wMonth && database[i].getDeadline().wDay == timeNow.wDay)
            {
                database[i].Print();
            }            
        }
        break;
    }
    //print to do this week
    case 3:
    {
        for (int i = 0; i < database.size(); i++)
        {
            if (database[i].getDeadline().wYear == timeNow.wYear && database[i].getDeadline().wMonth == timeNow.wMonth && database[i].getDeadline().wDay - timeNow.wDay < 8)
            {
                database[i].Print();
            }
        }
        break;
    }
    //print to do this month
    case 4:
    {
        for (int i = 0; i < database.size(); i++)
        {
            if (database[i].getDeadline().wYear == timeNow.wYear && database[i].getDeadline().wMonth == timeNow.wMonth)
            {
                database[i].Print();
            }
        }
        break;
    }
    default:
        break;
    }
    //sort cases by priority, deadline
    
    do
    {        
        cout << "sort  1. by priority \n2. by deadline\n0. exit\n";
        cin >> sort;
        if (sort == 0)
        {
            break;
        }
        else if (sort == 1)
        {
            for (int i = 0; i < database.size(); i++)
            {
                for (int j = 0; j < database.size() - 1; j++)
                {
                    if (database[i].getPriority() < database[j].getPriority())
                    {
                        Case temp = database[i];
                        database[i] = database[j];
                        database[j] = temp;
                    }
                }
            }
            system("cls");
            PrintDB(database, choice);            
        }
        else if (sort == 2)
        {
            for (int i = 0; i < database.size(); i++)
            {
                for (int j = 0; j < database.size() - 1; j++)
                {
                    if (database[i].getDeadline().wYear >= database[j].getDeadline().wYear)
                    {
                        if (database[i].getDeadline().wMonth >= database[j].getDeadline().wMonth)
                        {
                            if (database[i].getDeadline().wDay > database[j].getDeadline().wDay)
                            {
                                Case temp = database[i];
                                database[i] = database[j];
                                database[j] = temp;
                            }
                        }
                    }
                }
            }
            system("cls");
            PrintDB(database, choice);            
        }
    } while (sort < 0 || sort > 2);
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
        
        system("cls");

        switch (choice)
        {
        //exit menu
        case 0:
        {
            break;
        }
        //add case
        case 1:
        {
            database.push_back(temp);
            cout << "Add new case:\n";
            database.at(database.size() - 1).Edit();
            cout << "-------------\n";
            database.at(database.size() - 1).Print();
            break;
        }
        //delete case
        case 2:
        {
            int numberToDelete;
            do
            {  
                system("cls");
                cout << "Choose case to erase\n\n";
                printNames(database);
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
        //edit case
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
                    database[numberToEdit].Edit();
                }
                else
                {
                    cout << "number of case to edit does not exist\n";
                }
            } while (numberToEdit < database.size());
            break;
        }
        //Find by
        case 4:
        {     
            cout << "0. Exit\nFind case by\n1. name\n2. priority\n3. description\n4. Deadline\n";
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
            break;
        }
        //print cases (all/day/week/month)
        case 5:
        {
            int choice;            
            do
            {
                cout << "choose cases to show\n1. all\n2. to do today\n3. to do this week\n4. to do this month\n";
                cin >> choice;
                if (choice == 0)
                {
                    break;                
                }
                else if (choice < 0 && choice > 4)
                {
                    cout << "number of choice is not correct\n";
                }
            } while (choice < 0 || choice > 4);
            
            PrintDB(database, choice);
            break;
        }
        //add DEMO to-do's
        case 6:
        {
            Case temp1("to do something today", 2, "some description", 2022, 6, 14, 20);
            Case temp2("pass Exam", 1, "pass Exam C++ with two progs & theoretic test", 2022, 6, 15, 22);
            Case temp3("ride a bike", 3, "ride my bike with somebody", 2022, 6, 20, 16);
            Case temp4("build PC", 1, "build my new PC", 2022, 6, 18, 12);
            Case temp5("write programs in C#", 2, "learn & write something new from C#", 2022, 7, 2, 18);
            Case temp6("play guitar", 3, "learn & write something new from C#", 2022, 7, 5, 22);
            database.push_back(temp1);
            database.push_back(temp2);
            database.push_back(temp3);
            database.push_back(temp4);
            database.push_back(temp5);
            database.push_back(temp6);
            break;
        }
        }
    } while (choice != 0);
}