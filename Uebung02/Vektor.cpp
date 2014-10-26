#include "Vektor.h"
#define _USE_MATH_DEFINES
#include <limits>
#include <cmath>

Vektor::Vektor(int m)
	:Matrix(m, 1)
{
}

Vektor::~Vektor()
{
}

void Vektor::subtrahieren(Vektor vektor)
{
	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		m_Element[i] -= vektor.m_Element[i];
	}
}

float Vektor::betrag()
{
	return sqrt(skalarprodukt(*this));
}

float Vektor::skalarprodukt(Vektor vektor)
{
	if (m_Zeilen != vektor.m_Zeilen || m_Spalten != vektor.m_Spalten)
	{
		return std::numeric_limits<float>::quiet_NaN();
	}

	float value = 0;

	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		value = value + (m_Element[i] * vektor.m_Element[i]);
	}

	return value;
}

double Vektor::winkel(Vektor vektor)
{
	if (m_Zeilen != vektor.m_Zeilen || m_Spalten != vektor.m_Spalten)
	{
		return std::numeric_limits<float>::quiet_NaN();
	}

	return acos(skalarprodukt(vektor) / (betrag() * vektor.betrag())) / M_PI * 180;
}

void Vektor::multiplizieren(float wert)
{
	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		m_Element[i] *= wert;
	}
}