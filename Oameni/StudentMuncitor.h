// StudentMuncitor.h

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Angajat.h"
#include "Student.h"
#include <cstring>
class StudentMuncitor: public Angajat, public Student
{// A trebuit sa mostenesc protected sau public ca sa pot accesa fara probleme campurile private;
public:
	StudentMuncitor();
	StudentMuncitor(char* numescoala, double nota1, double nota2, double nota3, double medie, int id, double salariu, char* numefirma);
	StudentMuncitor(char* nume, char* pren, int varst, long int cnp, char* numescoala, double nota1, double nota2, double nota3, double medie, int id, double salariu, char* numefirma);
	StudentMuncitor(const Persoane& pers, const Student& stud, const Angajat& angj);
	StudentMuncitor(const Persoane& pers, const Angajat& angj, const Student& stud);
	StudentMuncitor(const Student& stud, const Persoane& pers, const Angajat& angj);
	StudentMuncitor(const Student& stud, const Angajat& angj, const Persoane& pers);
	StudentMuncitor(const Angajat& angj, const Persoane& pers, const Student& stud);
	StudentMuncitor(const Angajat& angj, const Student& stud, const Persoane& pers);
	StudentMuncitor(const StudentMuncitor& studmun);

	bool operator<(const StudentMuncitor& studmun);
	bool operator>(const StudentMuncitor& studmun);
	bool operator==(const StudentMuncitor& studmun);
	StudentMuncitor& operator=(const StudentMuncitor& studmun);

	friend std::ostream& operator<<(std::ostream& out, const StudentMuncitor& studmun);
	friend std::istream& operator>>(std::istream& in, StudentMuncitor& studmun);

	// Aceasta clasa nu are nevoie de setter sau getter deoarece ii mosteneste;
	~StudentMuncitor();
};

