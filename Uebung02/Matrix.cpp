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
}

void Matrix::ausgabe()
{
	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		cout << "Element " << i << ": " << m_Element[i] << endl;
	}
}