/*Задание 1.
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай». С помощью 
конструктора установить имя каждого животного и его 
характеристики.*/
#include <iostream>
using namespace std;

class Pet
{
protected:
    string name;
    int weight;
    int height;
    string color;

public:
    Pet(string nameP, int weightP, int heightP, string colorP) : name{ nameP }, weight{ weightP }, height{ heightP }, color { colorP }
    {
        cout << "new pet: " << name << endl;
    }
    Pet() :Pet("noname", 1, 1, "none") {}

    string Name()
    {
        return name;
    }

    void Name(string nameP)
    {
        name = nameP;
    }

    int Weight()
    {
        return weight;
    }

    void Weight(int weightP)
    {
        weight = weightP;
    }

    int Height()
    {
        return height;
    }

    void Height(int heightP)
    {
        height = heightP;
    }

    string Color()
    {
        return color;
    }

    void Color(string colorP)
    {
        color = colorP;
    }
};

class Breedable //если у животного есть порода
{
protected:
    string breed;
public:
    string Breed()
    {
        return breed;
    }

    void Breed(string breedP)
    {
        breed = breedP;
    }

};

class Dog :public Pet, public Breedable
{    
public:
    Dog(string nameP, int weightP, int heightP, string colorP, string breedP) : Pet(nameP, weightP, heightP, colorP)
    {
        breed = breedP;
        cout << "new dog: " << name << " breed " << breed << endl;
    }
    Dog() :Dog("noname", 1, 1, "none", "unknown") {}
    
};

class Cat : public Pet, public Breedable
{
    string breed;
public:
    Cat(string nameP, int weightP, int heightP, string colorP, string breedP) :Pet(nameP, weightP, heightP, colorP)
    {
        breed = breedP;
        cout << "new cat: " << name << " breed " << breed << endl;
    }
    Cat() :Cat("noname", 1, 1, "none", "unknown") {}
};

class Parrot : public Pet, public Breedable
{
    string breed;
public:
    Parrot(string nameP, int weightP, int heightP, string colorP, string breedP) :Pet(nameP, weightP, heightP, colorP)
    {
        breed = breedP;
        cout << "new cat: " << name << " breed " << breed << endl;
    }
    Parrot() :Parrot("noname", 1, 1, "none", "unknown") {}
};

int main()
{
    Dog Polkan("Polkan", 5, 25, "white", "York");
    Cat Murenka("Murenka", 4, 20, "striped", "Scottish");
    Parrot Pti4ka("Pernatiy", 1, 10, "blue", "Blue wavy parrot");  
}
