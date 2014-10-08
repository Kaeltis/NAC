#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix
{
protected:
	int m_Zeilen;
	int m_Spalten;
	float m_Element[2];
public:
	Matrix();
	~Matrix();
	void ausgabe();
};
#endif