// Complex

#include <iostream>
#include "Complex.h"

int main()
{
	Complex c1(4.0, 2.0);
	std::cout << "c1: " << c1 << std::endl;
	Complex c2;
	std::cout << "c2: " << c2 << std::endl;
	Complex c3(c1);
	std::cout << "c3: " << c3 << std::endl;
	c2 = c3 + 2;
	std::cout << "c2: " << c2 << std::endl;
	c2 = c2 * 2;
	std::cout << "c2: " << c2 << std::endl;
	Complex c4 = c1 * c2;
	std::cout << "c4: " << c4 << std::endl;
	Complex c5 = c1 / c2;
	std::cout << "c5: " << c5 << std::endl;
	Complex c6;
	std::cin >> c6;
	std::cout << "c6: " << c6 << std::endl;
	std::cout << std::endl;
	std::cout << "c1: " << c1 << std::endl;
	std::cout << "c2: " << c2 << std::endl;
	std::cout << "c3: " << c3 << std::endl;
	std::cout << "c4: " << c4 << std::endl;
	std::cout << "c5: " << c5 << std::endl;
	std::cout << "c6: " << c6 << std::endl;
	Complex c7;
	c7.SetReal(3); c7.SetImag(5);
	std::cout << "c7: " << c7 << std::endl;
	return 0;
}