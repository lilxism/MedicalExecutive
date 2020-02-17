#include "OrderedList.h"

//This method is to allow the insert of element in the OrderedList.
void OrderedList::insert(City c1){
	if(llist.size()==0){
		llist.push_front(c1);
	}else if(c1>=llist.front()){
		llist.push_front(c1);
	}else{
		list<City>::iterator it;
		for(it=llist.begin();it!=llist.end();it++){
			City c2=*it;
			if(c1>=c2){
				break;
			}
		}
		llist.insert(it,c1);
	}
}
		
//This method is to remove a particular element from the list.
void OrderedList::remove(City c1){
	llist.remove(c1);
}
		
//This method is to get the length of the OrderedList
int OrderedList::length(){
	return llist.size();
}

//toString method
void OrderedList::printString(){
	list<City>::iterator it;
	for(it=llist.begin();it!=llist.end();it++){
		cout<<it->getName()<<" ";
		cout<<it->getPopulation()<<" ";
		cout<<it->getInfection()<<endl;
	}	
}
		
//This method is to get city at given index
City OrderedList::get(int index){
	list<City>::iterator it=llist.begin();
	for(int i=0;i<index;i++){
		++it;
	}
	City c=*it;
	return c;
}

//destructor
OrderedList::~OrderedList(){}
