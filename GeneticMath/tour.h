#ifndef TOUR_H
#define TOUR_H
#include <vector>

class City;
class Tour_manager;
class Tour
{
public:
	Tour(Tour_manager*);
	Tour(std::vector<City*>*);
	void generate_individual(Tour_manager*);
	City* get_city(int);
	void set_city(int, City*);
	double get_fitness();
	int get_distance();
	int tour_size();
	bool contains_city(City*);
private:
	std::vector<City*> *tour = new std::vector<City*>;
	double fitness;
	int distance;
};
#endif // !TOUR_H
