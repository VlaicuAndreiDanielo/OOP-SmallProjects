//Persoane.h

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
class Angajat;  class Student;  class StudentMuncitor;
class Persoane
{
	friend class Angajat;
	friend class Student;
	friend class StudentMuncitor;
private:
	char* Nume;
	char* Prenume;
	int Varsta;
	long int CNP;
public:
	Persoane();
	Persoane(char* nume, char* pren, int varst, long int cnp);
	Persoane(const Persoane& pers);

	bool operator<(const Persoane& pers);
	bool operator>(const Persoane& pers);
	bool operator==(const Persoane& pers);
	Persoane& operator=(const Persoane& pers);


	friend std::ostream& operator<<(std::ostream& out, const Persoane& pers);
	friend std::istream& operator>>(std::istream& in, Persoane& pers);

	void SetNume(const char* num);
	void SetPrenume(const char* prenum);
	void SetVarsta(int vrst);
	void SetCNP(long int cnp);

	const char* GetNume() const;
	const char* GetPrenume() const;
	int GetVarsta() const;
	long int GetCNP() const;

	virtual ~Persoane();
};

//Angajat.h

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persoane.h"
#include <cstring>
class StudentMuncitor;
class Angajat : virtual public Persoane
{// A trebuit sa mostenesc protected sau public ca sa pot accesa fara probleme campurile private;
	friend class StudentMuncitor;
private:
	int IdAngajat;
	double Salariu;
	char* NumeFirma;
public:
	Angajat();
	Angajat(int id, double salariu, char* numefirma);
	Angajat(char* nume, char* pren, int varst, long int cnp, int id, double salariu, char* numefirma);
	Angajat(const Persoane& pers, int id, double salariu, char* numefirma);
	Angajat(const Angajat& angj);

	bool operator<(const Angajat& angj);
	bool operator>(const Angajat& angj);
	bool operator==(const Angajat& angj);
	Angajat& operator=(const Angajat& angj);

	friend std::ostream& operator<<(std::ostream& out, const Angajat& ang);
	friend std::istream& operator>>(std::istream& in, Angajat& ang);

	void SetIdAngajat(int id);
	void SetSalariu(double salar);
	void SetNumeFirma(const char* numfirm);

	int GetIdAngajat() const;
	double GetSalariu() const;
	const char* GetNumeFirma() const;

	virtual ~Angajat();
};

//Student.h

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persoane.h"
#include <cstring>
class StudentMuncitor;
class Student : virtual public Persoane
{// A trebuit sa mostenesc protected sau public ca sa pot accesa fara probleme campurile private;
	friend class StudentMuncitor;
private:
	char* NumeScoala;
	double Nota1, Nota2, Nota3;
	double Medie = (Nota1 + Nota2 + Nota3) / 3;
public:
	Student();
	Student(char* numescoala, double nota1, double nota2, double nota3, double medie);
	Student(char* nume, char* pren, int varst, long int cnp, char* numescoala, double nota1, double nota2, double nota3, double medie);
	Student(const Persoane& pers, char* numescoala, double nota1, double nota2, double nota3, double medie);
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

// StudentMuncitor.h

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Angajat.h"
#include "Student.h"
#include <cstring>
class StudentMuncitor : public Angajat, public Student
{// A trebuit sa mostenesc protected sau public ca sa pot accesa fara probleme campurile private;
public:
	StudentMuncitor();
	StudentMuncitor(char* numescoala, double nota1, double nota2, double nota3, double medie, int id, double salariu, char* numefirma);
	StudentMuncitor(char* nume, char* pren, int varst, long int cnp, char* numescoala, double nota1, double nota2, double nota3, double medie,int id, double salariu, char* numefirma);
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

