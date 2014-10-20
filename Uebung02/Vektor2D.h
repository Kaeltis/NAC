#include "Vektor.h"

#ifndef __VEKTOR2D_H__
#define __VEKTOR2D_H__

class Vektor2D :
	public Vektor
{
public:
	Vektor2D();
	Vektor2D(float, float);
	void addiere(Vektor2D);
	void kopiereIn(Vektor2D*);	
	void ausgabe(bool);
};

void tausche(Vektor2D*, Vektor2D*);
#endif