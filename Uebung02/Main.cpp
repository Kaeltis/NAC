#include "Matrix.h"
#include "Vektor.h"
#include "Vektor2D.h"
#include "Gerade2D.h"
#include <iostream>

//#define UEBUNG1u2
//#define UEBUNG3
//#define UEBUNG4
//#define UEBUNG5
//#define UEBUNG6
//#define UEBUNG7
#define UEBUNG8
#include "Funktion2D.h"

using namespace std;

int main()
{
	{
#ifdef UEBUNG1u2
		// Anfang Uebung 2
		cout << "--- Uebung 1/2 ---" << endl;
		Matrix myMatrix(2,1);
		myMatrix.ausgabe(true);

		Vektor myVektor(2);

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

		z->ausgabe(true);
		a.ausgabe(true);
#endif

#ifdef UEBUNG4
		// Anfang Uebung 4
		cout << endl << "--- Uebung 4 ---" << endl;

		Vektor2D v(1, 2), w(3, 4);
		Matrix M(2,1);
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
#ifdef UEBUNG5
		Vektor2D vektorArray[3];

		Vektor2D* varr[2];
		varr[0] = new Vektor2D(2, 3);
		varr[1] = new Vektor2D(-2, 1);

		varr[0]->addiere(*varr[1]);
		varr[0]->ausgabe(true);

		delete varr[0];
		delete varr[1];

		Gerade2D g(Vektor2D(-3, -4), Vektor2D(0, 0));
		cout << g.gerichteterAbstand(Vektor2D(4,3)) << endl;
#endif

#ifdef UEBUNG6
		cout << Gerade2D(Vektor2D(-3, -4)).aufGerade(Vektor2D(4, -3)) << endl;

		void geradenTest(const Gerade2D& g);
		geradenTest(Gerade2D(Vektor2D(-3, -4), Vektor2D(2, 3)));
#endif

#ifdef UEBUNG7
		Matrix M(1, 2);
		M(1, 1) = 1;
		M(1, 2) = 125;

		Matrix N(2, 1);
		N(1, 1) = 2;
		N(2, 1) = 255;

		cout << M(1, 1) << endl;
		cout << M(1, 2) << endl;

		cout << N(1, 1) << endl;
		cout << N(2, 1) << endl;

		Vektor2D v(1, 2), w(3, 4);

		cout << w(2) << endl;

		void matrixTest();
		matrixTest();
#endif

#ifdef UEBUNG8
		Funktion2D f;

		minimieren2D(f, Vektor2D(4, 0), 1);
		cout << "----------------------------------" << endl;
		minimieren2D(f, Vektor2D(4, 1), 1);
		cout << "----------------------------------" << endl;
		minimieren2D(f, Vektor2D(3.0, 1.0), 1);
		cout << "----------------------------------" << endl;
#endif


		cout << endl << "--- ENDE ---" << endl;
	}

	cout << "Anzahl der Matrix Instanzen: " << Matrix::getCounter() << endl;

	return 0;
}