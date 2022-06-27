#include "Fraction.h"

Fraction Fraction::Summand( Fraction s2)
{
	if (denominator == s2.denominator)
		return Fraction(numerator + s2.numerator, denominator);
	else
	{
		numerator *= s2.denominator;
		denominator *= s2.denominator;
		s2.numerator *= denominator;
		s2.denominator *= denominator;

		return Fraction(numerator + s2.numerator, denominator);
	}
}
Fraction Fraction::Subtraction(Fraction s2)
{
	s2.numerator *= -1;
	this->Summand(s2);
}
Fraction Fraction::Multiply(Fraction m2)
{
	return Fraction(numerator * m2.numerator, denominator * m2.denominator);
}
Fraction Fraction::Division(Fraction d2)
{
	return Fraction(numerator * d2.denominator, denominator * d2.numerator);
}