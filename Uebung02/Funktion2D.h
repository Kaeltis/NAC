#ifndef __FUNKTION2D_H__
#define __FUNKTION2D_H__
#include "Vektor2D.h"

class Funktion2D
{
public:
	Funktion2D();
	virtual ~Funktion2D();
	float operator()(Vektor2D) const;
};

float gradient2D(const Funktion2D&, float);
float minimieren2D(const Funktion2D&, float, float, float = 0.001, float = 0.001); //TODO: Werte anpassen
#endif