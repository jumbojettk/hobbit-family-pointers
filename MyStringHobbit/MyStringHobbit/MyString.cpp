// Napon Krassner (Jett)
// CSC 2430, Homework 5
// 3/4/15
// Due: 3/10/15
// Name: Hobbit
// Description: This is the implementation file for MyString class.
//				It contains the MyString class function definitions of the MyString object
//				to be implemented by the client.

#include "MyString.h"
#include <iostream>

//**********CONSTRUCTORS**********

MyString::MyString()
{
	length = 0;
	pStr = new char[length];
}

MyString::MyString(const char* s, unsigned int l)
{
	//we'll copy into temporary memory
	char *tmp = new char[l];

	//and make pStr point to start of c-string
	// so pStr points to the start of the string throughout
	pStr = tmp;

	//not looking for \0 because we know exact length
	for(unsigned int i = 0; i < (l - 1); i++)
	{
		//copy contents of s to tmp one at a time
		*tmp = *s;

		//increment tmp and s
		tmp++;
		s++;
	}

	//to be safe, will set last character to \0
	// in case a malformed c-string is passed in
	*tmp = '\0';

	//no longer using tmp, good practice to set to NULL
	//note: pStr points to the newly-allocated memory
	tmp = NULL;

	length = l;
}

// Copy constructor
MyString::MyString(const MyString& original)
{
	deepCopy(original);
}

//Destructor
MyString::~MyString()
{
	delete[] pStr;
}

//**********ACCESSORS**********

unsigned int MyString::getLength() const
{ 
	return length;
}

char MyString::getCharAt(unsigned short position) const
{
	// return the last element if position is out of range
	if (position > length - 2)
		position = length - 2;

	// pStr always points to start of array so create temp
	char *tmp = pStr;

	tmp = tmp + position;  // Move to the position

	return *tmp;
}

//**********MUTATORS**********

//Note: this function modifies MyString
void MyString::toUpper()
{
	//don't want to change pStr pointer!
	//it should always point to start of char array
	char *tmp = pStr;

	while(*tmp != '\0')
	{
		*tmp = toupper(*tmp);
		tmp++;
	}
}

void MyString::resize(unsigned int newLength)
{
	char *tmp = new char[newLength];  // new array with new length

	if (newLength < length)
		copy(pStr, tmp, newLength);  // Copy up to the newLength
	else if (newLength >= length)  // account for unsigned short
		copy(pStr, tmp, length);  // Copy up to the current length

	delete[] pStr;  // Delete old pStr
	pStr = tmp;  // Assign new pStr with new length

	tmp = NULL;  // Point tmp to nowhere

	length = newLength;  // Assign new length
}

void MyString::addChar(char newC, int position)
{
	if (position > length - 1)
		position = length - 1;

	resize(length + 1);  // Increase size by one everytime add char
	char *tmp = pStr;  // pStr always point to start
	char *newTmp = new char[length];  // length is already increased
	char *newTmpBase = newTmp;  // Start of new array
	unsigned int count = 0;
	char posChar = this->getCharAt(position);
	
	while (*tmp != posChar)  // Copy up to position
	{
		*newTmp = *tmp;
		newTmp++;
		tmp++;
	}

	*newTmp = newC;  // Add the new char at that position
	newTmp++;

	while (*tmp != '\0')
	{
		*newTmp = *tmp;
		newTmp++;
		tmp++;
	}

	*newTmp = '\0';  // Ending null

	delete[] pStr;
	pStr = newTmpBase;  // Point to new array

	// Set all temp pointers to NULL
	newTmp = NULL;
	tmp = NULL;
	newTmpBase = NULL;	
}

//**********UTILITY**********
void MyString::outputString() const
{
	//don't want to change pStr pointer!
	//it should always point to start of char array
	char *tmp = pStr;

	while(*tmp != '\0')
	{
		cout << *tmp;
		tmp++;
	}

}

//Nobody in class chose this (or nobody e-mailed me their solution)
// so here's an example implementation
// I threw this together fairly quickly, if you find
// an edge case and can break it please let me know!
bool MyString::findStr(const char* key) const
{
	//preserve key as pointer to start of string
	const char *tmpKey = key;

	//don't want to change pStr pointer!
	//it should always point to start of char array
	char *tmp = pStr;

	//find occurence of key's first char in tmp (i.e., pStr)
	while(*tmp != '\0')
	{
		//if we find an occurence of the first character
		// look for the full key starting here (at current tmp)
		char *here = tmp;

		//this loop will continue as long as the characters
		// in the portion of pStr we are looking at match
		// the characters in key
		while(*here == *tmpKey)
		{
			here++;
			tmpKey++;

			//if we get to the end of tmpKey
			// and still in the loop (meaning, all chars
			// were equal up to this point) then we have a match
			if(*tmpKey == '\0')
				return true;
		}

		//otherwise, increment tmp and keep looking
		tmp++;
	}

	return false;

}

unsigned int MyString::countVowels() const
{
	//don't want to change pStr pointer!
	//it should always point to start of char array
	char *tmp = pStr;

	int count = 0;

	while (*tmp != '\0')
	{
		if ((*tmp == 'a') || (*tmp == 'A'))
			count++;
		else if ((*tmp == 'e') || (*tmp == 'E'))
			count++;
		else if ((*tmp == 'i') || (*tmp == 'I'))
			count++;
		else if ((*tmp == 'o') || (*tmp == 'O'))
			count++;
		else if ((*tmp == 'u') || (*tmp == 'U'))
			count++;
		tmp++;
	}

	return count;
}

void MyString::copyToSpace(char* dest) const
{
	//don't want to change pStr pointer!
	//it should always point to start of char array
	char *tmp = pStr;

	//probably not the most efficient,
	// but we already have a function to make sure
	// we have a space, so let's use that :)
	if(findStr(" "))
	{
		while(*tmp != ' ')
		{
			*dest = *tmp;
			tmp++;
			dest++;
		}

	}

	*dest = '\0';
}

void MyString::copyAfterSpace(char* dest) const
{
	char *tmp = pStr;

	if (findStr(" ")) // Check if there is space
	{
		// Get to space
		while (*tmp != ' ')
		{
			tmp++;
		}
		tmp++; // Get to first char in last name

		while (*tmp != '\0')  // Until it reaches end
		{
			*dest = *tmp;
			tmp++;
			dest++;
		}
		*dest = '\0';
	}
}

bool MyString::isPalindrome() const
{
	MyString stringCopy(*this);  // use copy-constructor to copy original string
	stringCopy.toUpper();  // ignore case

	char *tmpFront = stringCopy.pStr;
	char *tmpBack = stringCopy.pStr;
	bool palindrome = false;
	tmpBack = tmpBack + (length - 2);  // Start from the back

	for (int i = 0; i < length/2; i++)
	{
		if (*tmpFront == *tmpBack)
		{
			palindrome = true;
			tmpFront++;
			tmpBack--;
		}
		else
		{
			palindrome = false;
			break;
		}
	}

	tmpFront = NULL;
	tmpBack = NULL;

	return palindrome;
}

void MyString::deepCopy(const MyString& original)
{
	length = original.length;
	pStr = new char[length];
	copy(original.pStr, pStr, length);
}

//**********PRIVATE MEMBER FUNCTIONS**********
void MyString::copy(char* pCStr1, char* pCStr2, unsigned int n)
{
	unsigned int count = 0;
	// Shallow copy
	while (*pCStr1 != '\0' && count < n-1) // Save the last space for \0
	{
		*pCStr2 = *pCStr1;
		pCStr1++;
		pCStr2++;
		count++;
	}
	*pCStr2 = '\0';
}