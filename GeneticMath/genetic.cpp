#include <stdlib.h>
#include <time.h>
#include "tour.h"
#include "genetic.h"
#include "population.h"



Population* Genetic::evolve_pop(Population* pop, Tour_manager* man)
{
	Population* new_pop = new Population(pop->population_size(), false, man);

	int elitism_offset = 0;
	if (ELITISM)
	{
		new_pop->save_tour(0, pop->get_fittest());
		elitism_offset = 1;
	}

	for (int i = elitism_offset; i < new_pop->population_size(); i++)
	{
		Tour* parent_1 = tournament_select(pop, man);
		Tour* parent_2 = tournament_select(pop, man);

		Tour* child = crossover(parent_1, parent_2, man);

		new_pop->save_tour(i, child);
	}

	for (int i = elitism_offset; i < new_pop->population_size(); i++)
	{
		mutate(new_pop->get_tour(i));
	}
	return new_pop;
}

Tour* Genetic::crossover(Tour* parent_1, Tour* parent_2, Tour_manager* man)
{
	Tour* child = new Tour(man);

	int start_pos = rand() % (parent_1->tour_size());
	int end_pos = rand() % (parent_1->tour_size());

	for (int i = 0; i < child->tour_size(); i++)
	{
		if (start_pos < end_pos && i > start_pos && i < end_pos)
		{
			child->set_city(i, parent_1->get_city(i));
		}
		else if (start_pos > end_pos)
		{
			if (!(i < start_pos && i > end_pos))
			{
				child->set_city(i, parent_1->get_city(i));
			}
		}
	}

	for (int i = 0; i < parent_2->tour_size(); i++)
	{
		if (!child->contains_city(parent_2->get_city(i)))
		{
			for (int j = 0; j < child->tour_size(); j++)
			{
				if (child->get_city(j) == NULL)
				{
					child->set_city(j, parent_2->get_city(i));
					break;
				}
			}
		}
	}

	return child;
}

void Genetic::mutate(Tour* tour)
{
	for (int tour_pos_1 = 0; tour_pos_1 < tour->tour_size(); tour_pos_1++)
	{
		if (static_cast<float>(rand()) / RAND_MAX < MUTATION_RATE)
		{
			int tour_pos_2 = (static_cast<int>(rand() % (tour->tour_size())));

			City* city_1 = tour->get_city(tour_pos_1);
			City* city_2 = tour->get_city(tour_pos_2);

			tour->set_city(tour_pos_2, city_1);
			tour->set_city(tour_pos_1, city_2);
		}
	}
}

Tour* Genetic::tournament_select(Population* pop, Tour_manager* man)
{
	Population* tournament = new Population(TOURNAMENT_SIZE, false, man);

	for (int i = 0; i < TOURNAMENT_SIZE; i++)
	{
		int random_id = static_cast<int>(rand() % (pop->population_size()));
		tournament->save_tour(i, pop->get_tour(random_id));
	}

	Tour* fittest = tournament->get_fittest();
	return fittest;
}