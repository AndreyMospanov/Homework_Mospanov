/*1. Поиск по названию;
2. Поиск по владельцу; 
3. Поиск по номеру телефона; 
4. Поиск по роду деятельности; 
5. Показ всех записей и добавление.

Вся информация, должна сохранятся в файле, должна
быть реализована возможность добавления новых данных.*/
#pragma once
#include "Note.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class Notebook
{
    vector<Note> notes;
    string path;
    
public:
    Notebook()
    {
        path = "Notebook.txt";
        ifstream in(path);        

        if (in.bad() == true) //in.bad == true , если файл по указанному адресу не существует
        {
            ofstream out;
            out.open(path);//создаём файл по указанному адресу
            out.close();
        }  
        else
        {
            Open();//в другом случае открываем файл
        }
    }
    void Find(string toFind, int idx)
    {
        switch (idx)
        {
        case 1:
        {
            for (int i = 0; i < notes.size(); i++)
            {
                if (notes[i].Name() == toFind)
                {
                    cout << notes[i].info();
                }
            }
            break;
        }

        case 2:
        {
            for (int i = 0; i < notes.size(); i++)
            {
                if (notes[i].Owner() == toFind)
                {
                    cout << notes[i].info();
                }
            } 
            break;
        }

        case 3:
        {
            for (int i = 0; i < notes.size(); i++)
            {
                if (notes[i].Phone() == toFind)
                {
                    cout << notes[i].info();
                }
            }    
            break;
        }

        case 4:
        {
            for (int i = 0; i < notes.size(); i++)
            {
                if (notes[i].Adress() == toFind)
                {
                    cout << notes[i].info();
                }
            }  
            break;
        }

        case 5:
        {
            for (int i = 0; i < notes.size(); i++)
            {
                if (notes[i].TypeOfActivity() == toFind)
                {
                    cout << notes[i].info();
                }
            }    
            break;
        }

        default:
            break;
        }
        
    }

    void Print()
    {
        for (int i = 0; i < notes.size(); i++)
        {
            cout << notes[i].info() << endl;
        }
    }
    void Add(Note newNote)
    {
        newNote.Import();
        notes.push_back(newNote);
    }

    void Erase(int index)
    {
        try
        {
            if (notes.empty())
                throw "empty";
            if (index > notes.size() || index < 0)
                throw index;

            notes.erase(notes.begin() + index);
            cout << "Успешное удаление\n";
        }
        catch (string)
        {
            cout << "Справочник уже пуст!\n";
        }
        catch (int)
        {
            cout << "За границами диапазона!\n";
        }
    }
    
    int length()
    {
        return notes.size();
    }
    
    void Open()
    {
        ifstream in;
        string name;
        string owner;
        string phone;
        string adress;
        string typeOfActivity;
        in.open(path);
        if (in.is_open())
        {
            while (in >> name >> owner >> phone >> adress >> typeOfActivity)
            {
                Add(Note(name, owner, phone, adress, typeOfActivity));                
            }
        }
        in.close();
    }

    void Save()
    {
        ofstream out;
        out.open(path);
        if (out.is_open())
        {
            for (int i = 0; i < notes.size(); i++)
            {
                out << notes[i];
            }
        }
        out.close();
        cout << "Успешное сохранение\n";
    }

    Note& operator [] (int index)
    {
        return notes[index];
    }
};

