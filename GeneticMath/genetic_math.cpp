#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tour_manager.h"
#include "tour.h"
#include "city.h"
#include "population.h"
#include "genetic.h"

using namespace std;
void output_results(Population*, ofstream&);
void output_results(Tour_manager*, ofstream&);
int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int num_cities = 20;
	int pop_size = 10;
	ifstream inFile;
	ofstream outFile;
	string inFile_name = "cities.txt";
	string outFile_name = "routes.txt";
	inFile.open(inFile_name);
	outFile.open(outFile_name);

	City **cities = new City*[num_cities];
	Tour_manager *tour_man = new Tour_manager();
	
	
	if (!inFile.is_open())
	{
		cout << "Error opening input file." << endl;
		return -1;
	}

	if (!outFile.is_open())
	{
		cout << "Error opening output file." << endl;
	}

	int *x = new int[num_cities];
	int *y = new int[num_cities];

	for (int i = 0; i < num_cities; i++)
	{
		inFile >> x[i];
		inFile >> y[i];
		cities[i] = new City(x[i], y[i]);
		tour_man->add_city(cities[i]);
	}

	inFile.close();

	Population* pop = new Population(50, true, tour_man);
	Genetic* gen = new Genetic();

	cout << "Starting distance between each city: ";
	outFile << "Starting distance between each city: ";
	output_results(tour_man, outFile);

	cout << "\n\nInitial distance: " << pop->get_fittest()->get_distance() << endl;
	outFile << "\n\nInitial distance: " << pop->get_fittest()->get_distance() << endl;
	output_results(pop, outFile);
	
	pop = gen->evolve_pop(pop, tour_man);

	for (int i = 0; i < 100; i++)
		pop = gen->evolve_pop(pop, tour_man);

	cout <<"\n\nFinal distance: " << pop->get_fittest()->get_distance() << endl;
	outFile << "\n\nFinal: " << pop->get_fittest()->get_distance() << endl;
	output_results(pop, outFile);
	
	outFile.close();
	return 0;
}

void output_results(Population* m_pop, ofstream& outFile)
{

	for (int i = 0; i < m_pop->get_fittest()->tour_size(); i++)
	{
		if (i != m_pop->get_fittest()->tour_size() - 1)
		{
			outFile << "(" << m_pop->get_fittest()->get_city(i)->get_x() << ", " << m_pop->get_fittest()->get_city(i)->get_y() << ")" << "-->";
			cout << "(" << m_pop->get_fittest()->get_city(i)->get_x() << ", " << m_pop->get_fittest()->get_city(i)->get_y() << ")" << "-->";
		}
		else
		{
			outFile << "(" << m_pop->get_fittest()->get_city(i)->get_x() << ", " << m_pop->get_fittest()->get_city(i)->get_y() << ")";
			cout << "(" << m_pop->get_fittest()->get_city(i)->get_x() << ", " << m_pop->get_fittest()->get_city(i)->get_y() << ")";
		}
	}
}

void output_results(Tour_manager* m_tour_man, ofstream& outFile)
{
	for (int i = 0; i < m_tour_man->num_cities(); i++)
	{
		if (i != m_tour_man->num_cities() - 1)
		{
			outFile << "(" << m_tour_man->get_city(i)->get_x() << ", " << m_tour_man->get_city(i)->get_y() << ")" << "-->";
			cout << "(" << m_tour_man->get_city(i)->get_x() << ", " << m_tour_man->get_city(i)->get_y() << ")" << "-->";
		}
		else
		{
			outFile << "(" << m_tour_man->get_city(i)->get_x() << ", " << m_tour_man->get_city(i)->get_y() << ")";
			cout << "(" << m_tour_man->get_city(i)->get_x() << ", " << m_tour_man->get_city(i)->get_y() << ")";
		}
	}
}
