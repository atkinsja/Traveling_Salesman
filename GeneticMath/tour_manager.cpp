#include <vector>
#include "tour_manager.h"

void Tour_manager::add_city(City *city)
{
	destination_cities->push_back(city);
}

City* Tour_manager::get_city(int index)
{
	return destination_cities->at(index);
}

int Tour_manager::num_cities()
{
	return destination_cities->size();
}
