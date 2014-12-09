#ifndef __NSFUNKTION2D_H__
#define __NSFUNKTION2D_H__
#include "Vektor2D.h"
#include "float.h"
#include "math.h"

class NSFunktion2D
{
public:
	NSFunktion2D();
	virtual ~NSFunktion2D();
	float operator()(float) const;
};

float bisektion(const NSFunktion2D&, float, float);
float sekantenmethode(const NSFunktion2D&, float, float);
bool isValueZero(float);

#endif