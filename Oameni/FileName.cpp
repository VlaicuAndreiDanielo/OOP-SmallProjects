// Oameni

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persoane.h"
#include "Angajat.h"
#include "Student.h"
#include "StudentMuncitor.h"
#include <cstring>

int main()
{
	Persoane pers1, pers2;
	std::cin >> pers1;
	pers2.SetNume("Maria"); pers2.SetPrenume("Eva"); pers2.SetVarsta(5); pers2.SetCNP(63928582);

	if (pers1 < pers2) {
		std::cout << "pers1 este mai mic decat pers2" << std::endl;
	}
	else if (pers1 > pers2) {
		std::cout << "pers1 este mai mare decat pers2" << std::endl;
	}
	else if (pers1 == pers2) {
		std::cout << "pers1 este egal cu pers2" << std::endl;
	}

	std::cout << pers1 << std::endl;
	char nume[] = "Mihai";
	char prenume[] = "Mihaela";
	char numefirma[] = "Minerva";
	Angajat angj1(nume, prenume, 7, 869797829, 700, 456.7, numefirma); 
	//Angajat angj1("Mihai", "Mihaela", 7, 869797829, 700, 456.7, "Minerva");
	//Daca voiam sa sriu asa trebuia sa fac campurile char8 ca fiind constante (const char*);
	std::cout << angj1 << std::endl;
	Angajat angj2(angj1);
	std::cout << angj2 << std::endl;
	Angajat angj3(989, 9874.87, numefirma);
	std::cout << angj3 << std::endl;

	char scoala[] = "Universitate";
	Student stud1(pers1, scoala, 5.7, 8.9, 9.9, (5.7 + 8.9 + 9.9) / 3);
	std::cout << stud1 << std::endl;

	Student stud2(scoala, 7.6, 8.9, 6.9, (7.6 + 8.9 + 6.9) / 3);
	std::cout << stud2 << std::endl;

	StudentMuncitor studmun1(pers1, angj3, stud2);
	std::cout << studmun1 << std::endl;

	return 0;
}