#ifndef __GERADE2D_H__
#define __GERADE2D_H__
#include "Vektor2D.h"

class Gerade2D
{
protected:
	Vektor2D m_Normale;
	Vektor2D m_Aufpunkt;
public:
	Gerade2D(Vektor2D, Vektor2D);
	virtual ~Gerade2D();
	float gerichteterAbstand(Vektor2D);
};
#endif