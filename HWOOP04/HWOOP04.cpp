#include <iostream>
#include <array>
#include <string>
#include "Person.h"
#include "Apartment.h"
#include "House.h"

/*Встреча №4 
Создайте программу, имитирующую многоквартирный 
дом. Необходимо иметь классы “Человек”, “Квартира”, 
“Дом”. Класс “Квартира” содержит динамический массив 
объектов класса “Человек”. Класс “Дом” содержит массив 
объектов класса “Квартира”. 
Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области 
класса. Обращаем ваше внимание, что память под строковые значения выделяется динамически. Например, для 
ФИО в классе “Человек”. Не забывайте обеспечить классы 
различными конструкторами (конструктор копирования 
обязателен), деструкторами. В main протестировать работу полученного набора классов*/


Person* habs(int size)
{
    const char* names[10]{ "Андрей", "Алексей", "Александр", "Добрыня", "Светозар", "Севастьян", "Махмуд", "Джамшут", "Ярополк", "Боб" };
    const char* fthrNames[10]{ "Андреевич", "Алексеевич", "Александрович", "Добрынич", "Светозарович", "Севастьянович", "Махмуд Оглы", "Джамшутович", "Ярополкович", "Бобыч" };
    const char* lastNames[10]{ "Абобянко", "Мячников", "Огурцов", "Дудаков", "Джонсон", "Горшков", "Петров-Водкин", "Кшиштовский", "Прикрепин", "Бакланенков" };
    string info[10]{ "Нормальный", "Гадит в подъезде", "Алкаш", "Политически не благонадёжен", "Девиант", "Низкая социальная ответственность", "Нормальный", "Выкручивает лампочки", "Наркоман", "Паркуется на газоне"};

    Person* habitants = new Person[size];

    for (int i = 0; i < size; i++)
    {
        habitants[i].setFName(names[rand() % 10]);
        habitants[i].setFthrName(fthrNames[rand() % 10]);
        habitants[i].setLName(lastNames[rand() % 10]);
        habitants[i].setInfo(info[rand() % 10]);        
    }

    return habitants;
}

Apartment* aparts(int size)
{
    Apartment* aps = new Apartment[size];    

    for (int i = 0; i < size; i++)
    {
        int random = 1 + rand() % 6;
        Person* temp = new Person[random];
        temp = habs(random);
        aps[i].initHabitants(temp, random);
        aps[i].SetNumber(i + 1);        
    }
    return aps;
}

int main()
{
    setlocale(0, "");
    House* block;
    int randomHouseCount = 1 + rand() % 3;
    string address[5]{ "Радищева, 24", "Московская, 72", "Столыпина, 4", "Чапаева, 59", "Астраханская, 83" };
    block = new House[randomHouseCount];
    for (int i = 0; i < randomHouseCount; i++)
    {
        int random = 1 + rand() % 36;
        Apartment* temp;
        temp = new Apartment[random];
        temp = aparts(random);
        block[i].addApartments(temp, random);
        block[i].SetAddress(address[rand() % 5]);
        block[i].Print();
    }
}