//Angajat.cpp

#include "Angajat.h"

Angajat::Angajat() : Persoane(), IdAngajat(0), Salariu(0), NumeFirma(nullptr)
{
	NumeFirma = new char[1];
	NumeFirma[0] = '\0';
}

Angajat::Angajat(int id, double salariu, char* numefirma) : Persoane()
{
	if (NumeFirma != nullptr)
		delete[] NumeFirma;
	IdAngajat = id;
	Salariu = salariu;
	NumeFirma = new char[strlen(numefirma) + 1];
	strcpy_s(NumeFirma, strlen(numefirma) + 1, numefirma);
}

Angajat::Angajat(char* nume, char* pren, int varst, long int cnp, int id, double salariu, char* numefirma)
	: Persoane(nume, pren, varst, cnp)
{
	if (NumeFirma != nullptr)
		delete[] NumeFirma;

	IdAngajat = id;
	Salariu = salariu;
	NumeFirma = new char[strlen(numefirma) + 1];
	strcpy_s(NumeFirma, strlen(numefirma) + 1, numefirma);
}

Angajat::Angajat(const Persoane& pers, int id, double salariu, char* numefirma)
	: Persoane(pers)
{
	if (NumeFirma != nullptr)
		delete[] NumeFirma;

	IdAngajat = id;
	Salariu = salariu;
	NumeFirma = new char[strlen(numefirma) + 1];
	strcpy_s(NumeFirma, strlen(numefirma) + 1, numefirma);
}

Angajat::Angajat(const Angajat& angj) : Persoane(angj)
{   if(NumeFirma !=nullptr)
        delete[] NumeFirma;

	IdAngajat = angj.IdAngajat;
	Salariu = angj.Salariu;
	NumeFirma = new char[strlen(angj.NumeFirma) + 1];
	strcpy_s(NumeFirma, strlen(angj.NumeFirma) + 1, angj.NumeFirma);
}

bool Angajat::operator<(const Angajat& angj)
{
	// Compara Prenume daca Numele sunt egale;
	int Compare = strcmp(Nume, angj.Nume);
	if (Compare < 0) return true;
	if (Compare > 0) return false;

	// Compara  Prenumele daca Numele sunt egale;
	Compare = strcmp(Prenume, angj.Prenume);
	if (Compare < 0) return true;
	if (Compare > 0) return false;

	// Compara Varsta daca Prenumele si Numele sunt egale;
	if (Varsta < angj.Varsta) return true;
	if (Varsta > angj.Varsta) return false;

	//Comparam Salariul daca Toate cele de mai sus sunt egale;
	if (Salariu < angj.Salariu) return true;
	if (Salariu > angj.Salariu) return false;

	return false;
}

bool Angajat::operator>(const Angajat& angj)
{
	//Deoarece > este complementul lui <;
	return !(*this < angj) && !(*this == angj);
}

bool Angajat::operator==(const Angajat& angj)
{
	return strcmp(Nume, angj.Nume) == 0 && strcmp(Prenume, angj.Prenume) == 0 && Varsta == angj.Varsta && Salariu == angj.Salariu;
}

Angajat& Angajat::operator=(const Angajat& angj)
{
	if (this == &angj)
	{
		return *this;
	}
	else
	{
		delete[] NumeFirma;
		IdAngajat = angj.IdAngajat;
		Salariu = angj.Salariu;
		NumeFirma = new char[strlen(angj.NumeFirma) + 1];
		strcpy_s(NumeFirma, strlen(angj.NumeFirma) + 1, angj.NumeFirma);
		Varsta = angj.Varsta;
		CNP = angj.CNP;

		delete[] Nume;
		delete[] Prenume;
		Nume = new char[strlen(angj.Nume) + 1];
		strcpy_s(Nume, strlen(angj.Nume) + 1, angj.Nume);
		Prenume = new char[strlen(angj.Prenume) + 1];
		strcpy_s(Prenume, strlen(angj.Prenume) + 1, angj.Prenume);
	}
	return *this;
}

void Angajat::SetIdAngajat(int id)
{
	IdAngajat = id;
}

void Angajat::SetSalariu(double salar)
{
	Salariu = salar;
}

void Angajat::SetNumeFirma(const char* numfirm)
{
	delete[] NumeFirma;
	NumeFirma = new char[strlen(numfirm) + 1];
	strcpy_s(NumeFirma, strlen(numfirm) + 1, numfirm);
}

int Angajat::GetIdAngajat() const
{
	return IdAngajat;
}

double Angajat::GetSalariu() const
{
	return Salariu;
}

const char* Angajat::GetNumeFirma() const
{
	if (NumeFirma == nullptr)
	{
		return nullptr;
	}
	else
	{
		return NumeFirma;
	}
}

Angajat::~Angajat()
{
	delete[] NumeFirma;
}

std::ostream& operator<<(std::ostream& out, const Angajat& ang)
{
	if (ang.GetNume() != nullptr && ang.GetPrenume() != nullptr)
	{
		out << ang.GetNume() << " " << ang.GetPrenume() << " " << ang.GetVarsta() << " " << ang.GetCNP() << " ";
	}
	if (ang.NumeFirma != nullptr)
	{
		out << ang.IdAngajat << " " << ang.Salariu << " " << ang.NumeFirma;
	}

	return out;
}

std::istream& operator>>(std::istream& in, Angajat& ang)
{
	char temp[50];
	std::cout << "Nume:";
	in >> temp;
	ang.SetNume(temp);
	std::cout << "Prenume:";
	in >> temp;
	ang.SetPrenume(temp);
	std::cout << "Varsta:"; int varsta;
	in >> varsta;
	ang.SetVarsta(varsta); 
	std::cout << "CNP:"; long int cnp;
	in >> cnp;
	ang.SetCNP(cnp);
	std::cout << "NumeFirma:"; 
	in >> temp;
	ang.SetNumeFirma(temp);
	std::cout << "IdAngajat:"; int idangajat;
	in >> idangajat;
	ang.SetIdAngajat(idangajat);
	std::cout << "Salariu:"; double salar;
	in >> salar;
	ang.SetSalariu(salar);
	
	return in;
}
