#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
	:m_Zeilen(2), m_Spalten(1)
{
	m_Element[0] = 0;
	m_Element[1] = 0;

	cout << "Standardkonstruktor von Matrix wurde aufgerufen" << endl;
}

Matrix::~Matrix()
{
	cout << "Matrix (";
	ausgabe(false);
	cout << ") wurde zerstoert" << endl;
}

void Matrix::ausgabe(bool endline)
{
	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		if (endline)
		{
			cout << "Element " << i << ": " << m_Element[i] << endl;
		}
		else
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
	}
}