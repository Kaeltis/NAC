#include "Funktion2D.h"
#include "math.h"


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

float minimieren2D(const Funktion2D& funktion, float start, float schrittweite, float tol, float ftol)
{
	return 0;
}

float gradient2D(const Funktion2D funktion, float stelle)
{
	return 0;
}