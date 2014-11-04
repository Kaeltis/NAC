#include "Matrix.h"
#include "Vektor.h"
#include <limits>
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

Matrix::Matrix(const Matrix& other)
{
	//cout << "Copy constructor called" << endl;
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
	//cout << "operator= called" << endl;
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

float& Matrix::operator()(int i, int j)
{
	//TODO: Sehr dubiose implementierung von mir
	if (m_Zeilen < m_Spalten)
	{
		if (m_Zeilen >= i && m_Spalten >= j)
		{
			return m_Element[((j - 1) * m_Spalten) + i];
		}
		else
		{
			throw numeric_limits<float>::quiet_NaN();
		}
	}
	else
	{
		if (m_Zeilen >= i && m_Spalten >= j)
		{
			return m_Element[((i - 1) * m_Zeilen) + j];
		}
		else
		{
			throw numeric_limits<float>::quiet_NaN();
		}
	}
}

const float& Matrix::operator()(int i, int j) const
{
	//TODO: Sehr dubiose implementierung von mir
	if (m_Zeilen < m_Spalten)
	{
		if (m_Zeilen >= i && m_Spalten >= j)
		{
			return m_Element[((j - 1) * m_Spalten) + i];
		}
		else
		{
			throw numeric_limits<float>::quiet_NaN();
		}
	}
	else
	{
		if (m_Zeilen >= i && m_Spalten >= j)
		{
			return m_Element[((i - 1) * m_Zeilen) + j];
		}
		else
		{
			throw numeric_limits<float>::quiet_NaN();
		}
	}
}

Matrix::~Matrix()
{
	/*
	cout << "Matrix (";
	ausgabe(false);
	cout << ") wurde zerstoert" << endl;
	*/
	delete [] m_Element;
	counter--;
}

void Matrix::ausgabe(bool endline) const
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