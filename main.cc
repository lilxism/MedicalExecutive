#include <iostream>
#include "MedicalExecutive.h"
#include <string>
using namespace std;
int main(int argc, char *argv[]){
	if(argc!=2){
		cout<<"Please input a file name"<<endl;
		exit(1);
	}else{
		MedicalExecutive med; 
		//when it read the file, it also set the cities into iList
		med.ReadFile(argv[1]);
	
		string choice="0";
	
		while(choice!="6"){
			cout<<"Make a selection:\n"<<
			"1) Increase infection level of all cities\n" << 
			"2) Increase infection level of specific city\n" << 
			"3) Print status of a specific city\n" <<
			"4) Create quarantine log\n" <<
			"5) Print all cities above an infection level\n" <<
			"6) Exit\n"<<
			"Choice: ";
			
			cin>>choice;
			cout<<" "<<endl;
			string dummy; //for fixing getline
		
			if(choice=="1"){
				med.increaseAll();
			
			}else if(choice=="2"){
				getline(cin,dummy);
				string infName;
				cout<<"Which city do you want to infect?: ";
				getline(cin,infName);
				if(med.increaseSpecific(infName)){
					cout<<"Infection level for "<<infName<<" increase by 1"<<endl;
				}else{
					cout<<infName<<" is not found"<<endl;
				}
			
			}else if(choice=="3"){
				getline(cin, dummy);
				string statusName;
				cout<<"Which city do you want the status of?: ";
				getline(cin, statusName);
				med.printSpecific(statusName);
			
			}else if(choice=="4"){
				if(med.getQList().length()>0){
					getline(cin,dummy);
					string logName;
					cout<<"What do you want to name the log?: ";
					getline(cin,logName);
					med.qLog(logName);
				}else{
					cout<<"Quarantine list is empty"<<endl;
				}
			
			}else if(choice=="5"){
				int level;
				cout<<"Cities above what level?: ";
				cin>>level;
				med.printAbove(level);
			
			}else if(choice=="6"){
				cout << "Exiting." << endl;
				exit(1);
			
			}else{
				cout<<"Wrong input! Choose from 1 to 6."<<endl;
			}
			cout<<endl;
		}
	}
}
