#pragma once
#include "Vector.h"

class Matrix {
	Vector* matrix = 0;
	unsigned int row;
	unsigned int collum;
	bool error;

public:
	Matrix();
	Matrix(Matrix& a);
	Matrix(Matrix&& a);
	Matrix(unsigned int size);
	Matrix(unsigned int rowCount, unsigned int collumCount);
	Matrix(unsigned int rowCount, unsigned int collumCount, float value);
	~Matrix();
	float getX(unsigned int row, unsigned int collum);
	void setX(unsigned int row, unsigned int collum, float x);
	unsigned int getRowCnt();
	unsigned int getCollumCnt();
	bool isError();
	void print();

	Matrix& operator=(Matrix& a);
	Matrix& operator=(Matrix&& a);

	Matrix operator+(Matrix a);
	void operator+=(Matrix& a);
	void operator+=(Matrix&& a);

	Matrix operator-(Matrix a);
	void operator-=(Matrix& a);
	void operator-=(Matrix&& a);

	Matrix operator*(Matrix a);
	void operator*=(Matrix& a);
	void operator*=(Matrix&& a);

	Matrix operator/(Matrix a);
	void operator/=(Matrix& a);
	void operator/=(Matrix&& a);

	Matrix operator*(float a);
	void operator*=(float a);

	Matrix operator/(float a);
	void operator/=(float a);

	Matrix operator+(float a);
	void operator+=(float a);

	Matrix operator-(float a);
	void operator-=(float a);

	bool operator==(Matrix& a);
	bool operator!=(Matrix& a);
	Matrix operator!();
	Matrix operator-();

	Vector& operator[](unsigned int index);

};



inline Matrix operator*(float i, Matrix& a) {
	a *= i;
	return a;
}

inline Matrix operator/(float i, Matrix& a) {
	a /= i;
	return a;
}

inline Matrix operator+(float i, Matrix& a) {
	a += i;
	return a;
}

inline Matrix operator-(float i, Matrix& a) {
	a -= i;
	return a;
}
