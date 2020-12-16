#ifndef TOUR_MANAGER_H
#define TOUR_MANAGER_H

class City;
class Tour_manager
{
public:
	void add_city(City*);
	City* get_city(int);
	int num_cities();
private:
	std::vector<City*> *destination_cities = new std::vector<City*>;
};
#endif // !TOUR_MANAGER_H
