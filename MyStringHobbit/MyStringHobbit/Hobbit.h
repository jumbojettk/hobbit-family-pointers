// Napon Krassner (Jett)
// CSC 2430, Homework 7
// 3/4/15
// Due: 3/10/15
// Name: Hobbit
// Description: This is the header file for Hobbit class.
//				It contains the Hobbit class with the member variables and function prototypes.

#ifndef _HOBBIT_
#define _HOBBIT_

#include <iostream>
#include "MyString.h"

using namespace std;

class Hobbit
{
public:

	//Parameterized constructor with defaults
	//Parameters: 
	//  The Hobbit's name (a const char* to work with MyString, default is empty string)
	//  The Hobbit's name length (an unsigned int, default is 0)
	//  The Hobbit's age (birthyear, an unsigned short, default is 0, i.e., just born)
	//  The Hobbit's antecedent (a Hobbit*, default is NULL)
	//  The Hobbit's descendent (a Hobbit*, default is NULL)
	//Effects: sets all private member variables to parameters passed in, or
	//  defaults.  
	Hobbit(const char* = "", unsigned int = 0, unsigned short = 0, Hobbit* = NULL, Hobbit* = NULL);

	//ACCESSORS

	//Accessor to return Hobbit's descendent
	//Parameters: None
	//Returns: a pointer to the Hobbit's descendent (Hobbit*)
	Hobbit *getDescendent() const;

	//Accessor to return Hobbit's antecedent
	//Parameters: None
	//Returns: a pointer to the Hobbit's antecedent (Hobbit*)
	Hobbit *getAntecedent() const;

	//Accessor to return Hobbit's name
	//Parameters: None
	//Returns: the Hobbit's name (a string)
	MyString getName() const;

	//Accessor to return Hobbit's age
	//Parameters: None
	//Returns: the Hobbit's age (an unsigned short)
	unsigned short getBirthYear() const;

	//MUTATORS

	//Mutator set Hobbit's descendent
	//Parameters: a pointer to the Hobbit's descendent (Hobbit*)
	//Returns: none
	void setDescendent(Hobbit*);

	//Mutator set Hobbit's antecedent
	//Parameters: a pointer to the Hobbit's antecedent (Hobbit*)
	//Returns: none
	void setAntecedent(Hobbit*);

	//Mutator set Hobbit's name
	//Parameters: the Hobbit's name (a string)
	//Returns: none
	void setName(const char*, unsigned int);

	//Mutator set Hobbit's age
	//Parameters: the Hobbit's age (a unsigned short)
	//Returns: none
	void setBirthYear(unsigned short);


	//UTILITY FUNCTIONS

	//Utility function to determine if one Hobbit is parent of another
	//Parameters: the potential child (Hobbit*)  of this Hobbit
	//Returns: true if this is parent of parameter
	//  false if this is not parent of parameter
	bool isParentOf(Hobbit *);

	// Parameters: unsigned short for current year
	// Returns: unsigned short for age
	// Description: Determine the age of the Hobbit, takes curernt year and calculate
	//				the difference of birth year
	unsigned short calcAge(unsigned short) const;

private:

	//A pointer to *one* of the Hobbit's children (NULL if none)
	Hobbit *descendent;

	//A pointer to *one* of the Hobbit's parents (NULL if none)
	Hobbit *antecedent;

	//The Hobbit's full name (first last)
	//TODO: this member variable will be MyString
	MyString name;

	//The Hobbit's age (can't be negative!)
	unsigned short birthyear;
};
#endif