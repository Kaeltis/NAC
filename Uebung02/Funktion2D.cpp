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
	return 0;
}

Vektor2D gradient2D(const Funktion2D& funktion, const Vektor2D& stelle)
{
	float x = (funktion(Vektor2D(stelle(1) + myh(1), stelle(2))) - funktion(stelle)) / myh(1);
	float y = (funktion(Vektor2D(stelle(1), stelle(2) + myh(1))) - funktion(stelle)) / myh(1);

	return Vektor2D(x,y);
}