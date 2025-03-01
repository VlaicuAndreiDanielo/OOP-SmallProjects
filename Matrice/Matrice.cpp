#include "Matrice.h"

Matrice::Matrice() :Coloane(0), Linii(0), Elemente(nullptr) {};

Matrice::Matrice(int coloane, int linii, double* elemente)
{
	Coloane = coloane;
	Linii = linii;
	
	if (Elemente == nullptr)
	{
		Elemente = new double[Linii * Coloane];
	}
	else
	{
		delete[] Elemente;
		Elemente = new double[Linii * Coloane];
	}
	
	for (int i = 0; i < Linii * Coloane; i++)
	{
		Elemente[i] = elemente[i];
	}
}

Matrice::Matrice(const Matrice& mat)
{
	Elemente = new double[Linii * Coloane];
	Coloane = mat.Coloane;
	Linii = mat.Linii;
	for (int i = 0; i < Linii * Coloane; i++)
	{

		Elemente[i] = mat.Elemente[i];
	}
}

Matrice Matrice::operator+(const Matrice& mat)
{
	Matrice Rez;
	if (Linii == mat.Linii && Coloane == mat.Coloane)
	{
		Rez.Coloane = Coloane; Rez.Linii = Linii;
		for (int i = 0; i < Linii * Coloane; i++)
		{
			Rez.Elemente[i] = Elemente[i] + mat.Elemente[i];
		}
	}
	else
	{
		std::cout << "Matriciile nu se pot aduna" << std::endl;
		return *this;
	}
	return Rez;
}

Matrice Matrice::operator-(const Matrice& mat)
{
	Matrice Rez;
	if (Linii == mat.Linii && Coloane == mat.Coloane)
	{
		Rez.Coloane = Coloane; Rez.Linii = Linii;
		for (int i = 0; i < Linii * Coloane; i++)
		{
			Rez.Elemente[i] = Elemente[i] - mat.Elemente[i];
		}
	}
	else
	{
		std::cout << "Matriciile nu se pot scadea" << std::endl;
		return *this;
	}
	return Rez;
}

Matrice Matrice::operator*(const Matrice& mat)
{
	if (Coloane != mat.Linii) 
	{
		std::cout << "Matricile nu pot fi inmultite" << std::endl;
		return *this;
	}
	else
	{
		Matrice Rez(Linii, mat.Coloane, new double[Linii * mat.Coloane]);

		for (int i = 0; i < Linii; i++) {
			for (int j = 0; j < mat.Coloane; j++) {
				Rez.Elemente[i * mat.Coloane + j] = 0;
				for (int k = 0; k < this->Coloane; k++) {
					Rez.Elemente[i * mat.Coloane + j] += Elemente[i * Coloane + k] * mat.Elemente[k * mat.Coloane + j];
				}
			}
		}
		return Rez;
	}
}

Matrice Matrice::operator*(double nr)
{
	Matrice Rez;
	Rez.Coloane = Coloane; Rez.Linii = Linii;
	for (int i = 0; i < Coloane * Linii; i++)
	{
		Rez.Elemente[i] = Elemente[i] * nr;
	}
	return Rez;
}

Matrice Matrice::operator/(double nr)
{
	Matrice Rez;
	Rez.Coloane = Coloane; Rez.Linii = Linii;
	for (int i = 0; i < Coloane * Linii; i++)
	{
		Rez.Elemente[i] = Elemente[i] / nr;
	}
	return Rez;
}

Matrice& Matrice::operator=(const Matrice& mat)
{
	if (this == &mat)
	{
		return *this;
	}
	delete[] Elemente;

	Coloane = mat.Coloane;
	Linii = mat.Linii;
	Elemente = new double[Linii * Coloane];

	for (int i = 0; i < Linii * Coloane; i++)
	{
		Elemente[i] = mat.Elemente[i];
	}
	return *this;
}

Matrice Matrice::operator+=(const Matrice& mat)
{
	if (Linii != mat.Linii || Coloane != mat.Coloane)
	{
		std::cout << "matricile nu pot fi adunate" << std::endl;
		return *this;
	}
	for (int i = 0; i < Linii * Coloane; i++)
	{
		Elemente[i] += mat.Elemente[i];
	}
	return *this;
}

