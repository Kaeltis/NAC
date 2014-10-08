#include "Matrix.h"
#include "Vektor.h"
#include "Vektor2D.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix myMatrix;
	myMatrix.ausgabe();

	Vektor myVektor;

	cout << "Betrag von Vektor: " << myVektor.betrag() << endl;

	Vektor2D a(3, 1), b(1, 2), c;

	a.ausgabe();
	b.ausgabe();
	c.ausgabe();

	c.addiere(a);

	b.addiere(c);

	cout << "Betrag von Vektor2D b: " << b.betrag() << endl;

	return 0;
}