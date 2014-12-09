#include "Matrix.h"
#ifndef __VEKTOR_H__
#define __VEKTOR_H__

class Vektor :
	public Matrix
{
public:
	Vektor(int);
	virtual ~Vektor();
	float& operator()(int);
	const float& operator()(int) const;
	void subtrahieren(Vektor);
	float betrag() const;
	float skalarprodukt(Vektor) const;
	double winkel(Vektor) const;
	void multiplizieren(float);
};
#endif
