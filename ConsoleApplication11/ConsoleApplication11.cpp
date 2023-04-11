// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <cassert>

using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:

	Fraction(int newNumerator, int newDenominator)
		: numerator{ newNumerator }, denominator{ newDenominator } 
	{
		if (newDenominator == 0)
		{
			cout << "Error";
			exit(0);
	    }
	}

	Fraction() : Fraction(1, 1) {}

	Fraction(const Fraction& cop)
		: numerator{ cop.numerator },
		denominator{ cop.denominator } {}

	friend Fraction operator+(const Fraction& left,
		const Fraction& right)
	{
		return Fraction{ left.numerator *
		right.denominator +
	   right.numerator *
	   left.denominator,
		left.denominator *
	   right.denominator };
	}

	friend Fraction operator-(const Fraction& left,
		const Fraction& right)
	{
		return Fraction{ left.numerator * right.denominator -
		right.numerator * left.denominator,
		left.denominator * right.denominator };
	}

	friend Fraction operator*(const Fraction& left,
		const Fraction& right)
	{
		return Fraction{ left.numerator *
		right.numerator, left.denominator *
		right.denominator };
	}

	friend Fraction operator/(const Fraction& left,
		const Fraction& right)
	{
		return Fraction{ left.numerator * right.denominator,
		left.denominator * right.numerator };
	}

	void print()
	{
		cout << '(' << numerator << " / "
			<< denominator << ")";
	}
	
	~Fraction() {}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Fraction a{ 2, 3 };
	Fraction b{ 3, 6 };
	cout << "a = ";
	a.print();
	cout << "\nb = ";
	b.print();
	cout << "\na + b = "; 
	(a + b).print(); 
	cout << "\na * b = "; 
	(a * b).print(); 
	cout << "\na / b = "; 
	(a / b).print(); 

}
