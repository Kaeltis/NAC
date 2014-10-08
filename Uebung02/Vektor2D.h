#include "Vektor.h"

#ifndef __VEKTOR2D_H__
#define __VEKTOR2D_H__

class Vektor2D :
	public Vektor
{
public:
	Vektor2D();
	Vektor2D(float, float);
	~Vektor2D();
	void addiere(Vektor2D);
};
#endif