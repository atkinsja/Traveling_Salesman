#include <stdlib.h>
#include <math.h>
#include <string>
#include "city.h"


City::City()
{
	x = rand() % 200;
	y = rand() % 200;
}

City::City(int m_x, int m_y)
{
	x = m_x;
	y = m_y;
}

int City::get_x()
{
	return x;
}

int City::get_y()
{
	return y;
}

double City::distance_to(City *city)
{
	int x_distance = abs(get_x() - city->get_x());
	int y_distance = abs(get_y() - city->get_y());
	double distance = sqrt((x_distance*x_distance) + (y_distance*y_distance));
	return distance;
}

std::string City::to_string()
{
	std::string test = " ";
	return test;
}


