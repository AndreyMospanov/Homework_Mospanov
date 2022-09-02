#pragma once
#include <iostream>
using namespace std;

class Komplex
{
	double real;
	double imaginary;

public:

	Komplex(double realP, double imaginaryP): real{realP}, imaginary{imaginaryP} {}
	Komplex(double realP): Komplex(realP, 0){}
	Komplex():Komplex(0,0){}

	double Real()
	{
		return real;
	}

	double Imaginary()
	{
		return imaginary;
	}

	void Real(double value)
	{
		real = value;
	}

	void Imaginary(double value)
	{
		imaginary = value;
	}

	friend ostream& operator << (ostream& output, Komplex num)
	{
		if (num.imaginary >= 0)
		{
			output << num.real << " + " << num.imaginary << "i ";
		}
		else
		{
			output << num.real << " - " << -1 * num.imaginary << "i ";
		}
		
		return output;
	}

	friend istream& operator >> (istream& input, Komplex num)
	{
		input >> num.real >> num.imaginary;
		return input;
	}

	friend Komplex operator + (const Komplex& num1, const Komplex& num2)
	{
		return Komplex(num1.real + num2.real, num1.imaginary + num2.imaginary);
	}

	friend Komplex operator - (const Komplex& num1, const Komplex& num2)
	{
		return Komplex(num1.real - num2.real, num1.imaginary - num2.imaginary);
	}

	friend Komplex operator * (const Komplex& num1, const Komplex& num2)
	{		
		return Komplex(num1.real * num2.real - num1.imaginary * num2.imaginary, num1.real * num2.imaginary + num2.real * num1.imaginary);
	}

	friend Komplex operator / (const Komplex& num1, const Komplex& num2)
	{
		Komplex temp;
		temp.real = num2.real / (num2.real * num2.real + num2.imaginary * num2.imaginary);
		temp.imaginary = - num2.imaginary / (num2.real * num2.real + num2.imaginary * num2.imaginary);
		return num1 * temp;
	}
};

