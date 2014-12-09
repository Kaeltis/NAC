#ifndef __MATRIX_H__
#define __MATRIX_H__

class Vektor;

class Matrix
{
private:
	static int counter;
protected:
	int m_Zeilen;
	int m_Spalten;
	float* m_Element;
public:
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);
	float& operator()(int, int);
	const float& operator()(int, int) const;
	virtual ~Matrix();
	virtual void ausgabe(bool) const;
	static int getCounter();
	Matrix operator*(const Matrix&) const;
	Vektor operator*(const Vektor&) const;
};
#endif
