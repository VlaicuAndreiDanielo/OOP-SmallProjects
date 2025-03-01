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

