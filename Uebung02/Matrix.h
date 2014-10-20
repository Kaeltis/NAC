#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix
{
private:
	static int counter;
protected:
	int m_Zeilen;
	int m_Spalten;
	float m_Element[2];
public:
	Matrix();
	~Matrix();
	virtual void ausgabe(bool);
	static int getCounter();
};
#endif