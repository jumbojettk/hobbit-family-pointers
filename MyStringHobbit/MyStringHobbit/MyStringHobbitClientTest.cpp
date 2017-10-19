// Napon Krassner (Jett)
// CSC 2430, Homework 5
// 3/4/15
// Due: 3/10/15
// Name: Hobbit Client Test
// Description: This is the client file for testing HobbitString object.
//				It contains the client functions for testing.

#include "Hobbit.h"
#include "MyString.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
void printFamilyStick(Hobbit*, unsigned short);
void printRelation(Hobbit*, Hobbit*);
void printEleventyN(unsigned short);
void printStats(Hobbit*);

int main()
{
	
	//Create Sam and Gaffer, link them
	Hobbit sam("Samwise Gamgee", 15, 1380, NULL, NULL);
	Hobbit gaffer("Gaffer Gamgee", 14, 1326, NULL, &sam);
	sam.setAntecedent(&gaffer);

	//Create Elanor, link to Sam and vice versa
	Hobbit *elanor = new Hobbit("Elanor Gamgee", 14, 1421, &sam, NULL);
	sam.setDescendent(elanor);
	elanor->setAntecedent(&sam);

	// Create Eegmag, link to Elanor and vice versa
	Hobbit *eegmag = new Hobbit("Eegmag Gamgee", 14, 1461, elanor, NULL);
	elanor->setDescendent(eegmag);
	eegmag->setAntecedent(elanor);

	// Create Raffer, link to eegmag (for eleventy one test for 115 years old) and vice versa
	Hobbit *raffer = new Hobbit("Raffer Gamgee", 14, 1900, eegmag, NULL);
	eegmag->setDescendent(raffer);
	raffer->setAntecedent(eegmag);

	// Welcome
	cout << "********Welcome to the MyString Hobbit by Napon Krassner (Jett)********" << endl << endl;
	
	// TEST ADDED FUNCTIONS

	// Test Client functions
	// Test printRelation with added same lastname relationship function
	cout << "==== Testing printRelation ====" << endl;
	cout << endl << "===== Relationship of Samwise and Gaffer: =====" << endl;
	printRelation(&sam, &gaffer);
	cout << endl << "===== Relationship of Samwise and Elanor: =====" << endl;
	printRelation(&sam, elanor);
	cout << endl << "===== Relationship of Gaffer and Elanor: =====" << endl;
	printRelation(&gaffer, elanor);
	cout << endl << "===== Relationship of Elanor and Eegmag: =====" << endl;
	printRelation(eegmag, elanor);
	cout << endl << "===== Relationship of Samwise and Raffer: =====" << endl;
	printRelation(&sam, raffer);
	cout << endl << endl;

	// Test printFamilyStick with added birth year, age, root in uppercase, calcAge function
	// and the new printEleventyN function
	cout << endl << "===== Testing printFamilyStick on Gaffer: =====" << endl;
	printFamilyStick(&gaffer, 2015);
	cout << endl << endl;

	// Test printStats which contains:
	//		palindrome testing,
	//		copy constructor testing,
	//		toUpper testing
	cout << "==== Testing printStats on Samwise: ====" << endl;
	printStats(&sam);
	cout << endl << endl << endl;

	// Test MyString Class
	cout << "==== Testing MyString Class ====" << endl;
	MyString str("The Green Dragon", 17);

	//Test length
	cout << "The length of \"";
	str.outputString();
	cout << "\" is: ";
	cout << str.getLength() << endl;

	// Test toUpper
	cout << "Capitalized ";
	str.outputString();
	cout << " is: ";
	str.toUpper();
	str.outputString();
	cout << endl;

	// Test getCharAt
	cout << "The char at position 12 in ";
	str.outputString();
	cout << " is: " << str.getCharAt(12) << endl;

	// Test add char at position
	cout << "Add X to position 12 in ";
	str.outputString();
	str.addChar('X', 12);
	cout << " then it becomes: ";
	str.outputString();
	cout << endl;

	// Test resize
	cout << "The size of ";
	str.outputString();
	cout << " is " << str.getLength() << endl;
	cout << "Resizing to 7 becomes: ";
	str.resize(7);
	str.outputString();
	cout << endl;

	// Test countVowels
	cout << "Number of vowels in ";
	str.outputString();
	cout << " is: ";
	cout << str.countVowels() << endl;
	cout << endl << endl;
	
	return 0;
}

