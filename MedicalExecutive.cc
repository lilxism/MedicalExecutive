#include "MedicalExecutive.h"

//to get iList
OrderedList MedicalExecutive::getIList(){
	return iList;
}
	
//to set iList
void MedicalExecutive::setIList(OrderedList iList){
	this->iList=iList;
}

//to get qList	
OrderedList MedicalExecutive::getQList(){
	return qList;
}

//to set qList	
void MedicalExecutive::setQList(OrderedList qList){
	this->qList=qList;
}
	
//read file and put the cities into iList	
void MedicalExecutive::ReadFile(string filename){
	ifstream file(filename);
	if(file.is_open()) {	
		string line;
		string name;
		int population;
		int infection;
		string p;
		string i;
		while(getline(file,line)){
			stringstream iss(line);
			getline(iss,name, ',');
			getline(iss,p,',');
			population=stoi(p);
			getline(iss,i,'\n');
			infection=stoi(i);
			
			City city(name,population,infection);
			iList.insert(city);
		}
	}else{
		cout<<"unable to read file"<<endl;
		exit(1);
	}
}
	
//to increase infection level of all cities	
void MedicalExecutive::increaseAll(){
	City city;
	vector<City> temp;
	for(int i=0;i<iList.length();i++){
		city=iList.get(i);
		city.setInfection(city.getInfection()+1);
		temp.push_back(city);	
	}
	int s=temp.size();
	cout<<"The infection level for all cities has been increased."<<endl;
	for(int i=0;i<s;i++){
		checkLevel(temp.at(i));
	}		
}

//to check the level of given city and act based on the level	
void MedicalExecutive::checkLevel(City city){
	iList.remove(city);
	int population=city.getPopulation();
	if(city.getInfection()==1) {
		city.setPopulation(population-(population*10/100));
		iList.insert(city);
	}else if(city.getInfection()==2) {
		city.setPopulation(population-(population*20/100));
		iList.insert(city);
	}else if(city.getInfection()==3) {
		city.setPopulation(population-(population*25/100));
		int nCityPop = population*25/100;
		City newCity("New "+city.getName(),nCityPop,0);
		iList.insert(city);
		iList.insert(newCity);
		cout<< "New "<<city.getName()<<" has been made."<<endl;
	}else if(city.getInfection()==4) {
		qList.insert(city);
		cout<<"City "<<city.getName()<<" has been placed in quarantine!"<<endl;
	}else {
		iList.insert(city);
	}
}
	
//print the info of given city name
bool MedicalExecutive::increaseSpecific(string infName){
	bool b=false;
	for(int i=0;i<iList.length();i++){
		City city=iList.get(i);
		if((iList.get(i).getName().compare(infName))==0){
			city.setInfection(iList.get(i).getInfection()+1);
			checkLevel(city);
			b=true;
			break;
		}
	}
	return b;
}

//increase the infection level of given city
void MedicalExecutive::printSpecific(string statusName) {
	bool b=false;
	for(int i=0;i<iList.length();i++) {
		if(statusName.compare(iList.get(i).getName())==0) {
			cout<<"Status: "<<iList.get(i).toString()<<endl;
			b=true;
		}
	}
	if(!b) {
		cout<<"Sorry, "<<statusName<<" is not a city in the list."<<endl;
	}
}

//create file for quarantine log
void MedicalExecutive::qLog(string file){
	ofstream myfile;
	myfile.open(file);
	if(myfile){
	for(int i=0;i<qList.length();i++){
		myfile<<qList.get(i).toString()<<endl;
	}
	myfile.close();
	}else{
		cout<<"cannot create file"<<endl;
	}
}
	
//print cities that are above the given level
void MedicalExecutive::printAbove(int level) {
	string list="";
	if(level>=-1&&level<5) {
		cout<<"Cities above level "<<level<<" :"<<endl;
		for(int i=0;i<iList.length();i++) {
			if(iList.get(i).getInfection()>level) {
				list=list+iList.get(i).toString()+"\n";
			}
		}
		if(list==""){
			cout<<"no cities have infection level above "<< level<<endl;
		}else{
			cout<<list;
		}
	}else {
		cout<<"Input level out of bound."<<endl;
	}
}

//destructor
MedicalExecutive::~MedicalExecutive(){}

	

