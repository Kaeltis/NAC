#ifndef __FUNKTION2D_H__
#define __FUNKTION2D_H__
#include "Vektor2D.h"
#include "float.h"
#include "math.h"

class Funktion2D
{
public:
	Funktion2D();
	virtual ~Funktion2D();
	float operator()(Vektor2D) const;
};

Vektor2D gradient2D(const Funktion2D&, const Vektor2D&);
float minimieren2D(const Funktion2D&, const Vektor2D&, float, float = 0.001, float = 0.001); //TODO: Werte anpassen

inline float myh(float x)
{
	return sqrt(FLT_EPSILON)*x;
}
#endif