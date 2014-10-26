#include "Matrix.h"

#ifndef __VEKTOR_H__
#define __VEKTOR_H__

class Vektor :
	public Matrix
{
public:
	Vektor(int);
	virtual ~Vektor();
	void subtrahieren(Vektor);
	float betrag();
	float skalarprodukt(Vektor);
	double winkel(Vektor);
	void multiplizieren(float);
};
#endif