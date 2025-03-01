#include "Rational.h"
#include <iostream>
Rational::Rational() : numarator(0), numitor(1) {}

Rational::Rational(int nr, int num)
{
	if (num != 0)
	{
		numitor = num;
		numarator = nr;
	}
	else
	{
		std::cout << "Numitor invalid";
		return;
	}
}
Rational::Rational(const Rational& Rat)
{
	this->numitor = Rat.numitor;
	this->numarator = Rat.numarator;
}

Rational Rational::operator+(int nr)
{
	Rational Rez;
	Rez.numarator = this->numarator + (nr * this->numitor);
	return Rez; 
	// return Rational(numar, this->numitor);
}

Rational Rational::operator+(const Rational& Rat)
{
	Rational Rez;
	if (this->numitor != Rat.numitor)
	{
		Rez.numarator = (this->numarator * Rat.numitor) + (Rat.numarator * this->numitor);
		Rez.numitor = this->numitor * Rat.numarator;
	}
	else
	{
		Rez.numarator = this->numarator + Rat.numarator;
		Rez.numitor = this->numitor;
	}
	return Rez;
	//return Rational(this->numarator, this->numitor);
}

Rational Rational::operator-(int nr)
{
	Rational Rez;
	Rez.numarator = this->numarator - (nr * this->numitor);
	return Rez;
	// return Rational(numar, this->numitor);
}

Rational Rational::operator-(const Rational& Rat)
{
	Rational Rez;
	if (this->numitor != Rat.numitor)
	{
		Rez.numarator = (this->numarator * Rat.numitor) - (Rat.numarator * this->numitor);
		Rez.numitor = this->numitor * Rat.numarator;
	}
	else
	{
		Rez.numarator = this->numarator + Rat.numarator;
		Rez.numitor = this->numitor;
	}
	return Rez;
	//return Rational(this->numarator, this->numitor);
}

Rational Rational::operator*(int nr)
{
	Rational Rez;
	Rez.numarator = this->numarator * nr;
	return Rez;
	// return Rational(this->numarator, this->numitor);
}

Rational Rational::operator*(const Rational& Rat)
{
	Rational Rez;
	Rez.numarator = this->numarator * Rat.numarator;
	Rez.numitor = this->numitor * Rat.numitor;
	return Rez;
	// return Rational(this->numarator, this->numitor);
}

Rational Rational::operator/(int nr)
{
	Rational Rez;
	Rez.numitor = this->numitor * nr;
	return Rez;
	// return Rational(this->numarator, this->numitor);
}

Rational Rational::operator/(const Rational& Rat)
{
	Rational Rez;
	Rez.numarator = this->numarator * Rat.numitor;
	Rez.numitor = this->numitor * Rat.numarator;
	return Rez;
	// return Rational(this->numarator, this->numitor);
}


Rational Rational::operator++()
{
	this->numarator = this->numarator + this->numitor;
	//this->numarator += this->numitor;
	return *this;
}

Rational Rational::operator++(int)
{
	Rational temporal = *this;
	this->numarator = this->numarator + this->numitor;
	//this->numarator += this->numitor;
	return temporal;

}

bool Rational::operator==(const Rational& Rat)
{
	if (this->numarator == Rat.numarator)
	{
		if (this->numitor == Rat.numitor)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	// retrun (this->numarator * Rat.numitor) == (Rat.numarator * this->numitor)

}

bool Rational::operator<(const Rational& Rat)
{
	return (this->numarator * Rat.numitor) < (Rat.numarator * this->numitor);
}

bool Rational::operator>(const Rational& Rat)
{
	return (this->numarator * Rat.numitor) > (Rat.numarator * this->numitor);
}

Rational Rational::operator=(const Rational& Rat)
{
	if (this != &Rat)
	{
		this->numarator = Rat.numarator;
		this->numitor = Rat.numitor;
	}
	return *this;
}

Rational Rational::operator+=(const Rational& Rat)
{
	this->numarator = this->numarator * Rat.numitor + this->numitor * Rat.numarator;
	this->numitor = this->numitor * Rat.numitor;
	return *this;
}

Rational Rational::operator-=(const Rational& Rat)
{
	this->numarator = this->numarator * Rat.numitor - this->numitor * Rat.numarator;
	this->numitor = this->numitor * Rat.numitor;
	return *this;
}

Rational Rational::operator*=(const Rational& Rat)
{
	this->numarator = this->numarator * Rat.numarator;
	this->numitor = this->numitor * Rat.numitor;
	return *this;
}

Rational Rational::operator/=(const Rational& Rat)
{
	this->numarator = this->numarator * Rat.numitor;
	this->numitor = this->numitor * Rat.numarator;
	return *this;
}

Rational Rational::operator+=(int nr)
{
	this->numarator = this->numarator + (nr * this->numitor);
	return *this;
}

Rational Rational::operator-=(int nr)
{
	this->numarator = this->numarator - (nr * this->numitor);
	return *this;
}

Rational Rational::operator*=(int nr)
{
	this->numarator = this->numarator * nr;
	return *this;
}

Rational Rational::operator/=(int nr)
{
	this->numitor = this->numitor * nr;
	return *this;
}

void Rational::SeterNumitor(int numi)
{
	this->numitor = numi;
}

void Rational::SeterNumarator(int numar)
{
	this->numarator = numar;
}

int Rational::GeterNumitor()
{
	return this->numitor;
}

int Rational::GeterNumarator()
{
	return this->numarator;
}

Rational Rational::Simplificare()
{
	int DivMaxim;
	if (numitor < numarator)
	{
		DivMaxim = numitor;
	}
	else
	{
		DivMaxim = numarator;
	}
	for (int i = 2; i < DivMaxim; i++)
	{
		if (numitor % i == 0 && numarator % i == 0)
		{
			numitor = numitor / i;
			numarator = numarator / i;
		}
	}
	return *this;
}

double Rational::ShowRational()
{
	double rezultat= static_cast<double>(numarator) / static_cast<double>(numitor);
	return rezultat;
}

Rational::~Rational()
{
	//Destructor gol deoarece nu sunt alcoate dinamic elemente;
}

std::ostream& operator<<(std::ostream& out, const Rational& Rat)
{
	out << Rat.numarator << '/' << Rat.numitor;
	return out;
}

std::istream& operator>>(std::istream& in, Rational& Rat)
{
	std::cout << "Numaratorul:";
	in >> Rat.numarator;
	std::cout << "Numitorul:";
	in >> Rat.numitor;
	return in;
}
