/*
 * pa2.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Carlos
 */

#ifndef NODECLASS_H_
#define NODECLASS_H_
#include <stddef.h>
#include <string>

using namespace std;


class NodeClass {
public:
	NodeClass();
	NodeClass(int value);
	int data;
	bool used;
	NodeClass * next;
	string programName;
	int pageSize;
};

class NodeClass;
class LinkedListClass {
public:
	void insertNullNode();
	void printNullElement();
	void addProgramWorst(string programName, int pages);
	void removeElement(string programName);
	bool isNameTaken(string programName);
	void addProgramBest(string programName, int pages);
	int fragments();


private :
	NodeClass *head;

};


#endif /* NODECLASS_H_ */
