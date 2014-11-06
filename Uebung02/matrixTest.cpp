#include <iostream>
#include <math.h>
#include "Matrix.h"
#include "Vektor.h"

static void falsch()
{
	std::cout << "falsch" << std::endl;
}

#define TEST(bedingung)                   \
  if(bedingung)                           \
    std::cout << "richtig" << std::endl;  \
    else                                    \
    falsch();

void matrixTest()
{
	Matrix m1(3, 3);
	m1(1, 1) = 1; m1(1, 2) = 2;  m1(1, 3) = 3;
	m1(2, 1) = 4; m1(2, 2) = 5;  m1(2, 3) = 6;
	m1(3, 1) = 7; m1(3, 2) = 8;  m1(3, 3) = 9;
	Vektor v(3);
	v(1) = 2; v(2) = 3; v(3) = 1;

	Vektor r(3);
	r = m1*v;

	const Vektor cv(r);

	Vektor vexpected(3);
	vexpected(1) = 11; vexpected(2) = 29; vexpected(3) = 47;

	r.subtrahieren(vexpected);
	TEST(r.betrag() < 0.0001);

	TEST(fabs(cv(1) - vexpected(1)) < 0.0001);

	const Matrix cm(m1);
	TEST(fabs(m1(1, 1) - cm(1, 1)) < 0.0001);

	Matrix m2(3, 2);
	m2(1, 1) = 1; m2(1, 2) = 2;
	m2(2, 1) = 4; m2(2, 2) = 5;
	m2(3, 1) = 7; m2(3, 2) = 8;

	Matrix mr(m1*m2);

	Matrix mexpected(3, 2);
	mexpected(1, 1) = 30; mexpected(1, 2) = 36;
	mexpected(2, 1) = 66; mexpected(2, 2) = 81;
	mexpected(3, 1) = 102; mexpected(3, 2) = 126;

	int i, j;
	for (i = 1; i<3; ++i)
		for (j = 1; j<2; ++j)
		{
		TEST(fabs(mr(i, j) - mexpected(i, j)) < 0.0001);
		}

	try
	{
		mr(3, 3);
		falsch();
	}
	catch (float nan)
	{
		if (nan == nan)
		{
			falsch();
		}
	}

	try
	{
		cv(7);
		falsch();
	}
	catch (float nan)
	{
		if (nan == nan)
		{
			falsch();
		}
	}

	TEST(fabs(v.skalarprodukt(vexpected) - 156) < 0.0001);
}