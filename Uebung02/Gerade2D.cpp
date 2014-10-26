#include "Gerade2D.h"


Gerade2D::Gerade2D(Vektor2D normale, Vektor2D aufpunkt)
	:m_Normale(normale), m_Aufpunkt(aufpunkt)
{
}

Gerade2D::~Gerade2D()
{
}

float Gerade2D::gerichteterAbstand(Vektor2D punkt)
{
	Vektor2D t_Normale = m_Normale;

	punkt.subtrahieren(m_Aufpunkt);
	t_Normale.multiplizieren(1 / t_Normale.betrag());
	return t_Normale.skalarprodukt(punkt);
}