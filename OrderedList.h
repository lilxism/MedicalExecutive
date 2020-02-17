#ifndef _ORDEREDLIST_H_
#define _ORDEREDLIST_H_

#include <iostream>
#include <list>
#include <string>
#include "City.h"
using namespace std;

class OrderedList{
	private:
		list <City> llist;
	
	public:
		//This method is to allow the insert of element in the OrderedList.
		void insert(City c);
		
		//This method is to remove a particular element from the list.
		void remove(City c);
		
		//This method is to get the length of the OrderedList
		int length();
		
		//toString method
		void printString();
		
		//This method is to get city at given index
		City get(int index);
		
		//destructor
		~OrderedList();
	 
};

#endif
	