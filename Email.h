#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

/* PROGRAM DESCRIPTION
Email.h
Nick Giampietro
giampiet@pdx.edu
7 October 2013
Email class

The purpose of this class is to store data for emails,
and search all fields for a keyword

Later versions would use ctime to store the "sent" date,
for better natural ordering of emails. The current version
lacks good ordering.

END PROGRAM DESCRIPTION */

class Email
{
public:
	Email();
	~Email();

	/*
	Keyword functions
	*/
	
	// Takes a keyword string and returns 1 if any of the
	// email's data contains it; 0 otherwise
	int matches_kw(char* keyword);
	
	/*
	Setters
	*/
	
	// Your basic setter
	void set_sent(char* newSent);
	
	// Your basic setter
	void set_from(char* newFrom);
	
	// Your basic setter
	void set_to(char* newTo);
	
	// Your basic setter
	void set_subj(char* newSubj);
	
	// Your basic setter
	void set_body(char* newBody);
	
	/*
	Getters
	*/
	
	// Your basic getter
	char* get_sent();
	
	// Your basic getter
	char* get_from();

	// Your basic getter
	char* get_to();

	// Your basic getter
	char* get_subj();

	// Your basic getter
	char* get_body();
	
	// Other

	// Prints the email in a pre-determined arbitrary format	
	void print();
private:
	char* sent; // Stores sent
	char* from; // Stores from
	char* to; // Stores to
	char* subj; // Stores subject
	char* body; // Stores body 
};

/*
Operator overloads
*/

// Formatted printing of an Email
ostream& operator<<(ostream& out, Email* em);

// Also returns true if they're equal; uses strcmp to sort by "sent"
bool operator<(Email& em1, Email& em2);
// Also returns true if they're equal; uses strcmp to sort by "sent"
bool operator>(Email& em1, Email& em2);
