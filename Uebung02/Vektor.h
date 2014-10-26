#ifndef __VEKTOR_H__
#define __VEKTOR_H__
#include "Matrix.h"

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