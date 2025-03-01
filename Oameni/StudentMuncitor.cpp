// StudentMuncitor.cpp

#include "StudentMuncitor.h"
#include <iostream>
#include <cstring>
StudentMuncitor::StudentMuncitor() :Angajat(), Student() {};

StudentMuncitor::StudentMuncitor(char* numescoala, double nota1, double nota2, double nota3, double medie, int id, double salariu, char* numefirma) : Angajat(id, salariu, numefirma), Student(numescoala, nota1, nota2, nota3, medie) {}

StudentMuncitor::StudentMuncitor(char* nume, char* pren, int varst, long int cnp, char* numescoala, double nota1, double nota2, double nota3, double medie, int id, double salariu, char* numefirma)
    : Persoane(nume,pren,varst,cnp), Angajat(id, salariu, numefirma), Student(numescoala, nota1, nota2, nota3, medie) {}

StudentMuncitor::StudentMuncitor(const Persoane& pers, const Student& stud, const Angajat& angj)
    : Persoane(pers), Angajat(angj), Student(stud){}

StudentMuncitor::StudentMuncitor(const Persoane& pers, const Angajat& angj, const Student& stud)
	: Persoane(pers), Angajat(angj), Student(stud) {}

StudentMuncitor::StudentMuncitor(const Student& stud, const Persoane& pers, const Angajat& angj)
	: Persoane(pers), Angajat(angj), Student(stud) {}

StudentMuncitor::StudentMuncitor(const Student& stud, const Angajat& angj, const Persoane& pers)
	: Persoane(pers), Angajat(angj), Student(stud) {}

StudentMuncitor::StudentMuncitor(const Angajat& angj, const Persoane& pers, const Student& stud)
	: Persoane(pers), Angajat(angj), Student(stud) {}

StudentMuncitor::StudentMuncitor(const Angajat& angj, const Student& stud, const Persoane& pers)
	: Persoane(pers), Angajat(angj), Student(stud) {}

StudentMuncitor::StudentMuncitor(const StudentMuncitor& studmun)
	:Angajat(studmun), Student(studmun) {}

bool StudentMuncitor::operator<(const StudentMuncitor& studmun)
{

	// Compara Prenume daca Numele sunt egale;
	int Compare = strcmp(Nume, studmun.Nume);
	if (Compare < 0) return true;
	if (Compare > 0) return false;

	// Compara  Prenumele daca Numele sunt egale;
	Compare = strcmp(Prenume, studmun.Prenume);
	if (Compare < 0) return true;
	if (Compare > 0) return false;

	// Compara Varsta daca Prenumele si Numele sunt egale;
	if (Varsta < studmun.Varsta) return true;
	if (Varsta > studmun.Varsta) return false;

	//Comparam Media daca Toate cele de mai sus sunt egale;
	if (Medie < studmun.Medie) return true;
	if (Medie > studmun.Medie) return false;

	//Comparam Salariul daca Toate cele de mai sus sunt egale;
	if (Salariu < studmun.Salariu) return true;
	if (Salariu > studmun.Salariu) return false;

	return false;
}

bool StudentMuncitor::operator>(const StudentMuncitor& studmun)
{
	//Deoarece > este complementul lui <;
	return !(*this < studmun) && !(*this == studmun);
}

bool StudentMuncitor::operator==(const StudentMuncitor& studmun)
{
	return strcmp(Nume, studmun.Nume) == 0 && strcmp(Prenume, studmun.Prenume) == 0 && Varsta == studmun.Varsta && Salariu == studmun.Salariu && Medie == studmun.Medie;
}

StudentMuncitor& StudentMuncitor::operator=(const StudentMuncitor& studmun)
{

	if (this == &studmun)
	{
		return *this;
	}
	else
	{
		delete[] NumeFirma;
		IdAngajat = studmun.IdAngajat;
		Salariu = studmun.Salariu;
		NumeFirma = new char[strlen(studmun.NumeFirma) + 1];
		strcpy_s(NumeFirma, strlen(studmun.NumeFirma) + 1, studmun.NumeFirma);
		Varsta = studmun.Varsta;
		CNP = studmun.CNP;

		delete[] Nume;
		delete[] Prenume;
		Nume = new char[strlen(studmun.Nume) + 1];
		strcpy_s(Nume, strlen(studmun.Nume) + 1, studmun.Nume);
		Prenume = new char[strlen(studmun.Prenume) + 1];
		strcpy_s(Prenume, strlen(studmun.Prenume) + 1, studmun.Prenume);

		delete[] NumeScoala;
		NumeScoala = new char[strlen(studmun.NumeScoala) + 1];
		strcpy_s(NumeScoala, strlen(studmun.NumeScoala) + 1, studmun.NumeScoala);
		Nota1 = studmun.Nota1; Nota1 = studmun.Nota2; Nota3 = studmun.Nota3;
		Medie = studmun.Medie;
	}
}

StudentMuncitor::~StudentMuncitor(){}

std::ostream& operator<<(std::ostream& out, const StudentMuncitor& studmun)
{
	if (studmun.GetNume() != nullptr && studmun.GetPrenume() != nullptr)
	{
		out << studmun.GetNume() << " " << studmun.GetPrenume() << " " << studmun.GetVarsta() << " " << studmun.GetCNP() << " ";
	}
	if (studmun.GetNumeFirma() != nullptr)
	{
		out << studmun.GetIdAngajat() << " " << studmun.GetSalariu() << " " << studmun.GetNumeFirma()<<" ";
	}
	if (studmun.GetNumeScoala() != nullptr)
	{
		out << studmun.GetNumeScoala() << " " << studmun.GetMedie();
	}
	return out;
}

std::istream& operator>>(std::istream& in, StudentMuncitor& studmun)
{
	char temp[50];
	std::cout << "Nume:";
	in >> temp;
	studmun.SetNume(temp);
	std::cout << "Prenume:";
	in >> temp;
	studmun.SetPrenume(temp);
	std::cout << "Varsta:"; int varsta;
	in >> varsta;
	studmun.SetVarsta(varsta);
	std::cout << "CNP:"; long int cnp;
	in >> cnp;
	studmun.SetCNP(cnp);
	std::cout << "NumeFirma:";
	in >> temp;
	studmun.SetNumeFirma(temp);
	std::cout << "IdAngajat:"; int idangajat;
	in >> idangajat;
	studmun.SetIdAngajat(idangajat);
	std::cout << "Salariu:"; double salar;
	in >> salar;
	studmun.SetSalariu(salar);
	std::cout << "NumeScoala:";
	in >> temp;
	studmun.SetNumeScoala(temp);
	std::cout << "Nota1:";  double nota1;
	in >> nota1;
	studmun.SetNota1(nota1);
	std::cout << "Nota2:";  double nota2;
	in >> nota2;
	studmun.SetNota2(nota2);
	std::cout << "Nota3:";  double nota3;
	in >> nota3;
	studmun.SetNota3(nota3);
	
	return in;
}
