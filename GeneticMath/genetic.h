#ifndef GENETIC_H
#define GENETIC_H

class Population;
class Tour;
class Tour_manager;
class Genetic
{

public:
	Population* evolve_pop(Population*, Tour_manager*);
	Tour* crossover(Tour*, Tour*, Tour_manager*);
	void mutate(Tour*);
	Tour* tournament_select(Population*, Tour_manager*);
private:
	const double MUTATION_RATE = 0.015;
	const bool ELITISM = true;
	const int TOURNAMENT_SIZE = 5;
};
#endif // !GENETIC_H