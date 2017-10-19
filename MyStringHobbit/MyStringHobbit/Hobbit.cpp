// Napon Krassner (Jett)
// CSC 2430, Homework 5
// 3/4/15
// Due: 3/10/15
// Name: Hobbit
// Description: This is the implementation file for Hobbit class.
//				It contains the Hobbit class function definitions of the Hobbit object
//				to be implemented by the client.

#include "Hobbit.h"
#include <iostream>
#include "MyString.h"

using namespace std;

Hobbit::Hobbit(const char* n, unsigned int nLength, unsigned short b, Hobbit *an, Hobbit *d)
{
	antecedent = an;
	descendent = d;
	name.deepCopy(MyString(n, nLength));

	//Note: will always be >= 0, since we are using
	// an unsigned short.  If you use a signed int for some
	// reason, need to make sure it is >=0!
	birthyear = b;
}

Hobbit* Hobbit::getDescendent() const
{
	return descendent;
}

MyString Hobbit::getName() const
{
	return name;
}

unsigned short Hobbit::getBirthYear() const
{
	return birthyear;
}

Hobbit* Hobbit::getAntecedent() const
{
	return antecedent;
}

void Hobbit::setAntecedent(Hobbit *a)
{
	antecedent = a;
}

void Hobbit::setDescendent(Hobbit *d)
{
	descendent = d;
}

void Hobbit::setName(const char* n, unsigned int nLength)
{
	name = MyString(n, nLength);
}

void Hobbit::setBirthYear(unsigned short b)
{
	//No need to check for age >=0
	// since working with unsigned short
	// BUT if you went "off script"
	// for the assignment and used an int, 
	// would need to check
	birthyear = b;
}

bool Hobbit::isParentOf(Hobbit *child)
{
	//Is this the parent of child?
	//Simply check child's antecedent,
	// (and doesn't hurt to check descendent of this too)
	if((child->getAntecedent() == this) && (this->getDescendent() == child))
		return true;
	return false;
}

unsigned short Hobbit::calcAge(unsigned short curYear) const
{
	unsigned short age = curYear - birthyear;
	return age;
}