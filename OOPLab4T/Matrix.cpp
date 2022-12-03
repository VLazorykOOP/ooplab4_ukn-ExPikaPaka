#include "Matrix.h"
#include "ColorText.h"
#include <iostream>

Matrix::Matrix() {
	error = 0;
}	

Matrix::Matrix(unsigned int rowCount, unsigned int collumCount) {
	if ((rowCount > 0 && rowCount < 65535) && (collumCount > 0 && collumCount < 65535)) {
		row = rowCount;
		collum = collumCount;
		error = 0;

		matrix = new Vector[row];

		for (int i = 0; i < row; i++) {
			matrix[i].init(collum);
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, 0);
			}
		}
	}
	else {
		error = 1;
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Розмір матриці некоректний! Об`єкт не створено.\n", 113);
	}
}


Matrix::Matrix(unsigned int size) {
	if (size > 0 && size < 65535) {
		row = size;
		collum = size;
		error = 0;

		matrix = new Vector[row];
	
		for (int i = 0; i < row; i++) {
			matrix[i].init(collum);
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, 0);
			}
		}
	}
	else {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Розмір матриці некоректний! Об`єкт не створено.\n", 113);
	}
}


Matrix::Matrix(unsigned int rowCount, unsigned int collumCount, float value) {
	
	if ((rowCount > 0 && rowCount < 65535) && (collumCount > 0 && collumCount < 65535)) {
		row = rowCount;
		collum = collumCount;
		error = 0;

		matrix = new Vector[row];

		for (int i = 0; i < row; i++) {
			matrix[i].init(collum);
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, value);
			}
		}
	}
	else {
		std::cout << ' ';
		CText("[ERROR]", 64);
		CText(" Розмір матриці некоректний! Об`єкт не створено.\n", 113);
	}
}

Matrix::Matrix(Matrix& a) {
	row = a.row;
	collum = a.collum;
	error = a.error;

	matrix = new Vector[row];

	for (int i = 0; i < row; i++) {
		matrix[i].init(collum);
	}

	for (unsigned int i = 0; i < a.row; i++) {
		for (unsigned int j = 0; j < a.collum; j++) {
			setX(i, j, a.getX(i, j));
		}
	}
}

Matrix::Matrix(Matrix&& a) {
	row = a.row;
	collum = a.collum;
	error = a.error;

	matrix = new Vector[row];

	for (int i = 0; i < row; i++) {
		matrix[i].init(collum);
	}

	for (unsigned int i = 0; i < a.row; i++) {
		for (unsigned int j = 0; j < a.collum; j++) {
			setX(i, j, a.getX(i, j));
		}
	}
}

Matrix::~Matrix() {
	delete[] matrix;
}

float Matrix::getX(unsigned int row, unsigned int collum) {
	return matrix[row].getX(collum);
}

void Matrix::setX(unsigned int row, unsigned int collum, float x) {
	matrix[row].setX(collum, x);
}

unsigned int Matrix::getRowCnt() {
	return row;
}

unsigned int Matrix::getCollumCnt() {
	return collum;
}

bool Matrix::isError() {
	return error ? 1 : 0;
}

void Matrix::print() {
	for (unsigned int i = 0; i < row; i++) {
		for (unsigned int j = 0; j < collum; j++) {
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

Matrix& Matrix::operator=(Matrix& a) {
	row = a.row;
	collum = a.collum;
	error = a.error;

	for (unsigned int i = 0; i < a.row; i++) {
		for (unsigned int j = 0; j < a.collum; j++) {
			setX(i, j, a.getX(i, j));
		}
	}
	return *this;
}

Matrix& Matrix::operator=(Matrix&& a) {
	row = a.row;
	collum = a.collum;
	error = a.error;

	for (unsigned int i = 0; i < a.row; i++) {
		for (unsigned int j = 0; j < a.collum; j++) {
			setX(i, j, a.getX(i, j));
		}
	}
	return *this;
}

Matrix Matrix::operator+(Matrix a) {
	Matrix tmp(*this);
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				tmp.setX(i, j, getX(i, j) + a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return tmp;
}

Matrix& Matrix::operator+=(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) + a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}

Matrix& Matrix::operator+=(Matrix&& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) + a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}

Matrix Matrix::operator-(Matrix a) {
	Matrix tmp(*this);
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				tmp.setX(i, j, getX(i, j) - a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return tmp;
}

Matrix& Matrix::operator-=(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) - a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}

Matrix& Matrix::operator-=(Matrix&& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) - a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}

Matrix Matrix::operator*(Matrix a) {
	Matrix tmp(*this);
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				tmp.setX(i, j, getX(i, j) * a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return tmp;
}

Matrix& Matrix::operator*=(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) * a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}

Matrix& Matrix::operator*=(Matrix&& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) * a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}

Matrix Matrix::operator/(Matrix a) {
	Matrix tmp(*this);
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				tmp.setX(i, j, getX(i, j) / a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return tmp;
}

Matrix& Matrix::operator/=(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) / a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}

Matrix& Matrix::operator/=(Matrix&& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) / a.getX(i, j));
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}


Matrix Matrix::operator*(float a) {
	Matrix tmp(*this);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			tmp.setX(i, j, getX(i, j) * a);
		}

	}
	return tmp;
}

Matrix& Matrix::operator*=(float a) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			setX(i, j, getX(i, j) * a);
		}
	}

	return *this;
}

Matrix Matrix::operator/(float a) {
	Matrix tmp(*this);
	if (a) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				tmp.setX(i, j, getX(i, j) / a);
			}
		}
	}
	else {
		tmp.error = 1;
	}
	return tmp;
}

Matrix& Matrix::operator/=(float a) {
	if (a) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				setX(i, j, getX(i, j) / a);
			}
		}
	}
	else {
		error = 1;
	}
	return *this;
}

Matrix Matrix::operator+(float a) {
	Matrix tmp(*this);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			tmp.setX(i, j, getX(i, j) + a);
		}

	}
	return tmp;
}

void Matrix::operator+=(float a) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			setX(i, j, getX(i, j) + a);
		}

	}
}

Matrix Matrix::operator-(float a) {
	Matrix tmp(*this);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			tmp.setX(i, j, getX(i, j) - a);
		}

	}
	return tmp;
}

void Matrix::operator-=(float a) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			setX(i, j, getX(i, j) - a);
		}

	}
}



bool Matrix::operator==(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				if (getX(i, j) != a.getX(i, j)) return 0;
			}
		}
		return 1;
	}
	return 0;
}

bool Matrix::operator!=(Matrix& a) {
	if ((row == a.row) && (collum = a.collum)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < collum; j++) {
				if (getX(i, j) != a.getX(i, j)) return 1;
			}
		}
		return 0;
	}
	return 1;
}

Matrix Matrix::operator!() {
	Matrix tmp(*this);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			tmp.setX(i, j, !getX(i, j));
		}
	}
	return tmp;
}

Matrix Matrix::operator-() {
	Matrix tmp(*this);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			tmp.setX(i, j, -getX(i, j));
		}
	}
	return tmp;
}

Vector& Matrix::operator[](unsigned int index) {
	return matrix[index];
}
