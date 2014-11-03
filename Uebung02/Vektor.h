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
	float betrag() const;
	float skalarprodukt(Vektor) const;
	double winkel(Vektor) const;
	void multiplizieren(float);
};
#endif