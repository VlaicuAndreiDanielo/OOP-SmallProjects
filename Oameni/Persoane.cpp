//Persoane.cpp

#include "Persoane.h"
#include <iostream>
#include <cstring>
Persoane::Persoane() :Nume(nullptr), Prenume(nullptr), Varsta(0), CNP(0) 
{
	Nume = new char[1];
	Nume[0] = '\0';
	Prenume = new char[1];
	Prenume[0] = '\0';
}

Persoane::Persoane(char* nume, char* pren, int varst, long int cnp)
{
	Varsta = varst;
	CNP = cnp;
	if (Nume != nullptr && Prenume != nullptr)
	{
		delete[] Nume;
		delete[] Prenume;
	}
	Nume = new char[strlen(nume) + 1];
	strcpy_s(Nume, strlen(nume) + 1, nume);    // strcpy (unde, de unde). Dar este mai sigur strcpy_s(unde, cat, de unde);
	Prenume = new char[strlen(pren) + 1];
	strcpy_s(Prenume, strlen(pren) + 1, pren); // strcpy (unde, de unde). Dar este mai sigur strcpy_s(unde, cat, de unde);
}

Persoane::Persoane(const Persoane& pers)
{
	Varsta = pers.Varsta;
	CNP = pers.CNP;
	if (Nume != nullptr && Prenume != nullptr)
	{
		delete[] Nume;
		delete[] Prenume;
	}
	Nume = new char[strlen(pers.Nume) + 1];
	strcpy_s(Nume, strlen(pers.Nume) + 1, pers.Nume);
	Prenume = new char[strlen(pers.Prenume) + 1];
	strcpy_s(Prenume, strlen(pers.Prenume) + 1, pers.Prenume);
}

bool Persoane::operator<(const Persoane& pers)
{
	// Compara Prenume daca Numele sunt egale;
	int Compare = strcmp(Nume, pers.Nume);
	if (Compare < 0) return true;
	if (Compare > 0) return false;

	// Compara  Prenumele daca Numele sunt egale;
	Compare = strcmp(Prenume, pers.Prenume);
	if (Compare < 0) return true;
	if (Compare > 0) return false;

	// Compara Varsta daca Prenumele si Numele sunt egale;
	if (Varsta < pers.Varsta) return true;
	if (Varsta > pers.Varsta) return false;

	return false;
}

bool Persoane::operator>(const Persoane& pers)
{
	//Deoarece > este complementul lui <;
	return !(*this < pers) && !(*this == pers);
}

bool Persoane::operator==(const Persoane& pers)
{
	return strcmp(Nume, pers.Nume) == 0 && strcmp(Prenume, pers.Prenume) == 0 && Varsta == pers.Varsta;
}

Persoane& Persoane::operator=(const Persoane& pers)
{
	if (this == &pers)
	{
		return *this;
	}
	else
	{
		Varsta = pers.Varsta;
		CNP = pers.CNP;

		delete[] Nume;
		delete[] Prenume;
		Nume = new char[strlen(pers.Nume) + 1];
		strcpy_s(Nume, strlen(pers.Nume) + 1, pers.Nume);
		Prenume = new char[strlen(pers.Prenume) + 1];
		strcpy_s(Prenume, strlen(pers.Prenume) + 1, pers.Prenume);
	}
	return *this;
}

void Persoane::SetNume(const char* num)
{
	delete[] Nume;
	Nume = new char[strlen(num) + 1];
	strcpy_s(Nume, strlen(num) + 1, num);
}

void Persoane::SetPrenume(const char* prenum)
{
	delete[] Prenume;
	Prenume = new char[strlen(prenum) + 1];
	strcpy_s(Prenume, strlen(prenum) + 1, prenum);
}

void Persoane::SetVarsta(int vrst)
{
	Varsta = vrst;
}

void Persoane::SetCNP(long int cnp)
{
	CNP = cnp;
}

const char* Persoane::GetNume() const
{
	if (Nume != nullptr)
	{
		return Nume;
    }
	return nullptr;
}

const char* Persoane::GetPrenume() const
{
	if (Prenume != nullptr)
	{
		return Prenume;
	}
	return nullptr;
}

int Persoane::GetVarsta() const
{
	return Varsta;
}

long int Persoane::GetCNP() const
{
	return CNP;
}

Persoane:: ~Persoane()
{
	delete[] Nume;
	delete[] Prenume;
}

std::ostream& operator<<(std::ostream& out, const Persoane& pers)
{
	//if (pers.Nume != nullptr && pers.Prenume)
	//{
	//	for (int i = 0; i < strlen(pers.Nume); i++)
	//		out << pers.Nume[i];
	//	out << " ";
	//	for (int i = 0; i < strlen(pers.Prenume); i++)
	//		out << pers.Prenume[i];
	//	out << " ";
	//	out << pers.Varsta;
	//	out << pers.CNP;
	//}
	// Varianta mai usoar
	if (pers.Nume != nullptr && pers.Prenume != nullptr)
	{
		out << pers.Nume << " " << pers.Prenume << " " << pers.Varsta << " " << pers.CNP;
	}
	return out;
	
}

std::istream& operator>>(std::istream& in, Persoane& pers)
{
	char temp[50];
	std::cout << "Nume:";
	in >> temp;
	pers.SetNume(temp);
	std::cout << "Prenume:";
	in >> temp;
	pers.SetPrenume(temp);
	std::cout << "Varsta:"; int varst;
	in >> varst;
	pers.SetVarsta(varst);
	std::cout << "CNP:"; long int cnp;
	in >> cnp;
	pers.SetCNP(cnp);

	return in;
}
