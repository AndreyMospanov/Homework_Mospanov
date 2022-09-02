#pragma once
#include<iostream>
#include<string>
using namespace std;

class Flat
{
	int square;
	int price;

public:
	Flat(int squareP, int priceP) :square { squareP }, price{ priceP }{}
	Flat() :Flat(0, 0) {}

	Flat& operator = (const Flat o2)
	{
		this->square = o2.square;
		this->price = o2.price;
		return *this;
	}

	friend ostream& operator << (ostream& output, const Flat& o1)
	{
		output << "Flat with square " << o1.square << "m3 with price = " << o1.price;
		return output;
	}

	friend istream& operator >> (istream& input, Flat& o1)
	{
		input >> o1.square >> o1.price;
		return input;
	}

	friend bool operator == (const Flat& o1, const Flat& o2)
	{
		return o1.square == o2.square;
	}

	friend bool operator != (const Flat& o1, const Flat& o2)
	{
		return !(o1 == o2);
	}

	friend bool operator > (const Flat& o1, const Flat& o2)
	{
		return o1.price > o2.price;
	}

	friend bool operator < (const Flat& o1, const Flat& o2)
	{
		return o1.price < o2.price;
	}

	
	
		
	


};

