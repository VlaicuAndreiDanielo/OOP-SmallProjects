// Matrice

#include <iostream>
#include "Matrice.h"

int main()
{
	Matrice Mat1;
	double elem1[12] = {1, 9, 8, 12, 6.4, 7, 12, 17, 5, 89, 10, 14};
	//double* elem1= new double[12];
	Mat1.SetColoane(4); Mat1.SetLinii(3);
	//Mat1.IntroducereElemente(Mat1.GetColoane(), Mat1.GetLinii());
	Mat1.SetElemente(elem1);

	std::cout << Mat1;
	double elem2[6] = {5, 8.4, 5.6, 4, 7, 12};
	Matrice Mat2(3, 2, elem2);
	Matrice Mat3(Mat2);

	std::cout << Mat3.GetColoane();

	Matrice Mat4 = Mat2 * Mat1;
	std::cout << Mat4;

	Mat3 += Mat2;
	std::cout << Mat3;

	Matrice Mat5;
	Mat5.SetColoane(2); Mat5.SetLinii(3);
	double elem3[6];
	for (int i = 0; i < Mat5.GetLinii() * Mat5.GetColoane(); i++)
	{
		double temp;
		std::cin >> temp;
		elem3[i] = temp;
	}
	std::cout << Mat5;

	return 0;
}