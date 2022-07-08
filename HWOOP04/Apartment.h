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

	void initHabitants(Person* hab, int size)
	{
		if (habitants != nullptr)
		{
			delete[] habitants;
		}
		habitants = new Person[size];
		for (int i = 0; i < size; i++)
		{
			habitants[i] = hab[i];
		}
	}

	void Print()
	{
		cout << "flat number " << number << ":\n";
		for (int i = 0; i < size; i++)
		{
			habitants[i].Print();
		}
	}
};

