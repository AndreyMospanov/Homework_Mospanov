#pragma once
#include <iostream>
using namespace std;
/*1. Название фирмы;
2. Владелец;
3. Телефон;
4. Адрес;
5. Род деятельности.*/
class Note
{
    string name;
    string owner;
    string phone;
    string adress;
    string typeOfActivity;

    string DeleteSpaces(string input)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == ' ')
            {
                input[i] = '_';
            }
        }
        return input;
    }
    string SetSpaces(string input)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '_')
            {
                input[i] = ' ';
            }
        }
        return input;
    }

public:
    Note(string nameP, string ownerP, string phoneP, string adressP, string typeOfActivityP) :name{ nameP }, owner{ ownerP }, phone{ phoneP }, adress{ adressP }, typeOfActivity{ typeOfActivityP } {}
    Note(string nameP) :Note(nameP, "", "", "", "" ) {}

    string Name()
    {
        return name;
    }
    void Name(string newData)
    {
        name = newData;
    }

    string Owner()
    {
        return owner;
    }
    void Owner(string newData)
    {
        owner = newData;
    }

    string Phone()
    {
        return phone;
    }
    void Phone(string newData)
    {
        phone = newData;
    }

    string Adress()
    {
        return adress;
    }
    void Adress(string newData)
    {
        adress = newData;
    }

    string TypeOfActivity()
    {
        return typeOfActivity;
    }
    void TypeOfActivity(string newData)
    {
        typeOfActivity = newData;
    }

    string info()
    {
        return "Name: " + name + "\nOwner: " + owner + "\nPhone: " + phone + "\nAdress: " + adress + "\nType of activity: " + typeOfActivity + "\n";
    }

    void PrepareForExport()//убираем пробелы в строках для экспорта в файл
    {
        name = DeleteSpaces(name);
        owner = DeleteSpaces(owner);
        phone = DeleteSpaces(phone);
        adress = DeleteSpaces(adress);
        typeOfActivity = DeleteSpaces(typeOfActivity);
    }

    void Import()//меняем нижнее подчёркивание на пробелы
    {
        name = SetSpaces(name);
        owner = SetSpaces(owner);
        phone = SetSpaces(phone);
        adress = SetSpaces(adress);
        typeOfActivity = SetSpaces(typeOfActivity);
    }

    friend ostream& operator << (ostream& out, Note& note)
    {
        note.PrepareForExport();
        out << note.name << " " << note.owner << " " << note.phone << " " << note.adress << " " << note.typeOfActivity << " \n";
        return out;
    }

    friend istream& operator >> (istream& in, Note& note)
    {
        in >> note.name >> note.owner >> note.phone >> note.adress >> note.typeOfActivity;        
        return in;
    }
};

