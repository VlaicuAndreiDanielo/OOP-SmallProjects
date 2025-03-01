#include "Complex.h"
#include <iostream>
Complex::Complex()
{
	Real = 0; Imag = 0;
}

Complex::Complex(double r, double i)
{
	Real = r; Imag = i;
}

Complex::Complex(const Complex& Obiect)
{
	this->Real = Obiect.Real;
	this->Imag = Obiect.Imag;
}

Complex Complex::operator+(double nr)
{
	Complex rez;
	rez.Real = this->Real + nr;
	rez.Imag = this->Imag;
	return rez;
}

Complex Complex::operator+(const Complex& obiect)
{
	Complex rez;
	rez.Real = this->Real + obiect.Real;
	rez.Imag = this->Imag + obiect.Imag;
	return rez;
	// Complex(this->real + obiect.real, this->imag + obiect.imag);
	// Complex(rez.Real, rez.Imag);
}

Complex Complex::operator*(double nr)
{
	Complex rez;
	rez.Real = this->Real * nr;
	rez.Imag = this->Imag * nr;
	return rez;
}

Complex Complex::operator*(const Complex& obiect)
{
	Complex rez;
	rez.Real = this->Real * obiect.Real - this->Imag * obiect.Imag;
	rez.Imag = this->Real * obiect.Imag + this->Imag * obiect.Real;
	return rez;
}

Complex Complex::operator/(double nr)
{
	Complex rez;
	rez.Real = this->Real / nr;
	rez.Imag = this->Imag / nr;
	return rez;
}

Complex Complex::operator/(const Complex& obiect)
{
	Complex rez;
	rez.Real = ((this->Real * obiect.Real) + (this->Imag * obiect.Imag)) / ((obiect.Real * obiect.Real) + (obiect.Imag * obiect.Imag));
	rez.Imag = ((this->Imag * obiect.Real) + (this->Real * obiect.Imag)) / ((obiect.Real * obiect.Real) + (obiect.Imag * obiect.Imag));
	return rez;
}

Complex& Complex::operator=(const Complex& obiect)
{
	if (this != &obiect) 
	{ 
		Real = obiect.Real;
		Imag = obiect.Imag;
	}
	return *this;
}

Complex Complex::operator+=(double nr)
{
	Real += nr;
	return *this;
}

Complex Complex::operator*=(double nr)
{
	Real *= nr;
	Imag *= nr;
	return *this;
}

Complex Complex::operator/=(double nr)
{
	Real /= nr;
	Imag /= nr;
	return *this;
}

Complex Complex::operator+=(const Complex& obiect)
{
	Real = Real + obiect.Real;
	Imag = Imag + obiect.Imag;
	return *this;
}

Complex Complex::operator*=(const Complex& obiect)
{
	double REAL = Real * obiect.Real - Imag * obiect.Imag;
	Imag = Real * obiect.Imag + Imag * obiect.Real;
	Real = REAL;
	return *this;
}

Complex Complex::operator/=(const Complex& obiect)
{
	double numitor = obiect.Real * obiect.Real + obiect.Imag * obiect.Imag;
	double Real = (Real * obiect.Real + Imag * obiect.Imag) / numitor;
	Imag = (Imag * obiect.Real - Real * obiect.Imag) / numitor;
	Real = Real;
	return *this;
}

void Complex::SetReal(double real)
{
	this->Real = real;
}

void Complex::SetImag(double imag)
{
	this->Imag = imag;
}

double Complex::GetReal()
{
	return this->Real;
}

double Complex::GetImag()
{
	return this->Imag;
}

Complex::~Complex()
{
	//Destructor gol deoarece nu sunt alcoate dinamic elemente;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
	out << complex.Real;
	if (complex.Imag >= 0)
	{
		out << " + " << complex.Imag << 'i';
	}
	else
	{
		out << " - " << complex.Imag << 'i';
	}
	return out;
}

std::istream& operator>>(std::istream& in, Complex& complex)
{
	std::cout << "Partea reala: ";
	in >> complex.Real;
	std::cout << "Partea imaginara: ";
	in >> complex.Imag;
	return in;
}
