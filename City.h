#ifndef _CITY_H_
#define _CITY_H_

#include <iostream>
#include <string>
using namespace std;

class City{
	private:
		string name;
		int population;
		int infection;
	
	public:
		//Constructor
		City();
		
		//Constructor with parameter
		City(string name, int population,int infection);
		
		//To get the name of the city
		string getName();
	
		//To set the name of the city
		void setName(string name);
	
		//To get the population of the city
		int getPopulation();
	
		//To set the population of the city
		void setPopulation(int population);
	
		//To get the infection level of the city
		int getInfection();
	
		//To set the infection of the city
		void setInfection(int infection);
		
		//operator overload for compare
		//ordered by population(descending)
		//rank by infection level
		//alphabetically by name
		friend bool operator >=(City c1,City c2);
		
		//overload operator for ==
		//mainly used in remove method in list
		friend bool operator ==(City c1,City c2);
		
		//toString method
		string toString();
		
		//destructor 
		~City();
};

#endif
	