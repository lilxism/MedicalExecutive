#include "City.h"

//Constructor
City::City(){
	name="";
	population=0;
	infection=0;
}

//Constructor with parameter
City::City(string name, int population,int infection){
	this->name=name;
	this->population=population;
	this->infection=infection;
}
		
//to get name of city
string City::getName(){
	return name;
}
	
//To set the name of the city
void City::setName(string name){
	this->name=name;
}
	
//To get the population of the city
int City::getPopulation(){
	return population;
}

//To set the population of the city
void City::setPopulation(int population){
	this->population=population;
}

//To get the infection level of the city
int City::getInfection(){
	return infection;
}
	
//To set the infection of the city
void City::setInfection(int infection){
	this->infection=infection;
}
		
		
//operator overload for compare
//ordered by population(descending)
//rank by infection level
//alphabetically by name
bool operator >= (City c1, City c2) {
	if(c1.population==c2.population) {
		if(c1.infection==c2.infection) {
			int n=c1.name.compare(c2.name);
			if(n>0) {	
				return false;
			}else if(n<0) {
				return true;
			}else {
				return true;
			}
		}else if(c1.infection>c2.infection) {
			return false;
		}else {
			return true;
		}
	}else if(c1.population>c2.population){
		return true;
	}else {
		return false;
	}
}

//overload operator for ==
//mainly used in remove method in list
bool operator == (City c1, City c2) {
	if(c1.name.compare(c2.name)==0){
		return true;
	}else{
		return false;
	}
	
}
	
//toString method	
string City::toString() {	
	return name+", "+to_string(population)+", "+to_string(infection);
}

//destructor
City::~City(){}
	