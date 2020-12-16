#include <vector>
#include "population.h"
#include "tour.h"

Population::Population(int pop_size, bool init, Tour_manager *man)
{
	tours = new std::vector<Tour*>(pop_size);
	if (init)
	{
		for (int i = 0; i < population_size(); i++)
		{
			Tour *new_tour = new Tour(man);
			new_tour->generate_individual(man);
			save_tour(i, new_tour);
		}
	}
}

void Population::save_tour(int index, Tour *tour)
{
	tours->at(index) = tour;
}

Tour* Population::get_tour(int index)
{
	return tours->at(index);
}

Tour* Population::get_fittest()
{
	Tour *most_fit = tours->at(0);
	for (int i = 1; i < population_size(); i++)
	{
		if (most_fit->get_fitness() <= get_tour(i)->get_fitness())
			most_fit = get_tour(i);
	}
	return most_fit;
}

int Population::population_size()
{
	return tours->size();
}