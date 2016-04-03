/*
 * LinkedListClass.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Carlos
 */

#include "pa2.h"

#include <iostream>

using namespace std;

//Prints all elements in linkedList
void LinkedListClass::printNullElement(){
	NodeClass * temp = head;
	int lineBreak =0;
//Print element values in linked list
   while(temp->next !=NULL){
	   //Add a break line after 6 objects

	   if (temp->used == false){
		   if (lineBreak == 8){

			   cout<<endl;
			   lineBreak =0;

		   }
	          cout<< "FREE ";

	        //  cout<<"Works 1"<<endl;

	          temp = temp -> next;
	          lineBreak ++;

	      }

	   else{
		   //only display 8 elements per line

		  if (lineBreak == 8){

			  cout<<endl;

			   lineBreak =0;

		  }
		  lineBreak ++;
	   	cout<< temp->programName<<" ";
	   	temp = temp -> next;

	   }

	//   cout<<"Works 2"<<endl;
       //temp = temp -> next;

   }

   cout<<endl;



//Print element values in linked list


   }

//Create a list of 32 null nodes
void LinkedListClass::insertNullNode(){


	if(head == NULL){

	       head = new NodeClass();

	       //cout<< "if head  " << ((head -> next)== NULL)<<endl;

	       return;

	   }

	//cout<<"Works 1"<<endl;
	   NodeClass * temp = head;
	   while(temp->next != NULL){

		//   cout<<"Works 2"<<endl;
	       temp = temp -> next;
	   }
	   temp -> next = new NodeClass();

	   //cout<<"Works 3"<<endl;
	   //cout<< "END" <<endl;

}
   //Transverse list to add values


