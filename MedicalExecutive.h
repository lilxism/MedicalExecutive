#ifndef _MEDICALEXECUTIVE_H_
#define _MEDICALEXECUTIVE_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "OrderedList.h"
using namespace std;
class MedicalExecutive{
	private:
		OrderedList iList; //infection list
		OrderedList qList; //quarantine list
	
	public:
		
		//to get iList
		OrderedList getIList();
		
		//to set iList
		void setIList(OrderedList iList);
	
		//to get qList
		OrderedList getQList();
	
		//to set qList
		void setQList(OrderedList qList);
		
		//read file and put the cities into iList
		void ReadFile(string filename);
	
		//to increase infection level of all cities
		void increaseAll();
		
		//to check the level of given city and act based on the level
		void checkLevel(City city);
		
		//print the info of given city name
		void printSpecific(string statusName);

		//increase the infection level of given city
		bool increaseSpecific(string infName);
	
		//create file for quarantine log
		void qLog(string file);
	
		//print cities that are above the given level
		void printAbove(int level);
		
		//destructor
		~MedicalExecutive();
	
};

#endif