//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include "pa2.h"
#include "NodeClass.cpp"
#include "LinkedListClass.cpp"

using namespace std;

int memoryToPage(int kB);
void correctInputMenu(int &inputNumber);

void correctInputCreate(int &inputNumber);

int main(int argc, char ** argv) {
	string bestOrWorst= "";
	
	//Checks number of arguments passed in terminal
	if (argc > 2){

		cout<<"Cannot run program"<<endl;
	}else{
		//Chooses method to use
		
		if(std::string(argv[1])=="worst" ||(std::string(argv[1])=="Worst")){

			cout<<"Using worst fit algorithm"<<endl;
			
			bestOrWorst="worst";

		}else if(std::string(argv[1])=="best" ||(std::string(argv[1])=="Best")){

			cout<<"Using best fit algorithm"<<endl;
			bestOrWorst="best";


		}else{
			cout<<"Unknown Command, terminating program"<<endl;
			return 0;
		}
		cout<<bestOrWorst<<endl;
	
	//Creates a linked list with 32 elements
	LinkedListClass *ll = new LinkedListClass();

	    for (int var = 0; var < 33; ++var) {
	    	ll->insertNullNode();
		}

	    int numberFragments = 0;
		int inputNum;
		string programName;
		int programSize;


		cout<<"1. Add program \n2. Kill program \n3. Fragmentation \n4. Print memory \n5. Exit "<<endl;
		//Main menu, keep program running until Exit is chosen
		    	do{
					//validates user input
		        	correctInputMenu(inputNum);

		        	if (inputNum==1){

		        		cout<<"Program name - ";
		        		cin>>programName;
		        		cout<<endl;
		        		correctInputCreate(programSize);
		        		//check if name already exists in memory
		        		if (ll->isNameTaken(programName)== true){

		        			cout<<"Program already exists"<<endl;

		        		}
		        		//Uses best or worst method depending on what was chosen at the begining
		        		else{
		        			if(bestOrWorst=="worst"){
		        			ll->addProgramWorst(programName,memoryToPage(programSize));
		        		}else{
		        			ll->addProgramBest(programName,memoryToPage(programSize));}
		        		}

		        	}
		        	//Remove a program
		        	else if (inputNum==2){
		        		cout<<"Program name - ";
		        		cin>>programName;
		        		cout<<endl;
		        		//Check if program actually exists
		        		if (ll->isNameTaken(programName)== true){
		        	     ll->removeElement(programName);
		        		}else{
		        			cout<<"Program Doesn't Exist"<<endl;

		        		}

		        	}
		        	//Checks fragmentation
		        	else if (inputNum==3){
		        		numberFragments =ll->fragments();

		        		cout<<"There are "<<numberFragments<<" fragment(s)."<<endl;

		        	}
		        	//Prints linked list
		        	else if (inputNum==4){
		        		 ll->printNullElement();

		        	}
		        	//Terminates program
				if(inputNum > 5 || inputNum<1){
					
					cout<<"Invalid user input, input must be between 1 and 5 "<<endl;
					}

		        }while(inputNum > 5 || inputNum<1 || inputNum !=5 );

	}
	return 0;
}

//Transforms memory into pages
int memoryToPage(int kB){
	int pages;
	//If even numbers grater than or equal to 4 then do this
	if (kB%4 == 0){
		pages = kB/4;
	}
	//If odd or less than 4
	else{

		pages = (kB/4)+1;
	}
	return pages;
}
//Validates correct input for main menu
void correctInputMenu(int &inputNumber){

	bool cinError;

	do {
		
		cout<<"choice - ";
		cin>>inputNumber;
		
		cinError = cin.fail();

		if(cinError ==true){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<<"Invalid Input"<<endl;
	}
	}while (cinError == true);

	

}
//Validates input for program creation
void correctInputCreate(int &inputNumber){

	bool cinError;

	do {
		
		cout<<"Program size (KB) - ";
		cin>>inputNumber;
		
		cinError = cin.fail();

		if(cinError ==true){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<<"Input must be a number"<<endl;
	}
	}while (cinError == true);

	

}




