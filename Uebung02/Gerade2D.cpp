#include "Gerade2D.h"


Gerade2D::Gerade2D(Vektor2D normale, Vektor2D aufpunkt)
	:m_Normale(normale), m_Aufpunkt(aufpunkt)
{
}

Gerade2D::~Gerade2D()
{
}

float Gerade2D::gerichteterAbstand(Vektor2D punkt) const
{
	Vektor2D t_Normale = m_Normale;

	punkt.subtrahieren(m_Aufpunkt);
	t_Normale.multiplizieren(1 / t_Normale.betrag());
	return t_Normale.skalarprodukt(punkt);
}

bool Gerade2D::aufGerade(const Vektor2D& x) const
{
	return gerichteterAbstand(x) == 0;
}

Vektor2D const& Gerade2D::normale() const
{
	return m_Normale;
}

Vektor2D& Gerade2D::normale()
{
	return m_Normale;
}

Vektor2D& Gerade2D::aufpunkt()
{
	return m_Aufpunkt;
}

Vektor2D const& Gerade2D::aufpunkt() const
{
	return m_Aufpunkt;
}