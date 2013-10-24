#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "Email.h"
#include "LLL.h"
#include "LOL.h"

using namespace std;

/* PROGRAM DESCRIPTION
Classifier.h

The purpose of this class is to provide a way of
classifying emails, probably junk mail, and sorting
them by keyword.

To read emails, this class uses the Email class, written
by Nick Giampietro, and stores them in a linear ordered
list (using the LOL class, also written by Nick Giampietro).

To store keywords, this class uses the LLL class of type char*

This class, in later versions, would order keywords alphabetically.
However, because this solution was implemented using a template
class, it was not easily possible. More research is required.

Nick Giampietro
giampiet@pdx.edu
7 October 2013
END PROGRAM DESCRIPTION */

class Classifier
{
public:
	Classifier();
	~Classifier();

	// Read emails from a file; returns 1 if nothing goes wrong; 0 otherwise.
	// This function adds loaded emails to em_list
	int load_emails(char f[]);
	
	// Display all emails; returns 1  if successful; 0 if there was nothing
	// to display, or something went wrong.
	int display_email();

	// Add a keyword to the list; returns 1 if successful.
	int add_keyword(char kw[]);

	// Displays all keywords; returns 1 if successful; 0 if there was nothing
	// to display, or something went wrong.
	int display_keywords();

	// Displays all emails that use one of the keywords in kw_list, in
	// any of its data fields; returns 0 if either em_list or kw_list
	// has nothing to display.
	int display_matches();
private:
	LOL<Email> em_list; // A linear ordered list of emails
	LLL<char*> kw_list; // A linear linked list of keywords
};
