#include "Matrix.h"
#include "Vektor.h"
#include "Vektor2D.h"
#include <iostream>

//#define UEBUNG1u2
//#define UEBUNG3
#define UEBUNG4

using namespace std;

int main()
{
	{
#ifdef UEBUNG1u2
		// Anfang Uebung 2
		cout << "--- Uebung 1/2 ---" << endl;
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
#endif

#ifdef UEBUNG3
		// Anfang Uebung 3
		cout << endl << "--- Uebung 3 ---" << endl;

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

		z->ausgabe();
		a.ausgabe();
#endif

#ifdef UEBUNG4
		// Anfang Uebung 4
		cout << endl << "--- Uebung 4 ---" << endl;

		Vektor2D v(1, 2), w(3, 4);
		Matrix M;
		Matrix* Mpointer;

		M = v;
		Mpointer = &v;

		std::cout << "Ausgabe von M und mit Mpointer" << std::endl;
		M.ausgabe(true);
		Mpointer->ausgabe(true);

		v.addiere(w);
		std::cout << "Ausgabe von v nach Addieren" << std::endl;
		v.ausgabe(true);

		std::cout << "Ausgabe von M/Mpointer nach Add." << std::endl;
		M.ausgabe(true);
		Mpointer->ausgabe(true);

		Vektor2D o(1, 1), p(-5, 0);

		cout << "Winkel: " << o.winkel(p) << endl;
#endif

		cout << endl << "--- ENDE ---" << endl;
	}

	cout << "Anzahl der Matrix Instanzen: " << Matrix::getCounter() << endl;

	return 0;
}