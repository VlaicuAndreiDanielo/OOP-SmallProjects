// Rational

#include "Rational.h"
#include <iostream>

int main()
{
	Rational Rat1;
	Rational Rat2(1, 3);
	Rational Rat3(Rat1);
	std::cout << "Rat1:" << Rat1 << std::endl;
	std::cout << "Rat2:" << Rat2 << std::endl;
	std::cout << "Rat3:" << Rat3 << std::endl;

	Rat1 = Rat2 * 2;
	Rational Rat4 = Rat1 + Rat2;
	Rational Rat5(Rat4);
	Rat5 -= Rat2;
	Rational Rat6;
	std::cin >> Rat6;
	std::cout << "Rat6:" << Rat6 << std::endl;
	Rational Rat7(Rat4);
	std::cout << "Rat7:" << Rat7 << std::endl;
	Rat7 *= Rat2; Rat7 *= Rat4;
	std::cout << "Rat7:" << Rat7 << std::endl;
	std::cout << "Rat7:" << Rat7.Simplificare();
	std::cout << "Rat7:" << Rat7.ShowRational();

	Rational Rat8;
	Rat8.SeterNumarator(5);
	Rat2.GeterNumitor();
	return 0;
}