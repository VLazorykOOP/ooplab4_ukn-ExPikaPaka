#include <iostream>
#include <windows.h> 
#include "Vector.h"
#include "Matrix.h"
#include "MyDate.h"
#include "Route.h"

void V11_Task1() {
	Vector a(5, 1);
	Vector c(5, 2);
	Vector r(5, 0);

	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}

	Vector b(a);

	std::cout << "Before -----\n";
	for (int i = 0; i < 5; i++) {
		std::cout << "A" << i << " " << a.getX(i) << "    B" << i << " " << b.getX(i) << "    C" << i << " " << c.getX(i) << "    R" << i << " " << r.getX(i) <<  "\n";
	}

	r = a * 5 + b * 7 - 3 * c;
	
	std::cout << "\nAfter -----\n";
	for (int i = 0; i < 5; i++) {
		std::cout << "A" << i << " " << a.getX(i) << "    B" << i << " " << b.getX(i) << "    C" << i << " " << c.getX(i) << "    R" << i << " " << r.getX(i) << "\n";
	}

	std::cout << "\n(A == A) ? : " << (a == a) << '\n';
	std::cout << "\n(A != A) ? : " << (a != a) << '\n';
	std::cout << "\n(A == B) ? : " << (a == b) << '\n';

	std::cout << "\n(-A) : " << '\n';
	-a;
	for (int i = 0; i < 5; i++) {
		std::cout << "A" << i << " " << a[i] << "\n";
	}

	std::cout << "\n(A = -A) : " << '\n';
	a = -a;
	for (int i = 0; i < 5; i++) {
		std::cout << "A" << i << " " << a[i] << "\n";
	}

	std::cout << "\n(A = !A) : " << '\n';
	a = !a;
	for (int i = 0; i < 5; i++) {
		std::cout << "A" << i << " " << a[i] << "\n";
	}
}

void V11_Task2() {
	Matrix a(3, 4, 2);
	Matrix b(3, 4, 5);
	Matrix c(a);
	Matrix d = b;
	Matrix r(a);

	a.print();
	std::cout << '\n';
	b.print();
	std::cout << '\n';
	c.print();
	std::cout << '\n';
	d.print();
	std::cout << '\n';
	r.print();

	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a.setX(i, j, i * 4 + j);
		}
	}

	a[1][2] = 323;
	std::cout << a[1][2] << "\n\n";

	r = a * b + c * 3 / 2.5 * d;
	std::cout << a[0][0] * b[0][0] + c[0][0] * 3 / 2.5 * d[0][0] << " = " <<
		a[0][0] << " * " << b[0][0] << " + " << c[0][0] << " * 3 /  2.5 * " << d[0][0] << "\n\n";

	a.print();
	std::cout << '\n';
	b.print();
	std::cout << '\n';
	c.print();
	std::cout << '\n';
	d.print();
	std::cout << '\n';
	r.print();
}

void V11_Task3() {
	Route route1;
	Date departure;
	Date arrival;

	arrival.now();
	departure.setDate(2017, 9, 23, 19, 30, 0);

	route1.arrival_date = arrival;
	route1.departure_date = departure;
	route1.bus_id = 325;
	route1.description = "Route from Chicago to New York, via special bus";
	route1.route_id = 3;
	route1.route_name = "Chicago - New York";
	std::cout << route1;
}
	
int main() {
	while (1) {
		if (GetAsyncKeyState(VK_NUMPAD0) < 0) {
			system("cls");
			Matrix _4096_KB(1024, 1024, 0);
			std::cout << "Memory check ~ " << _4096_KB.getCollumCnt() * _4096_KB.getRowCnt() * 4 << "_B " <<
											  _4096_KB.getCollumCnt() * _4096_KB.getRowCnt() / 256 << "_KB\n";
		}

		if (GetAsyncKeyState(VK_NUMPAD1) < 0) {
			system("cls");
			V11_Task1();
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_NUMPAD2) < 0) {
			system("cls");
			V11_Task2();
			Sleep(200);
		}
		
		if (GetAsyncKeyState(VK_NUMPAD3) < 0) {
			system("cls");
			V11_Task3();
			Sleep(200);
		}
	}
}