//Use Worst fit algorithm to add new programs
void LinkedListClass:: addProgramWorst(string programName, int pages){

	//Empty container for pages
	int tempPages;
	//A temp location in the linked list
	NodeClass * tempReplace;
	int tempSpotReplace = 0;
	//A bool to know which tempSpot is being replaced
	bool whichSpot;

	NodeClass * tempSpot1;
	int tempSpot1Pages = 0;

	NodeClass * tempSpot2;
	int tempSpot2Pages = 0;
	NodeClass * temp = head;

	//transverse the linked list until we reach the end aka null node
	while(temp->next !=NULL){

	//If head is empty then add program

		//Compare memory, If the memory in tempSpot1Pages is greater than tempSpot2Pages
		//set tempSpot2Pages to 0 and continue comparien always keeping the largest number
		if (tempSpot1Pages > tempSpot2Pages){

			tempSpot2Pages = 0;
		}
		else{
			tempSpot1Pages = 0;
		}

		//If current node is empty and there exists a node after that one start counting empty nodes
		if(temp->used == false && temp -> next != NULL){

			//If tempSpot1Pages is greater than the other one then set tempSpot2 and pages to be compared
			//in case that the value of tempSpot2Pages is larger
			if(tempSpot1Pages != 0 && tempSpot2Pages == 0 ){
				tempReplace = tempSpot2;
				tempSpotReplace = tempSpot2Pages;
				whichSpot = false;

			}
			else{
				tempReplace = tempSpot1;
				tempSpotReplace = tempSpot1Pages;
				whichSpot = true;

			}
			//Mark start of free space in linked list
			tempReplace = temp;
			//Increase the memory
			tempSpotReplace++;

			//Change to next node if there exists a next node
			if (temp -> next != NULL){

				temp = temp -> next;
			}
			else{
				break;
			}
			//Keep increasing pages until we hit a node that has been taken
			while(temp->used == false && temp -> next != NULL){


				//Increase empty spots
				tempSpotReplace++;

				temp = temp -> next;


			}

			//

			//At the end check whether the replaced variable belonged to tempSpot1 or 2
				if(whichSpot == false){
					tempSpot2=tempReplace;
					tempSpot2Pages = tempSpotReplace;
				}
				else{
					tempSpot1=tempReplace;
					tempSpot1Pages = tempSpotReplace;
				}


		}

		//Go through all the occupied nodes in the list
		while(temp->used == true){
			if (temp -> next != NULL){

				temp = temp -> next;

			}else{
				break;
			}
		}
	}//Check were to place programs
	//If the number of pages that tempSpot1Pages has are equal or greater than tempSpot2Pages
	//and it fits the program we are trying to add then add all those programs until there are no more pages
	if((tempSpot1Pages >tempSpot2Pages ||tempSpot1Pages == tempSpot2Pages) && (tempSpot1Pages > pages || tempSpot1Pages == pages)){
		tempPages= pages;
		while(tempPages > 0){
			tempSpot1->programName = programName;
			tempSpot1->used = true;
			tempPages--;
			tempSpot1 = tempSpot1->next;

		}
	cout<<"Program "<<programName<<" added successfully: "<< pages <<" page(s) used."<<endl;
	}
	//If tempSpot2 has more space than tempSpot1 and the size is equal or greater than the size of our program
	//then use start adding programs from that point onward until we fit all the program.
	else if( (tempSpot2Pages>tempSpot1Pages)&& (tempSpot2Pages > pages || tempSpot2Pages == pages)){
		tempPages= pages;
		while(tempPages > 0){
			tempSpot2->programName = programName;
			tempSpot2->used = true;
			tempPages--;
			tempSpot2 = tempSpot2->next;
	cout<<"Program "<<programName<<" added successfully: "<<pages <<" page(s) used."<<endl;
	}

	}
	else{

		cout<<"NOT ENOUGH MEMORY!!!!"<<endl;
	}

}
void LinkedListClass:: addProgramBest(string programName, int pages){

	//Empty container for pages
	int tempPages;
	//A temp location in the linked list
	NodeClass * tempReplace;
	int tempSpotReplace = 0;
	//A bool to know which tempSpot is being replaced
	bool whichSpot;

	NodeClass * tempSpot1;
	int tempSpot1Pages = 0;

	NodeClass * tempSpot2;
	int tempSpot2Pages = 0;
	NodeClass * temp = head;

	//transverse the linked list until we reach the end aka null node
	while(temp->next !=NULL){

		//Check if the space found in memory is equal to the min memory needed and stop searching if it's found
		if ((tempSpot1Pages == pages)){


			break;

		}else if(tempSpot2Pages == pages){

			break;
		}
		//Compare memory, If the memory in tempSpot1Pages is less than tempSpot2Pages
		//set tempSpot2Pages to 0 and continue comparien always keeping the largest number

		if ((tempSpot1Pages < tempSpot2Pages) ||(tempSpot1Pages!=0 && tempSpot2Pages==0)){

			tempSpot2Pages = 0;
		}
		else{

			tempSpot1Pages = 0;
		}

		//If current node is empty and there exists a node after that one start counting empty nodes
		if(temp->used == false && temp -> next != NULL){

			//If tempSpot1Pages is greater than the other one then set tempSpot2 and pages to be compared
			//in case that the value of tempSpot2Pages is larger
			if(tempSpot1Pages != 0 && tempSpot2Pages == 0 ){
				tempReplace = tempSpot2;
				tempSpotReplace = tempSpot2Pages;
				whichSpot = false;

			}
			else{

				tempReplace = tempSpot1;
				tempSpotReplace = tempSpot1Pages;
				whichSpot = true;

			}
			//Mark start of free space in linked list
			tempReplace = temp;
			//Increase the memory
			tempSpotReplace++;

			//Change to next node if there exists a next node
			if (temp -> next != NULL){

				temp = temp -> next;
			}
			else{
				break;
			}
			//Keep increasing pages until we hit a node that has been taken
			while(temp->used == false && temp -> next != NULL){



				//Increase empty spots
				tempSpotReplace++;

				temp = temp -> next;


			}

			//

			//At the end check whether the replaced variable belonged to tempSpot1 or 2
				if(whichSpot == false){
					tempSpot2=tempReplace;
					tempSpot2Pages = tempSpotReplace;
				}
				else{
					tempSpot1=tempReplace;
					tempSpot1Pages = tempSpotReplace;
				}


		}

		//Go through all the occupied nodes in the list
		while(temp->used == true){
			if (temp -> next != NULL){

				temp = temp -> next;

			}else{
				break;
			}
		}
	}//Check were to place programs
	//If the number of pages that tempSpot1Pages has are equal or greater than tempSpot2Pages
	//and it fits the program we are trying to add then add all those programs until there are no more pages
	if((tempSpot1Pages < tempSpot2Pages ||tempSpot1Pages == tempSpot2Pages ||tempSpot2Pages == 0) && (tempSpot1Pages > pages || tempSpot1Pages == pages)){
		tempPages= pages;
		while(tempPages > 0){
			tempSpot1->programName = programName;
			tempSpot1->used = true;
			tempPages--;
			tempSpot1 = tempSpot1->next;

		}
	cout<<"Program "<<programName<<" added successfully: "<< pages <<" page(s) used."<<endl;
	}
	//If tempSpot2 has more space than tempSpot1 and the size is equal or greater than the size of our program
	//then use start adding programs from that point onward until we fit all the program.
	else if( (tempSpot2Pages < tempSpot1Pages)&& (tempSpot2Pages > pages || tempSpot2Pages == pages)){
		tempPages= pages;
		while(tempPages > 0){
			tempSpot2->programName = programName;
			tempSpot2->used = true;
			tempPages--;
			tempSpot2 = tempSpot2->next;
		}
		cout<<"Program "<<programName<<" added successfully: "<<pages <<" page(s) used."<<endl;
	}
	else if( (tempSpot2Pages > pages || tempSpot2Pages == pages)){
		tempPages= pages;
		while(tempPages > 0){
			tempSpot2->programName = programName;
			tempSpot2->used = true;
			tempPages--;
			tempSpot2 = tempSpot2->next;
		}
		cout<<"Program "<<programName<<" added successfully: "<<pages <<" page(s) used."<<endl;
	}
	else{

		cout<<"NOT ENOUGH MEMORY!!!!"<<endl;
	}

}
//Remove progrmas from memory
void LinkedListClass::removeElement(string programName){
	//Counts number of pages removed
	int programsRemoved=0;

	if(head->programName == programName ){

		head->programName = "";
		head->used = false;
		programsRemoved++;
	}
	NodeClass * temp = head;
	while(temp->next !=NULL){
		if(temp->next->programName == programName ){
			temp = temp -> next;
			temp->programName = "";
			temp->used = false;
			programsRemoved++;
			}
		else{
			temp = temp -> next;

		}


	}
	cout<<"Program "<<programName<<" successfully killed,: "<<programsRemoved <<" page(s) used."<<endl;
}
bool LinkedListClass::isNameTaken(string programName){
	bool isNameTaken =false;
	if(head->programName == programName ){
		isNameTaken =true;

			return isNameTaken;
		}
		NodeClass * temp = head;
		while(temp->next !=NULL){
			if(temp->next->programName == programName ){
				temp = temp -> next;
				isNameTaken = true;
				return isNameTaken;

				}
			else{
				temp = temp -> next;

			}


		}
	return isNameTaken;
}
int LinkedListClass::fragments(){

	NodeClass * temp = head;
	int fragments = 0;

	while(temp->next !=NULL){
		if(temp->used == false && temp -> next != NULL){
			fragments++;

			//Change to next node if there exists a next node
			if (temp -> next != NULL){

				temp = temp -> next;
			}
			else{
				break;
			}
			//Keep increasing pages until we hit a node that has been taken
			while(temp->used == false && temp -> next != NULL){

				temp = temp -> next;
			}
		}
		while(temp->used == true){

			if (temp -> next != NULL){

				temp = temp -> next;

			}else{
				break;
			}
		}
	}
	return fragments;
}

