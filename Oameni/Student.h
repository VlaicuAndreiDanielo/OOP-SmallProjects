//Student.h

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persoane.h"
#include <cstring>
class StudentMuncitor;
class Student: virtual public Persoane
{// A trebuit sa mostenesc protected sau public ca sa pot accesa fara probleme campurile private;
	friend class StudentMuncitor;
private:
	char* NumeScoala;
	double Nota1, Nota2, Nota3;
	double Medie = (Nota1 + Nota2 + Nota3) / 3;
public:
	Student();
	Student(char* numescoala, double nota1, double nota2, double nota3, double medie);
	Student(char* nume, char* pren, int varst, long int cnp, char* numescoala, double nota1, 
		double nota2, double nota3, double medie);
	Student(const Persoane& pers, char* numescoala, double nota1,
		double nota2, double nota3, double medie);
	Student(const Student& stud);

	bool operator<(const Student& stud);
	bool operator>(const Student& stud);
	bool operator==(const Student& stud);
	Student& operator=(const Student& stud);

	friend std::ostream& operator<<(std::ostream& out, const Student& stud);
	friend std::istream& operator>>(std::istream& in, Student& stud);

	void SetNumeScoala(const char* numescl);
	void SetNota1(double not1); void SetNota2(double not2); void SetNota3(double not3);
	void SetMedie();

	const char* GetNumeScoala() const;
	double GetNota1() const; double GetNota2() const; double GetNota3() const;
	double GetMedie() const;

	virtual ~Student();
};

