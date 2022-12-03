#define _CRT_SECURE_NO_WARNINGS
#include "Route.h"
#include "ColorText.h"
#include <cstring>

Route::Route() {
	route_id = -1;
	bus_id = -1;
	route_name = "NULL";
	description = "NULL";

	departure_date.zero();
	arrival_date.zero();
}

std::ostream& operator<<(std::ostream& os, Route& route) {

	route.route_id == -1 ? os << "Route id : NULL\n" : os << "Route id : " << route.route_id << '\n';
	route.bus_id == -1 ? os << "Bus id : NULL\n" : os << "Bus id : " << route.bus_id << '\n';
	
	os << "Route name : "	  << route.route_name << '\n' <<
		  "Description : "	  << route.description << '\n';

	if (route.departure_date.isNull) {
		os << "Departure date : NULL\n";
	}
	else {
		os << "Departure date : "   << ((route.departure_date.getHour() < 10) ? '0' : '\0') << route.departure_date.getHour() << ':'
								    << ((route.departure_date.getMinute() < 10) ? '0' : '\0') << route.departure_date.getMinute() << ':'
								    << ((route.departure_date.getSecond() < 10) ? '0' : '\0') << route.departure_date.getSecond() << "  "
								    << ((route.departure_date.getDay() < 10) ? '0' : '\0') << route.departure_date.getDay() << '.'
								    << ((route.departure_date.getMonth() < 10) ? '0' : '\0') << route.departure_date.getMonth() << '.'
								    << route.departure_date.getYear() << '\n';
	}

	if (route.arrival_date.isNull) {
		os << "Arrival date : NULL\n";
	}
	else {
		os << "Arrival date : "   << ((route.arrival_date.getHour() < 10) ? '0' : '\0') << route.arrival_date.getHour() << ':'
								  << ((route.arrival_date.getMinute() < 10) ? '0' : '\0') << route.arrival_date.getMinute() << ':'
								  << ((route.arrival_date.getSecond() < 10) ? '0' : '\0') << route.arrival_date.getSecond() << "  "
								  << ((route.arrival_date.getDay() < 10) ? '0' : '\0') << route.arrival_date.getDay() << '.'
								  << ((route.arrival_date.getMonth() < 10) ? '0' : '\0') << route.arrival_date.getMonth() << '.'
								  << route.arrival_date.getYear() << '\n';
	}
	return os;
}
