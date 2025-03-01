#pragma once
#include <iostream>
class Rational
{
	int numarator;
	int numitor;
public:
	Rational();
	Rational(int nr, int num);
	Rational(const Rational& Rat);
	// Rational(const Rational& Rat): numitor(Rat.numitor), numarator(Rat.numarator){};
	Rational operator+(int nr);
	Rational operator+(const Rational& Rat);
	Rational operator-(int nr);
	Rational operator-(const Rational& Rat);
	Rational operator*(int nr);
	Rational operator*(const Rational& Rat);
	Rational operator/(int nr);
	Rational operator/(const Rational& Rat);

	Rational operator++();
	Rational operator++(int);

	bool operator==(const Rational& Rat);
	bool operator<(const Rational& Rat);
	bool operator>(const Rational& Rat);

	Rational operator=(const Rational& Rat);
	Rational operator+=(const Rational& Rat);
	Rational operator-=(const Rational& Rat);
	Rational operator*=(const Rational& Rat);
	Rational operator/=(const Rational& Rat);
	Rational operator+=(int nr);
	Rational operator-=(int nr);
	Rational operator*=(int nr);
	Rational operator/=(int nr);

	friend std::ostream& operator<<(std::ostream& out, const Rational& Rat);
	friend std::istream& operator>>(std::istream& in, Rational& Rat);

	void SeterNumitor(int numi);
	void SeterNumarator(int numar);
	int GeterNumitor();
	int GeterNumarator();

	Rational Simplificare();

	double ShowRational();

	~Rational();
};

