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

float& Vektor::operator()(int i)
{
	if (m_Zeilen >= i)
	{
		return m_Element[i-1];
	}
	else
	{
		throw std::numeric_limits<float>::quiet_NaN();
	}
}

const float& Vektor::operator()(int i) const
{
	if (m_Zeilen >= i)
	{
		return m_Element[i - 1];
	}
	else
	{
		throw std::numeric_limits<float>::quiet_NaN();
	}
}

void Vektor::subtrahieren(Vektor vektor)
{
	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		m_Element[i] -= vektor.m_Element[i];
	}
}

float Vektor::betrag() const
{
	return sqrt(skalarprodukt(*this));
}

float Vektor::skalarprodukt(Vektor vektor) const
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

double Vektor::winkel(Vektor vektor) const
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