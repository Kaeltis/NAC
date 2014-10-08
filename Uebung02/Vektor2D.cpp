#include "Vektor2D.h"


Vektor2D::Vektor2D()
{
}

Vektor2D::Vektor2D(float element1, float element2)
{
	m_Element[0] = element1;
	m_Element[1] = element2;
}

Vektor2D::~Vektor2D()
{
}

void Vektor2D::addiere(Vektor2D vektor)
{
	m_Element[0] += vektor.m_Element[0];
	m_Element[1] += vektor.m_Element[1];
}