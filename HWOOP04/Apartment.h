#pragma once
#include "Person.h"
#include <iostream>
using namespace std;
class Apartment
{
	int number;
	int size;
	Person* habitants;

public:
	Apartment(Person* hab, int size, int num) :habitants{ hab ? new Person[size] : nullptr}, number{num}
	{
		this -> size = size;
		if (hab != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				habitants[i] = hab[i];
			}
		}		
	}

	Apartment(int size, int num):Apartment(nullptr, size, num){}

	Apartment():Apartment(nullptr, 0, 0){}

	~Apartment()
	{
		if (habitants != nullptr)
		{
			delete[] habitants;
		}
	}

	void SetNumber(int num)
	{
		number = num;
	}

	void initHabitants(Person* hab, int size)
	{
		if (habitants != nullptr)
		{
			delete[] habitants;
		}
		this->size = size;
		habitants = new Person[size];
		for (int i = 0; i < size; i++)
		{
			habitants[i] = hab[i];			
		}
	}

	void Print()
	{
		cout << "Квартира № " << number << ":\n";
		for (int i = 0; i < size; i++)
		{			
			habitants[i].Print();
		}
		cout << endl;
	}
};

