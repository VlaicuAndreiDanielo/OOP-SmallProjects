#pragma once
#include <iostream>
class Matrice
{
	int Coloane, Linii;
	double* Elemente = new double[Coloane * Linii];
public:
	Matrice();
	Matrice(int coloane, int linii, double* elemente);
	Matrice(const Matrice& mat);

	Matrice operator+(const Matrice& mat);
	Matrice operator-(const Matrice& mat);
	Matrice operator*(const Matrice& mat);

	Matrice operator*(double nr);
	Matrice operator/(double nr);
	Matrice& operator=(const Matrice& mat);

	Matrice operator+=(const Matrice& mat);
	Matrice operator-=(const Matrice& mat);
	Matrice operator*=(const Matrice& mat);

	Matrice operator*=(int nr);
	Matrice operator/=(int nr);

	friend std::ostream& operator<<(std::ostream& out, const Matrice& mat);
	friend std::istream& operator>>(std::istream& in, Matrice& mat);

	void SetColoane(int col);
	void SetLinii(int lin);
	void SetElemente(double* elemente);

	int GetColoane();
	int GetLinii();
	double* GetElemente();
	void IntroducereElemente(int Col, int Lin);

	~Matrice();
};

