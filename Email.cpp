#include "Email.h"

Email::Email()
{
	sent = NULL;
	from = NULL;
	to = NULL;
	subj = NULL;
	body = NULL;
}

Email::~Email()
{
	delete sent;
	sent = NULL;
	delete from;
	from = NULL;
	delete to;
	to = NULL;
	delete subj;
	subj = NULL;
	delete body;
	body = NULL;
}



int Email::matches_kw(char* keyword)
{
	char* xist; // Temp to check
	// strstr returns null if arg2 is not present in arg1,
	// so if all of these return null then keyword is not present
	xist = strstr(subj, keyword);
	if(NULL==xist)
		xist = strstr(body, keyword);
	if(NULL==xist)
		xist = strstr(to, keyword);
	if(NULL==xist)
		xist = strstr(from, keyword);

	
	if(!(NULL==xist)) return 1;
	else return 0;
}



void Email::set_sent(char* newSent)
{
	if(!(NULL==sent))
		delete sent;
	sent = newSent;
}



void Email::set_from(char* newFrom)
{
	if(!(NULL==from))
		delete from;
	from = newFrom;
}



void Email::set_to(char* newTo)
{
	if(!(NULL==to))
		delete to;
	to = newTo;
}



void Email::set_subj(char* newSubj)
{
	if(!(NULL==subj))
		delete subj;
	subj = newSubj;
}



void Email::set_body(char* newBody)
{
	if(!(NULL==body))
		delete body;
	body = newBody;
}



char* Email::get_sent()
{
	return sent;
}



char* Email::get_from()
{
	return from;
}



char* Email::get_to()
{
	return to;
}



char* Email::get_subj()
{
	return subj;
}



char* Email::get_body()
{
	return body;
}



void Email::print()
{
	cout << "\n"
		 << "Email from " << from << endl
		 << "\tto " << to << endl
		 << "subject: " << subj << endl
		 << "(sent: " << sent << ")" << endl
		 << "====================\n"
		 << body
		 << "\n====================\n"
		 << endl;
}



ostream& operator<<(ostream& out, Email* em)
{
	char* from = em->get_from();
	char* to = em->get_to();
	char* subj = em->get_subj();
	char* sent = em->get_sent();
	char* body = em->get_body();
	out
		<< "\n"
		<< "Email from" << from << "\n"
		<< "\tto " << to << ".\n"
		<< "subject: " << subj << "\n"
		<< "(sent: " <<  sent << ")\n"
		<< "====================\n"
		<< body
		<< "\n====================\n"
		<< endl;
	return out;
}



bool operator<(Email& em1, Email& em2)
{
	char* t1 = em1.get_sent();
	char* t2 = em2.get_sent();

	int cmp = strcmp(t1, t2);

	if(0<=cmp) return true;
	else return false;
}



bool operator>(Email& em1, Email& em2)
{
	char* t1 = em1.get_sent();
	char* t2 = em2.get_sent();

	int cmp = strcmp(t1, t2);

	if(0>=cmp) return true;
	else return false;
}
