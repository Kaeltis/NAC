#include "Matrix.h"

#ifndef __VEKTOR_H__
#define __VEKTOR_H__

class Vektor :
	public Matrix
{
public:
	Vektor();
	float betrag();
	float skalarprodukt(Vektor);
	float winkel(Vektor);
};
#endif