//A funciton to print a family "stick"
//Simply traverses hob's descendents, printing their names
//Parameters: the Hobbit whose family stick we should print (Hobbit *)
//Returns: nothing
void printFamilyStick(Hobbit *hob, unsigned short curYear)
{
	Hobbit *curHob = hob;
	Hobbit *child = curHob->getDescendent();
	Hobbit *parent = curHob->getAntecedent();

	cout << "The family stick of ";
	hob->getName().outputString();
	cout << ": " << endl;

	// Get to the root of the family stick
	while (parent != NULL)
	{
		curHob = parent;
	}

	// Print first Hobbit (Root in Cap)
	cout << setw(25);
	MyString rootHob;
	rootHob.deepCopy(curHob->getName());
	rootHob.toUpper();  // Caps
	rootHob.outputString();  // Print

	// Print Age
	cout << " (YOB: " << curHob->getBirthYear() <<") " << "(Age: ";
	printEleventyN(curHob->calcAge(curYear));  // Eleventy
	cout << ")" << endl;

	while (child != NULL)
	{
		//Using setw for simple formatting
		cout << setw(30) << "|" << endl;
		cout << setw(25);
		child->getName().outputString();

		// Print Age
		cout << " (YOB: " << child->getBirthYear() <<") " << "(Age: ";
		printEleventyN(child->calcAge(curYear));
		cout << ")" << endl;
		child = child->getDescendent();
	}
}

//A functon to print the relation status between two Hobbits
//Parameters: the Hobbits we will determine relationship on (Hobbit*)
//Returns: nothing
void printRelation(Hobbit *a, Hobbit *b)
{
	// Get last name
	char bLast[20];
	b->getName().copyAfterSpace(bLast);

	if(a->isParentOf(b))
	{
		a->getName().outputString();
		cout << " is a parent of ";
		b->getName().outputString();
		cout << endl;
	}
	else if(b->isParentOf(a))  //If second Hobbit is parent of the first
	{
		b->getName().outputString();
		cout << " is a parent of ";
		a->getName().outputString();
		cout << "." << endl;
	}
	else if (a->getName().findStr(bLast)) // same last name
	{
		a->getName().outputString();
		cout << " and ";
		b->getName().outputString();
		cout << " are related, but not directly." << endl;
	}
	else  //Otherwise, no relation!
	{
		b->getName().outputString();
		cout << " is not the parent of ";
		a->getName().outputString();
		cout << " and vice versa." << endl;
	}
}

// Parameters: Hobbit object
// Returns: nothing
// Description: Print the stats on the Hobbit and the descendents
//				the total # of vowels in Hobbit's name
//				and the total # of Hobbits whose names are palindromes
void printStats(Hobbit *hob)
{
	Hobbit *curHob = hob;
	Hobbit *child = curHob->getDescendent();
	unsigned short countPalin = 0;

	cout << "The statistics on ";
	hob->getName().outputString();
	cout << " and his/her descendents: " << endl;

	// Print # of vowels for first Hobbit
	if (curHob->getName().isPalindrome())  // Keep track of palindrome
		countPalin++;
	cout << "Total number of vowels in ";
	curHob->getName().outputString();
	cout << " is: ";
	cout << curHob->getName().countVowels() << endl;

	while (child != NULL)
	{
		// Print # of vowels for rest of the Hobbit
		if (child->getName().isPalindrome())  // Keep track of palindrome
			countPalin++;
		cout << "Total number of vowels in ";
		child->getName().outputString();
		cout << " is: ";
		cout << child->getName().countVowels() << endl;
		child = child->getDescendent();  // Next child
	}

	// Print total # of Hobbits with palindrome names
	cout << "Total number of Hobbits whose names are palindromes: " << countPalin << endl;
}

// Parameters: unsigned short for Hobbit's age
// Returns: nothing
// Description: Eleventy-N function that takes the Hobbit's age
//				and prints its "eleventy" version if it is in the appropriate range.
void printEleventyN(unsigned short age)
{
	if (age >= 110 && age <= 119)  // range for eleventy version age
	{
		cout << "Eleventy";  // Default at 110
		switch (age) {  // Range from 111 - 119
		case 111:
			cout << "-One";
			break;
		case 112:
			cout << "-Two";
			break;
		case 113:
			cout << "-Three";
			break;
		case 114:
			cout << "-Four";
			break;
		case 115:
			cout << "-Five";
			break;
		case 116:
			cout << "-Six";
			break;
		case 117:
			cout << "-Seven";
			break;
		case 118:
			cout << "-Eight";
			break;
		case 119:
			cout << "-Eight";
			break;
		}
	}
	else
	{
		cout << age;  // print normal number age
	}
}