Matrice Matrice::operator-=(const Matrice& mat)
{
	if (Linii != mat.Linii || Coloane != mat.Coloane)
	{
		std::cout << "matricile nu pot fi scazute" << std::endl;
		return *this;
	}
	for (int i = 0; i < Linii * Coloane; i++)
	{
		Elemente[i] += mat.Elemente[i];
	}
	return *this;
}

Matrice Matrice::operator*=(const Matrice& mat)
{
	if (Coloane != mat.Linii)
	{
		std::cout << "Matricile nu pot fi inmultite" << std::endl;
		return *this;
	}
	else
	{
		Matrice Rez(Linii, mat.Coloane, new double[Linii * mat.Coloane]);

		for (int i = 0; i < Linii; i++) {
			for (int j = 0; j < mat.Coloane; j++) {
				Rez.Elemente[i * mat.Coloane + j] = 0;
				for (int k = 0; k < this->Coloane; k++) {
					Rez.Elemente[i * mat.Coloane + j] += Elemente[i * Coloane + k] * mat.Elemente[k * mat.Coloane + j];
				}
			}
		}
		delete[] this->Elemente;
		this->Coloane = Rez.Coloane;
		this->Linii = Rez.Linii;
		for (int i = 0; i < Linii * Coloane; i++)
		{
			Elemente[i] = Rez.Elemente[i];
		}
		Rez.Elemente = nullptr;
		return *this;
	}
}

Matrice Matrice::operator*=(int nr)
{
	for (int i = 0; i < Coloane * Linii; i++)
	{
		this->Elemente[i] = Elemente[i] * nr;
	}
	return *this;
}

Matrice Matrice::operator/=(int nr)
{
	for (int i = 0; i < Coloane * Linii; i++)
	{
		this->Elemente[i] = Elemente[i] / nr;
	}
	return *this;
}

void Matrice::SetColoane(int col)
{
	Coloane = col;
}

void Matrice::SetLinii(int lin)
{
	Linii = lin;
}

void Matrice::SetElemente(double* elemente)
{
	if (Elemente != nullptr)
	{
		delete[] Elemente;
	}

	Elemente = new double[Linii * Coloane];

	for (int i = 0; i < Linii * Coloane; ++i)
	{
		Elemente[i] = elemente[i];
	}
}

int Matrice::GetColoane()
{
	return Coloane;;
}

int Matrice::GetLinii()
{
	return Linii;
}

double* Matrice::GetElemente()
{
	double* Elem = new double[Linii * Coloane];
	for (int i = 0; i < Linii * Coloane; i++)
	{
		Elem[i] = Elemente[i];
	}
	return Elem;

	//Sau daca doar dorec sa il afisez;
	for (int i = 0; i < Linii; i++) {
		for (int j = 0; j < Coloane; j++) {
			std::cout << Elemente[i * Coloane + j] << " ";
		}
		std::cout << std::endl;
	}
    // Sau si mai simplu returnand direct Elemente;
	return this->Elemente;
}

void Matrice::IntroducereElemente(int Col, int Lin)
{
	for (int i = 0; i < Lin * Col; i++)
	{
		Elemente[i] = i;
	}
}

Matrice::~Matrice()
{
	delete[] Elemente;
}

std::ostream& operator<<(std::ostream& out, const Matrice& mat)
{
	out << std::endl;
	for (int i = 0; i < mat.Linii; i++) {
		for (int j = 0; j < mat.Coloane; j++) {
			out << mat.Elemente[i * mat.Coloane + j] << " ";
		}
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Matrice& mat)
{
	std::cout << "Nr. Coloane:";
	in >> mat.Coloane;
	std::cout << std::endl;
	std::cout << "Nr. Linii:";
	in >> mat.Linii;
	std::cout << std::endl;
	std::cout << "Elemente:" << std::endl;

	delete[] mat.Elemente;
	mat.Elemente = new double[mat.Linii * mat.Coloane];
	for (int i = 0; i < mat.Linii * mat.Coloane; i++)
	{
		in >> mat.Elemente[i];
	}
	return in;
}
