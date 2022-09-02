#pragma once
#include<iostream>
#include<string>
using namespace std;
class Overcoat
{
	string type;
	double price;

public:
	Overcoat(string typeP, double priceP):type{typeP},price{priceP}{}
	Overcoat() :Overcoat("no type", 0){}

	Overcoat& operator = (const Overcoat o2)
	{
		this->type = o2.type;
		this->price = o2.price;
		return *this;
	}

	friend ostream& operator << (ostream& output, const Overcoat& o1)
	{
		output << o1.type << " with price = " << o1.price;
		return output;
	}

	friend istream& operator >> (istream& input, Overcoat& o1)
	{
		input >> o1.type >> o1.price;
		return input;
	}

	friend bool operator == (const Overcoat& o1, const Overcoat& o2)
	{
		if (o1.type == o2.type)
			return true;
		else
			return false;
	}

	friend bool operator != (const Overcoat& o1, const Overcoat& o2)
	{
		return !(o1 == o2);
	}

	friend bool operator > (const Overcoat& o1, const Overcoat& o2)
	{
		return o1.price > o2.price;
	}

	friend bool operator < (const Overcoat& o1, const Overcoat& o2)
	{
		return o1.price < o2.price;
	}
};

