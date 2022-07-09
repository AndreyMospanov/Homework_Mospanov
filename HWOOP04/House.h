#pragma once
#include "Apartment.h"
#include <iostream>
#include <string>

using namespace std;
class House
{
	string address;
	int size;
	Apartment* apartments;
public:

	House(Apartment* aps, int size, string addr) :apartments{ aps ? new Apartment[size] : nullptr }, size{ size }, address{ addr }
	{
		if (aps != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				apartments[i] = aps[i];
			}
		}
	}

	House(int size, string addr) :House(nullptr, size, addr) {}

	House() :House(nullptr, 0, ""){}

	~House()
	{
		if (apartments != nullptr)
		{
			delete[] apartments;
		}
	}

	void addApartments(Apartment* aps, int size)
	{
		if (apartments != nullptr)
		{
			delete[] apartments;
		}
		this->size = size;
		apartments = new Apartment[size];
		if (aps != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				apartments[i] = aps[i];
			}
		}
	}

	void SetAddress(string address)
	{
		this->address = address;
	}

	void Print()
	{
		cout << "Дом " << address << ":\n";
		for (int i = 0; i < size; i++)
		{
			apartments[i].Print();
		}
		cout <<"-------------------------" << endl;
	}
};

