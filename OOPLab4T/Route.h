#pragma once
#include "MyDate.h"
#include <iostream>
#include <cstring>


class Route {
public:

	Route();
	int route_id;
	int bus_id;
	std::string route_name;
	std::string description;

	Date departure_date;
	Date arrival_date;

	friend std::ostream& operator<<(std::ostream& os, Route& route);
	
};