#include "Matrix.h"
#include "Vektor.h"
#include "Vektor2D.h"
#include <iostream>
using namespace std;

int main()
{
	// Anfang Übung 2
	Matrix myMatrix;
	myMatrix.ausgabe(true);

	Vektor myVektor;

	cout << "Betrag von Vektor: " << myVektor.betrag() << endl;

	Vektor2D a(3, 1), b(1, 2), c;

	a.ausgabe(true);
	b.ausgabe(true);
	c.ausgabe(true);

	c.addiere(a);

	b.addiere(c);

	cout << "Betrag von Vektor2D b: " << b.betrag() << endl;
	b.ausgabe(true);


	// Anfang Übung 3
	cout << "--- Uebung 3 ---" << endl;

	Vektor2D* z = new Vektor2D(-3, 1);
	Vektor2D* w = new Vektor2D;

	a.addiere(*z);
	a.ausgabe(true);

	w->addiere(*z);
	w->ausgabe(true);

	w->addiere(b);
	w->ausgabe(true);

	Vektor2D u(1, 2);

	u.kopiereIn(w);
	u.kopiereIn(&a);

	w->ausgabe(true);
	a.ausgabe(true);

	z->ausgabe(true);
	a.ausgabe(true);

	cout << "Tausche z und a" << endl;
	tausche(z, &a);

	z->ausgabe(true);
	a.ausgabe(true);

	return 0;
}