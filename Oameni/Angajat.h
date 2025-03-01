//Angajat.h

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persoane.h"
#include <cstring>
class StudentMuncitor;
class Angajat: virtual public Persoane
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

