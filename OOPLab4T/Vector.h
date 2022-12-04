#pragma once

class Vector {
	float* arr = 0;
	unsigned int length;

	bool error = 0;

public:
	Vector();
	Vector(unsigned int Length);
	Vector(unsigned int Length, float initVal);
	Vector(Vector& copyFrom);
	Vector(Vector&& copyFrom);

	void init(int Length);
	void setX(int position, float x);
	float getX(int position);
	bool isError();
	~Vector();

	
	void operator=(Vector& a);
	void operator=(Vector&& a);
	


	Vector operator+(Vector a);
	void operator+=(Vector& a);
	void operator+=(Vector&& a);

	Vector operator-(Vector a);
	void operator-=(Vector& a);
	void operator-=(Vector&& a);

	Vector operator*(Vector a);
	void operator*=(Vector& a);
	void operator*=(Vector&& a);

	Vector operator/(Vector a);
	void operator/=(Vector& a);
	void operator/=(Vector&& a);



	void operator=(float a);

	Vector operator+(float a);
	void operator+=(float a);

	Vector operator-(float a);
	void operator-=(float a);

	Vector operator*(float a);
	void operator*=(float a);

	Vector operator/(float a);
	void operator/=(float a);

	void operator++(int i);
	void operator--(int i);
	Vector operator!();
	Vector operator-();
	bool operator==(Vector& a);
	bool operator!=(Vector& a);

	float& operator[](unsigned int index);
};


inline Vector operator+(float i, Vector& a) {
	a += i;
	return a;
}

inline Vector operator-(float i, Vector& a) {
	a -= i;
	return a;
}

inline Vector operator*(float i, Vector& a) {
	a *= i;
	return a;
}

inline Vector operator/(float i, Vector& a) {
	a /= i;
	return a;
}


