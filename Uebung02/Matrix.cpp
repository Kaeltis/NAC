#include "Matrix.h"
#include "Vektor.h"
#include <limits>
#include <iostream>
using namespace std;

int Matrix::counter = 0;

Matrix::Matrix(int m, int n)
	:m_Zeilen(m), m_Spalten(n), m_Element(new float[m * n])
{
	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		m_Element[i] = 0;
	}

	counter++;
}

Matrix::Matrix(const Matrix& other)
{
	m_Zeilen = other.m_Zeilen;
	m_Spalten = other.m_Spalten;
	m_Element = new float[m_Zeilen * m_Spalten];

	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		m_Element[i] = other.m_Element[i];
	}
}


Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		m_Zeilen = other.m_Zeilen;
		m_Spalten = other.m_Spalten;

		delete [] m_Element;
		m_Element = new float[m_Zeilen * m_Spalten];

		for (int i = 0; i < m_Zeilen * m_Spalten; i++)
		{
			m_Element[i] = other.m_Element[i];
		}
	}
	return *this;
}

float& Matrix::operator()(int zeile, int spalte)
{
	if (m_Zeilen >= zeile && m_Spalten >= spalte)
	{
		return m_Element[(m_Spalten * (zeile - 1)) + (spalte - 1)];
	}
	else
	{
		throw numeric_limits<float>::quiet_NaN();
	}
}

const float& Matrix::operator()(int zeile, int spalte) const
{
	if (m_Zeilen >= zeile && m_Spalten >= spalte)
	{
		return m_Element[(m_Spalten * (zeile - 1)) + (spalte - 1)];
	}
	else
	{
		throw numeric_limits<float>::quiet_NaN();
	}
}

Matrix::~Matrix()
{
#ifdef DEBUG
		cout << "Matrix (";
		ausgabe(false);
		cout << ") wird zerstoert" << endl;
#endif

	delete [] m_Element;
	counter--;

#ifdef DEBUG
		cout << "Matrix wurde zerstoert" << endl;
#endif
}

void Matrix::ausgabe(bool endline) const
{
	int count = 0;
	for (int i = 0; i < m_Zeilen * m_Spalten; i++)
	{
		count++;
		cout << " " << m_Element[i];
		if (count >= m_Spalten)
		{
			cout << endl;
			count = 0;
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
