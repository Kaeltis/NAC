#include "Funktion2D.h"
#include "math.h"
#include <iostream>

Funktion2D::Funktion2D()
{
}


Funktion2D::~Funktion2D()
{
}

float Funktion2D::operator()(Vektor2D vektor) const
{
	vektor + Vektor2D(1, 0);
	return -(sin(vektor.betrag()) / vektor.betrag());
}

float minimieren2D(const Funktion2D& funktion, const Vektor2D& stelle, float schrittweite, float tol, float ftol)
{
	int i = 0;
	Vektor2D schritt = stelle;
	Vektor2D tempschritt;
	Vektor2D gradient;
	float funktionswertalt = 0;
	float funktionswertneu = 1;

	while (schritt.betrag() >= tol && fabs(funktionswertneu - funktionswertalt) > ftol)
	{
		funktionswertalt = funktion(schritt);

		gradient = gradient2D(funktion, schritt);
		tempschritt = schritt;
		schritt = Vektor2D(-gradient(1), -gradient(2));
		schritt * schrittweite;
		schritt + tempschritt;

#ifdef DEBUG
		std::cout << "Iteration " << i << std::endl;
		schritt.ausgabe(true);
		i++;
#endif

		funktionswertneu = funktion(schritt);
	}

	std::cout << "Stelle: " << std::endl;
	schritt.ausgabe(true);
	std::cout << "Funktionswert: " << funktionswertneu << std::endl << std::endl;
	return funktionswertneu;
}

Vektor2D gradient2D(const Funktion2D& funktion, const Vektor2D& stelle)
{
	float x = (funktion(Vektor2D(stelle(1) + myh(1), stelle(2))) - funktion(Vektor2D(stelle(1), stelle(2)))) / myh(1);
	float y = (funktion(Vektor2D(stelle(1), stelle(2) + myh(1))) - funktion(Vektor2D(stelle(1), stelle(2)))) / myh(1);

	return Vektor2D(x, y);
}