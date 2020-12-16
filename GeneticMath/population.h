#ifndef POPULATION_H
#define POPULATION_H
class Tour;
class Tour_manager;
class Population
{
public:
	Population(int, bool, Tour_manager*);
	void save_tour(int, Tour*);
	Tour* get_tour(int);
	Tour* get_fittest();
	int population_size();
private:
	std::vector<Tour*> *tours;
};
#endif // !POPULATION_H
