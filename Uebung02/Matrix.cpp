#include "Matrix.h"
#include <iostream>
using namespace std;

int Matrix::counter = 0;

Matrix::Matrix(int m, int n)
	:m_Zeilen(m), m_Spalten(n), m_Element(new float[m * n])
{
	/*
	cout << "Standardkonstruktor von Matrix wurde aufgerufen" << endl;
	*/

	counter++;
}

Matrix::~Matrix()
{
	/*
	cout << "Matrix (";
	ausgabe(false);
	cout << ") wurde zerstoert" << endl;
	*/
	counter--;
}

void Matrix::ausgabe(bool endline)
{
	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		if (i % 2 != 0)
		{
			cout << " " << m_Element[i];
		}
		else
		{
			cout << m_Element[i];
		}
	}
	if (endline)
	{
		cout << endl;
	}
}

int Matrix::getCounter()
{
	return counter;
}