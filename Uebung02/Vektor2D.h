#ifndef __VEKTOR2D_H__
#define __VEKTOR2D_H__
#include "Vektor.h"

class Vektor2D :
	public Vektor
{
public:
	Vektor2D();
	Vektor2D(float, float);
	virtual ~Vektor2D();
	void addiere(Vektor2D);
	void kopiereIn(Vektor2D*) const;
	void ausgabe(bool) const;
	void operator*(const float&);
	void operator+(const Vektor2D&);
};

void tausche(Vektor2D*, Vektor2D*);
#endif