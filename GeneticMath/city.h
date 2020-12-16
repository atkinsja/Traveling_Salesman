#ifndef CITY_H
#define CITY_H
class City
{
public:
	City();
	City(int, int);
	int get_x();
	int get_y();
	double distance_to(City*);
	std::string to_string();
private:
	int x;
	int y;
};
#endif // !CITY_H