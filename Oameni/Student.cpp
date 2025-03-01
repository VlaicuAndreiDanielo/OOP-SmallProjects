//Student.cpp

#include "Student.h"
Student::Student() : Persoane(), NumeScoala(nullptr)
{
	Nota1 = 0; Nota2 = 0; Nota3 = 0;
	Medie = 0; // Puteam sa nu o mai initializez;
	NumeScoala = new char[1];
	NumeScoala[0] = '\0';
}

Student::Student(char* numescoala, double nota1, double nota2, double nota3, double medie) : Persoane()
{
	if (NumeScoala != nullptr)
		delete[] NumeScoala;
	Nota1 = nota1; Nota2 = nota2; Nota3 = nota3;
	Medie = medie;
	NumeScoala = new char[strlen(numescoala) + 1];
	strcpy_s(NumeScoala, strlen(numescoala) + 1, numescoala);
}

Student::Student(char* nume, char* pren, int varst, long int cnp, char* numescoala, double nota1, double nota2, double nota3, double medie)
	: Persoane(nume, pren, varst, cnp)
{
	if (NumeScoala != nullptr)
		delete[] NumeScoala;
	Nota1 = nota1; Nota2 = nota2; Nota3 = nota3;
	Medie = medie;
	NumeScoala = new char[strlen(numescoala) + 1];
	strcpy_s(NumeScoala, strlen(numescoala) + 1, numescoala);
}

Student::Student(const Persoane& pers, char* numescoala, double nota1, double nota2, double nota3, double medie)
	: Persoane(pers)
{
	if (NumeScoala != nullptr)
		delete[] NumeScoala;
	Nota1 = nota1; Nota2 = nota2; Nota3 = nota3;
	Medie = medie;
	NumeScoala = new char[strlen(numescoala) + 1];
	strcpy_s(NumeScoala, strlen(numescoala) + 1, numescoala);
}

Student::Student(const Student& stud) : Persoane(stud)
{
	delete[] NumeScoala;
	Nota1 = stud.Nota1; Nota2 = stud.Nota2; Nota3 = stud.Nota3;
	Medie = stud.Medie;
	NumeScoala = new char[strlen(stud.NumeScoala) + 1];
	strcpy_s(NumeScoala, strlen(stud.NumeScoala) + 1, stud.NumeScoala);
}

bool Student::operator<(const Student& stud)
{
	// Compara Prenume daca Numele sunt egale;
	int Compare = strcmp(Nume, stud.Nume);
	if (Compare < 0) return true;
	if (Compare > 0) return false;

	// Compara  Prenumele daca Numele sunt egale;
	Compare = strcmp(Prenume, stud.Prenume);
	if (Compare < 0) return true;
	if (Compare > 0) return false;

	// Compara Varsta daca Prenumele si Numele sunt egale;
	if (Varsta < stud.Varsta) return true;
	if (Varsta > stud.Varsta) return false;

	//Comparam Media daca Toate cele de mai sus sunt egale;
	if (Medie < stud.Medie) return true;
	if (Medie > stud.Medie) return false;

	return false;
}

bool Student::operator>(const Student& stud)
{
	//Deoarece > este complementul lui <;
	return !(*this < stud) && !(*this == stud);
}

bool Student::operator==(const Student& stud)
{
	return strcmp(Nume, stud.Nume) == 0 && strcmp(Prenume, stud.Prenume) == 0 && Varsta == stud.Varsta && Medie == stud.Medie;
}

Student& Student::operator=(const Student& stud)
{
	if (this == &stud)
	{
		return *this;
	}
	else
	{
		Varsta = stud.Varsta;
		CNP = stud.CNP;

		delete[] Nume;
		delete[] Prenume;
		Nume = new char[strlen(stud.Nume) + 1];
		strcpy_s(Nume, strlen(stud.Nume) + 1, stud.Nume);
		Prenume = new char[strlen(stud.Prenume) + 1];
		strcpy_s(Prenume, strlen(stud.Prenume) + 1, stud.Prenume);

		delete[] NumeScoala;
		NumeScoala = new char[strlen(stud.NumeScoala) + 1];
		strcpy_s(NumeScoala, strlen(stud.NumeScoala) + 1, stud.NumeScoala);
		Nota1 = stud.Nota1; Nota1 = stud.Nota2; Nota3 = stud.Nota3;
		Medie = stud.Medie;
	}
	return *this;
}	

void Student::SetNumeScoala(const char* numescl)
{
	delete[] NumeScoala;
	NumeScoala = new char[strlen(numescl) + 1];
	strcpy_s(NumeScoala, strlen(numescl) + 1, numescl);
}

void Student::SetNota1(double not1)
{
	Nota1 = not1;
}

void Student::SetNota2(double not2)
{
	Nota2 = not2;
}

void Student::SetNota3(double not3)
{
	Nota3 = not3;
}

void Student::SetMedie()
{
	Medie = (Nota1 + Nota2 + Nota3) / 3;
}

const char* Student::GetNumeScoala() const
{
	return NumeScoala;
}

double Student::GetNota1() const
{
	return Nota1;
}

double Student::GetNota2() const
{
	return Nota2;
}

double Student::GetNota3() const
{
	return Nota3;
}

double Student::GetMedie() const
{
	return Medie;
}

Student::~Student()
{
	delete[] NumeScoala;
}

std::ostream& operator<<(std::ostream& out, const Student& stud)
{
	if (stud.GetNume() != nullptr && stud.GetPrenume() != nullptr)
	{
		out << stud.GetNume() << " " << stud.GetPrenume() << " " << stud.GetVarsta() << " " << stud.GetCNP() << " ";
	}
	if (stud.NumeScoala != nullptr)
	{
		out << stud.NumeScoala << " " << stud.Medie;
	}

	return out;
}

std::istream& operator>>(std::istream& in, Student& stud)
{
	char temp[50];
	std::cout << "Nume:";
	in >> temp;
	stud.SetNume(temp);
	std::cout << "Prenume:";
	in >> temp;
	stud.SetPrenume(temp);
	std::cout << "Varsta:"; int varsta;
	in >> varsta;
	stud.SetVarsta(varsta);
	std::cout << "CNP:"; long int cnp;
	in >> cnp;
	stud.SetCNP(cnp);
	std::cout << "NumeScoala:"; 
	in >> temp;
	stud.SetNumeScoala(temp);
	std::cout << "Nota1:";  double nota1;
	in >> nota1;
	stud.SetNota1(nota1);
	std::cout << "Nota2:";  double nota2;
	in >> nota2;
	stud.SetNota2(nota2);
	std::cout << "Nota3:";  double nota3;
	in >> nota3;
	stud.SetNota3(nota3);
	return in;
}
