#include "NSFunktion2D.h"
#include <stdexcept>
#include <iostream>

NSFunktion2D::NSFunktion2D()
{
}


NSFunktion2D::~NSFunktion2D()
{
}

float NSFunktion2D::operator()(float x) const
{
	return 2 * cos(x) * cos(x) * x * x + sin(x) * x - x;
}

float bisektion(const NSFunktion2D& f, float a, float b)
{
	if (f(a) * f(b) >= 0)
	{
		//throw std::invalid_argument("f(a)*f(b) muss < 0 sein!");
		return std::numeric_limits<float>::quiet_NaN();
	}

	float u, ergebnis;

	do
	{
		u = (a + b) / 2;
		ergebnis = f(u);

		if (!isValueZero(ergebnis))
		{
			if (ergebnis * f(b) < 0)
			{
				a = u;
			}
			else if (f(a) * ergebnis < 0)
			{
				b = u;
			}
			else
			{
				//throw std::invalid_argument("Nullstelle im Intervall nicht gefunden!");
				return std::numeric_limits<float>::quiet_NaN();
			}
		}
	}
	while (!isValueZero(ergebnis));

	return u;
}

float sekantenmethode(const NSFunktion2D& f, float x0, float x1)
{
	float x;

	do
	{
		x = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

		x0 = x1;
		x1 = x;
	}
	while (!isValueZero(fabs(x - x1)));

	return x;
}

bool isValueZero(float x)
{
	return !(fabs(x) > 0.00001);
}
