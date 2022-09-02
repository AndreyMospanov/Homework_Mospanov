#pragma once
#include <iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:

	Fraction(int num, int den) : numerator{ num }, denominator{ den }
	{
		if (denominator == 0)
		{
			cout << "Error. Denominator can't be equal to zero. Now it equals 1 \n";
			denominator++;
		}
	}
	Fraction(int num) :Fraction(num, 1) {}
	Fraction() :Fraction(1, 1) {}

	int getNumerator()
	{
		return numerator;
	}

	int getDenominator()
	{
		return denominator;
	}

	void setNumerator(int setter)
	{
		numerator = setter;
	}

	void setDenominator(int setter)
	{
		denominator = setter;
	}
	void Print()
	{
		cout << numerator << "/" << denominator;
	}

	Fraction Sum(Fraction s2);
	Fraction Subtraction(Fraction s2);
	Fraction Multiply(Fraction m2);
	Fraction Division(Fraction d2);

	friend Fraction operator + (Fraction& f1, Fraction& f2)
	{
		return f1.Sum(f2);
	}

	friend Fraction operator - (Fraction& f1, Fraction& f2)
	{
		return f1.Subtraction(f2);
	}

	friend Fraction operator * (Fraction& f1, Fraction& f2)
	{
		return f1.Multiply(f2);
	}

	friend Fraction operator / (Fraction& f1, Fraction& f2)
	{
		return f1.Division(f2);
	}
};

