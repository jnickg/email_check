#include <cstdlib>
#include "Classifier.h"

/* PROGRAMMING ASSIGNMENT ONE
CS163 Assignment 1
15 Oct 2013
Nick Giampietro
giampiet@pdx.edu

This assignment implements and tests a linear linked list
and a linear ordered list, and demonstrates their efficacy.

INPUT: varargs in the program call:
First vararg is the txt file to be read
remaining varargs are keywords to search emails for
Example:
	./a.out emails.txt doodski evil

OUTPUT: success or error messages for everything,
echoes for all input from txt file, echoes for all
keyword varargs, and a list of all emails which
contain any of the keywords.

*/

using namespace std;

#define USAGE(x)																\
	if(x<3)																		\
	{																			\
		cout << "\nuse at least 3 arguments:\n\t"								\
			 << "\"./a.out filename keyword(s)\""								\
			 << endl;															\
		return 0;																\
	};

int main(int argc, char *argv[])
{
	char* file;
	char* kw;
	Classifier junk_mail;

	USAGE(argc);

	file = argv[1];
	
	cout << "\n\nAttempting to load from...\n\t" << file << "\n" << endl;
	junk_mail.load_emails(file);
	cout << "\n\nFiles loaded successfully. Displaying emails:\n" << endl;
	junk_mail.display_email();


	cout << "\n\nEmails displayed. Adding new keywords from command line:" << endl;
	for(int i = 2; i<argc; i++)
	{
		kw = argv[i];
		cout << "KEYWORD: " << kw << endl;
		junk_mail.add_keyword(kw);
	}
	
	cout << "\n\nAll keywords added:\n" << endl;
	junk_mail.display_keywords();

	cout << "\n\nSearching loaded emails for presence of any keywords...\n" << endl;
	junk_mail.display_matches();

	cout << "\n\nFANTASTIC!\n\nTerminating program. Goodbye." << endl;
	return 0;
}
