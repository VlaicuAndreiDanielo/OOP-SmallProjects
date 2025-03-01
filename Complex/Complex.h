#pragma once
#include <iostream>
class Complex
{
private:
	double Real;
	double Imag;
public:
	Complex();
	Complex(double r, double i);
	Complex(const Complex& Obiect);

	Complex operator+(double nr);
	Complex operator+(const Complex& obiect);
	Complex operator*(double nr);
	Complex operator*(const Complex& obiect);
	Complex operator/(double nr);
	Complex operator/(const Complex& obiect);
	Complex& operator=(const Complex& obiect);

	Complex operator+=(double nr);
	Complex operator*=(double nr);
	Complex operator/=(double nr);

	Complex operator+=(const Complex& obiect);
	Complex operator*=(const Complex& obiect);
	Complex operator/=(const Complex& obiect);

	friend std::ostream& operator<<(std::ostream& out, const Complex& c);
	friend std::istream& operator>>(std::istream& in,Complex& c);

	void SetReal(double real);
	void SetImag(double imag);
	double GetReal();
	double GetImag();

	~Complex();
};

