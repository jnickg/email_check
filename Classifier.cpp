#include "Classifier.h"

Classifier::Classifier()
{

}

Classifier::~Classifier()
{
	// Both fields will delete when they go out of scope.
}



int Classifier::load_emails(char f[])
{
	Email* nu1;		// temp pointer to create new emails and pass into LOL
	int worked = 1;	// return value will be 1 if nothing goes wrong
	char buff[256];	// self-explanatory
	char* nuStr;	// used to move buffer to dynamic memory

	cout << "Attempting to open file \'" << f << "\'" << endl;
	
	ifstream file;
	file.open(f);

	if (file.is_open())
	{
		while(!(file.eof()))
		{
			cout << "Creating new email..." << endl;
			nu1 = new Email();

			// The following five blocks are written exactly
			// as this one is.
			cout << "Reading next email from file..." << endl;
			cout << "\'Sent\' info..." << endl;
			// Get relevant line & ignore delimiter
			file.get(buff, 255, '\n');
			file.ignore();
			// Move to dynamic memory
			nuStr = new char[strlen(buff)+1];
			strcpy(nuStr, buff);
			// Assign new Email's field
			nu1->set_sent(nuStr);

			cout << "\'From\' info..." << endl;
			file.get(buff, 255, '\n');
			file.ignore();
			nuStr = new char[strlen(buff)+1];
			strcpy(nuStr, buff);
			nu1->set_from(nuStr);

			cout << "\'To\' info..." << endl;
			file.get(buff, 255, '\n');
			file.ignore();
			nuStr = new char[strlen(buff)+1];
			strcpy(nuStr, buff);
			nu1->set_to(nuStr);

			cout << "\'Subj\' info..." << endl;
			file.get(buff, 255, '\n');
			file.ignore();
			nuStr = new char[strlen(buff)+1];
			strcpy(nuStr, buff);
			nu1->set_subj(nuStr);

			cout << "\'Body\' info..." << endl;
			file.get(buff, 255, '\n');
			file.ignore();
			nuStr = new char[strlen(buff)+1];
			strcpy(nuStr, buff);
			nu1->set_body(nuStr);

			// To account for the extra line beteween each email
			cout << "extra buffer for space..." << endl;
			file.get(buff, 255, '\n');
			file.ignore();

			cout << "Email setting succeeded." << endl;

			cout << "Trying to add the loaded email to the LOL" << endl;
			if(0==em_list.add(nu1)) worked=0; // Will get 0 if something went wrong
			
			cout << "...success!" << endl;
			file.peek(); // To set the eof flag, just in case.
		}
		file.close();
	}
	else cout << "Unable to open file: \'" << f << "\'" << endl;

	return worked;
}



int Classifier::display_email()
{
	// See LOL header file for more info
	if(1==em_list.it_init())
	{
		do
		{
			//Both options work
			//cout << em_list.it_current() << endl;
			(*em_list.it_current()).print();
		} while(1==em_list.it_adv());
		return 1;
	}
	else return 0;
}



int Classifier::add_keyword(char kw[])
{
	// Later versions would take char kw[] and copy THAT, but
	// because I used a template class (to keep my sanity I had
	// to be doing something new in this assignment) that was
	// not easily possible.

	// Move to dynamically-allocated memory, to set the LLL's pointer.
	char* nuKw = new char[strlen(nuKw)+1];
	strcpy(nuKw, kw);
	kw_list.add_to_end(nuKw);
	return 1;
}



int Classifier::display_keywords()
{
	// See LLL header file for more info
	if(1==kw_list.it_init())
	{
		do
		{
			cout << "Added keyword: " << *(kw_list.it_current()) << endl;
		} while(1==kw_list.it_adv());
		return 1;
	}
	else return 0;
}



int Classifier::display_matches()
{
	// See LLL header file for more info
	if(1==kw_list.it_init())
	{
		// For each keyword...
		do
		{
			if(1==em_list.it_init())
			{
				// Check all emails for its presence
				do
				{
					Email* tmp = em_list.it_current();
					char* kwtmp = *(kw_list.it_current());
					if(1==(tmp->matches_kw(kwtmp)))
						cout << "MATCHING EMAIL FOR KW " << kwtmp << "\n" << tmp << endl;
				} while(1==em_list.it_adv());
			}
			else return 0;
		} while(1==kw_list.it_adv());
		return 1;
	}
	else return 0;
}
