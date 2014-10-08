#include "Vektor.h"
#include <cmath>

Vektor::Vektor()
{
}


Vektor::~Vektor()
{
}

float Vektor::betrag()
{
	float value = 0;

	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		value = value + (m_Element[i] * m_Element[i]);
	}

	value = sqrt(value);

	return value;
}