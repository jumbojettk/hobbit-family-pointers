// Napon Krassner (Jett)
// CSC 2430, Homework 7
// 3/4/15
// Due: 3/10/15
// Name: MyString
// Description: This is the header file for MyString class.
//				It contains the MyString class with the member variables and function prototypes.

#ifndef _MYSTRING_
#define _MYSTRING_

#include <iostream>

using namespace std;

class MyString
{
public:
	//**********CONSTRUCTORS**********
	
	//Default constructor creates an empty
	//c-string and sets length to 0
	MyString();

	//Default constructor creates a string based on parameters
	//Parameters: const char* to copy chars from, length of string (unsigned int)
	MyString(const char*, unsigned int);

	// Parameters: MyString object (as parameter, const for safety)
	// Returns: nothing
	// Description: Copy constructor, takes another MyString as a parameter and copies all
	//				private data into this object.
	MyString(const MyString&);

	//Destructor
	~MyString();


	//**********ACCESSORS**********
	
	//Accessor to return length of the string
	//Parameters: none
	//Returns: the length of the string (an unsigned int)
	unsigned int getLength() const;

	// Parameters: int for position
	// Returns: char at the given position
	// Description: Returns the char at a given position via parameter in the string.
	char getCharAt(unsigned short) const;

	//**********MUTATORS**********
	
	//Converts this MyString object to upper-case letters
	void toUpper();

	// Parameters: int for new size
	// Returns: nothing
	// Description: Resize the stored C-string to a size passed in via input parameter.
	void resize(unsigned int);

	// Parameters: char to add, int for position to add
	// Returns: nothing
	// Description: Add a char at any position in the C-string and resizing if neccessary.
	void addChar(char, int);

	//**********UTILITY**********

	//Utility function to output the string element by element
	//Parameters: none:
	//Returns: nothing
	//Effects: prints the C-string to the screen
	void outputString() const;

	//Finds occurence of parameter this MyString object
	//Parameters: the C-string to search for (const char*)
	//Returns: true if found, false otherwise
	bool findStr(const char*) const;

	//Count # of vowels in this MyString object
	//Parameters: none
	//Returns: the # of vowels in this MyString object (unsigned int)
	// Note: we aren't counting Y or y
	unsigned int countVowels() const;

	//Copy string up to the first occurence of a space into parameter
	//(this is a generic version of the "first name" function you developed)
	//Parameters: char* to store substring
	//Returns: nothing
	//Effects: the char* passed in will contain the characters from this MyString object
	// up to the first space (if \0 reached before space is found, will copy nothing!)
	void copyToSpace(char*) const;

	// Parameters: char* to store substring
	// Returns: nothing
	// Description: char* passed in will contain characters from MyString object
	//				starting from space until it reaches \0.
	void copyAfterSpace(char*) const;

	// Parameters: nothing
	// Returns: true if palindrome, false otherwise
	// Description: Bool function that returns true if string is palindrome.
	// Note: ignore case is also a palindrome
	bool isPalindrome() const;

	// Parameters: MyString object
	// Returns: nothing
	// Description: Deep copy of MyString object, set private member variables to original.
	void deepCopy(const MyString&);

private:
	//A character array
	char *pStr;

	//Length of character array
	unsigned int length;

	//**********PRIVATE MEMBER FUNCTIONS**********

	// Parameters: C-string array to copy from, C-string array to copy to,
	//				the number of elements to copy (unsigned int)
	// Returns: nothing
	// Description: Copy elements from one array to another up to the number of elements to copy.
	void copy(char*, char*, unsigned int);
};

#endif