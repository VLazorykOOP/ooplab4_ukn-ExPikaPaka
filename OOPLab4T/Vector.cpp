#include "Vector.h"
#include <iostream>
#include <Windows.h>

Vector::Vector() {
	length = 1;
	arr = new float[length];
	for (unsigned int i = 0; i < length; i++) {
		setX(i, 0);
	}
}

Vector::Vector(unsigned int Length) {
	if (Length > 0 && Length <= 65535) {
		length = Length;
	}
	else {
		length = 65535;
		error = 1;
	}
	arr = new float[length];
	for (unsigned int i = 0; i < length; i++) {
		setX(i, 0);
	}
}

Vector::Vector(unsigned int Length, float initVal) {
	if (Length > 0 && Length <= 65535) {
		length = Length;
	}
	else {
		length = 65535;
		error = 1;
	}
	arr = new float[length];
	for (unsigned int i = 0; i < length; i++) {
		setX(i, initVal);
	}
}

Vector::Vector(Vector &copyFrom) {
	init(copyFrom.length);
	length = copyFrom.length;
	error = copyFrom.error;

	for (unsigned int i = 0; i < copyFrom.length; i++) {
		setX(i, copyFrom.getX(i));
	}
}

Vector::Vector(Vector&& copyFrom) {
	init(copyFrom.length);
	length = copyFrom.length;
	error = copyFrom.error;

	for (unsigned int i = 0; i < copyFrom.length; i++) {
		setX(i, copyFrom.getX(i));
	}
}

void Vector::init(int Length) {
	if (arr != NULL) {
		delete[] arr;
	}

	if (Length > 0 && Length <= 65535) {
		length = Length;
	}
	else {
		length = 65535;
		error = 1;
	}
	arr = new float[length];

	for (unsigned int i = 0; i < length; i++) {
		setX(i, 0);
	}
}

void Vector::setX(int position, float x) {
	if (position >= 0 && position <= 65535) {
		arr[position] = x;
	}
	else {
		error = 1;
	}
}

float Vector::getX(int position) {
	if (position >= 0 && position <= 65535) {
		return arr[position];
	}
	else {
		error = 1;
		return 0;
	}

}

Vector::~Vector() {
	delete[] arr;	
}



void Vector::operator=(Vector& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			this->setX(i, a.getX(i));
		}
	}
	else {
		error = 1;
	}
}

bool Vector::isError() {
	return error ? 1 : 0;
}

void Vector::operator=(Vector&& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			this->setX(i, a.getX(i));
		}
	}
	else {
		error = 1;
	}
}





Vector Vector::operator+(Vector a) {
	Vector tmp(this->length);

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			tmp.setX(i, getX(i) + a.getX(i));
		}
	}
	else {
		error = 1;
	}

	return tmp;
}


void Vector::operator+=(Vector &a) {
	
	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			setX(i, getX(i) + a.getX(i));
		}
	}
	else {
		error = 1;
	}
}

void Vector::operator+=(Vector&& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			setX(i, getX(i) + a.getX(i));
		}
	}
	else {
		error = 1;
	}
}



Vector Vector::operator-(Vector a) {
	Vector tmp(this->length);

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			tmp.setX(i, getX(i) - a.getX(i));
		}
	}
	else {
		error = 1;
	}

	return tmp;
}

void Vector::operator-=(Vector& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			setX(i, getX(i) - a.getX(i));
		}
	}
	else {
		error = 1;
	}
}

void Vector::operator-=(Vector&& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			setX(i, getX(i) - a.getX(i));
		}
	}
	else {
		error = 1;
	}
}



Vector Vector::operator/(Vector a) {
	Vector tmp(this->length);

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			tmp.setX(i, getX(i) / a.getX(i));
		}
	}
	else {
		error = 1;
	}

	return tmp;
}

void Vector::operator/=(Vector& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			setX(i, getX(i) / a.getX(i));
		}
	}
	else {
		error = 1;
	}
}

void Vector::operator/=(Vector&& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			setX(i, getX(i) / a.getX(i));
		}
	}
	else {
		error = 1;
	}
}



Vector Vector::operator*(Vector a) {
	Vector tmp(this->length);

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			tmp.setX(i, getX(i) * a.getX(i));
		}
	}
	else {
		error = 1;
	}

	return tmp;
}

void Vector::operator*=(Vector& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			setX(i, getX(i) * a.getX(i));
		}
	}
	else {
		error = 1;
	}
}

void Vector::operator*=(Vector&& a) {

	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < a.length; i++) {
			setX(i, getX(i) * a.getX(i));
		}
	}
	else {
		error = 1;
	}
}








void Vector::operator=(float a) {

	for (unsigned int i = 0; i < length; i++) {
		setX(i, a);
	}
}



Vector Vector::operator+(float a) {
	Vector tmp(length);

	for (unsigned int i = 0; i < length; i++) {
		tmp.setX(i, getX(i) + a);
	}
	
	return tmp;
}

void Vector::operator+=(float a) {

	for (unsigned int i = 0; i < length; i++) {
		setX(i, getX(i) + a);
	}
}



Vector Vector::operator-(float a) {
	Vector tmp(length);

	for (unsigned int i = 0; i < length; i++) {
		tmp.setX(i, getX(i) - a);
	}

	return tmp;
}

void Vector::operator-=(float a) {

	for (unsigned int i = 0; i < length; i++) {
		setX(i, getX(i) - a);
	}
}



Vector Vector::operator*(float a) {
	Vector tmp(length);

	for (unsigned int i = 0; i < length; i++) {
		tmp.setX(i, getX(i) * a);
	}

	return tmp;
}

void Vector::operator*=(float a) {

	for (unsigned int i = 0; i < length; i++) {
		setX(i, getX(i) * a);
	}
}



Vector Vector::operator/(float a) {
	Vector tmp(length);

	for (unsigned int i = 0; i < length; i++) {
		tmp.setX(i, getX(i) / a);
	}

	return tmp;
}

void Vector::operator/=(float a) {

	for (unsigned int i = 0; i < length; i++) {
		setX(i, getX(i) / a);
	}
}





void Vector::operator++(int i) {
	for (unsigned int i = 0; i < length; i++) {
		setX(i, getX(i) + 1);
	}
}

void Vector::operator--(int i) {
	for (unsigned int i = 0; i < length; i++) {
		setX(i, getX(i) - 1);
	}
}





Vector Vector::operator!() {
	Vector tmp(*this);
	for (unsigned int i = 0; i < length; i++) {
		tmp.setX(i, !getX(i));
	}
	return tmp;
}

Vector Vector::operator-() {
	Vector tmp(*this);
	for (unsigned int i = 0; i < length; i++) {
		tmp.setX(i, -getX(i));
	}
	return tmp;
}


bool Vector::operator==(Vector& a) {
	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < length; i++) {
			if (getX(i) != a.getX(i)) return 0;
		}
	}
	return 1;
}

bool Vector::operator!=(Vector& a) {
	if (length > a.length || length == a.length) {
		for (unsigned int i = 0; i < length; i++) {
			if (getX(i) != a.getX(i)) return 1;
		}
	}
	return 0;
}



float& Vector::operator[](unsigned int index) {
	if ((index >= length) || (index < 0)) {
		error = 1;
		return arr[0];
	}
	return arr[index];
}