#include <algorithm>
#include <random>
#include <chrono>
#include "tour.h"
#include "tour_manager.h"
#include "city.h"

Tour::Tour(Tour_manager* man)
{
	fitness = 0;
	distance = 0;

	for (int i = 0; i < man->num_cities(); i++)
	{
		tour->push_back(NULL);
	}
}

Tour::Tour(std::vector <City*> *m_tour)
{
	tour = m_tour;
}

void Tour::generate_individual(Tour_manager* man)
{
	unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine rng(seed);
	for (int city_index = 0; city_index < man->num_cities(); city_index++)
	{
		set_city(city_index, man->get_city(city_index));
	}
	std::shuffle(tour->begin(), tour->end(), rng);
}

City* Tour::get_city(int tour_position)
{
	return tour->at(tour_position);
}

void Tour::set_city(int tour_position, City* city)
{
	tour->at(tour_position) = city;
	fitness = 0;
	distance = 0;
}

double Tour::get_fitness()
{
	if (fitness == 0)
	{
		fitness = 1 / (static_cast<double>(get_distance()));
	}
	return fitness;
}

int Tour::get_distance()
{
	if (distance == 0)
	{
		int tour_distance = 0;
		for (int city_index = 0; city_index < tour_size(); city_index++)
		{
			City *from_city = get_city(city_index);
			City *destination_city;
			if (city_index + 1 < tour_size())
			{
				destination_city = get_city(city_index + 1);
			}
			else
			{
				destination_city = get_city(0);
			}
			tour_distance += static_cast<int> (from_city->distance_to(destination_city));
			
		}
		distance = tour_distance;
	}
	return distance;
}

int Tour::tour_size()
{
	return tour->size();
}

bool Tour::contains_city(City *city)
{
	if (std::find(tour->begin(), tour->end(), city) != tour->end())
	{
		return true;
	}
	else
		return false;
}
