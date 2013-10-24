#include <cstdlib>

/* LINEARLY-LINKED LIST
LLL.h
Nick Giampietro
giampiet@pdx.edu
10 Oct 2013

See description below

THIS IS A TEMPLATE CLASS WHICH REQUIRES FUNCTION
IMPLEMENTATIONS INSIDE THE .h FILE

*/

#ifndef LLSTRUCT
#define LLSTRUCT
template <class T> struct node
{
	T data;
	node<T>* next;
};
#endif // LLSTRUCT

/*	LLL--Linear Linked List
	
	A linear linked list is a series of nodes
	which contain pointers to other nordes. Each
	node contains an object of type T, which allows
	this class to be useful in any situation.

*/
template <class T> class LLL
{
public:
	LLL()
	{
		head = 	NULL;
		head = NULL;
		last = NULL;
		cur = NULL;
		count = 0;
	}

	~LLL()
	{
		// If there is a head
		if(head)
		{
			node<T>* tmp;
			while(head->next)
			{
				// Set tmp to the 'in-between' node
				tmp=head->next;
				// Set head to point over tmp (unless
				// tmp is the 2nd to last one)
				if(tmp->next)
					head->next = tmp->next;
				// Then cull tmp
				delete tmp;
			}
			delete head;
		}
		
	}

	/*
	Head/Last functions
	*/
	
	// Creates a new node and makes item its data; prepends it to the LLL
	int add_to_head(T item)
	{
		// Create new node with T
		node<T>* tmp = new node<T>;
		tmp->data = item;

		// Append head to tmp
		tmp->next = head;
	
		if (NULL==head)
		{ // If no items in list, it's both last and head
			last = tmp;
			head = tmp;
			cur = tmp;
		}
	
		else
		{ // Otherwise it's just the new head
			if(cur == head)
			{
				cur = tmp;
			}
			head = tmp;
		}

		count++;
		return 1;
	}



	// Creates a new node and makes item its data; appends it to the LLL
	int add_to_end(T item)
	{
		// Create new node with T
		node<T>* tmp = new node<T>;
		tmp->data = item;
		tmp->next = NULL;

		if (NULL==last)
		{ // If no items in list, it's both last and head
			last = tmp;
			head = tmp;
		}

		else
		{ // Otherwise it's just the new last
			last->next = tmp;
			last = tmp;
		}

		count++;
		return 1;	
	}



	// Removes the first node in the LLL
	int remove_last()
	{
		if (head == NULL)
			return 0;
		
		else if (head->next == NULL)
		{
			delete head;
			head = NULL;
			count--;
			return 1;
		}
	
		else {
			remove_last(head->next);
			return 1;
		}
	}



	// Removes the last node in the LLL
	int remove_first()
	{
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			node<T>* tmp = head;
			head = head->next;
			delete tmp;
			tmp = NULL;

			count--;
			return 1;
		}
	}

	
	
	// Returns the node at the beginning of the LLL
	node<T>* get_head()
	{
		return head;
	}

	
	
	// Returns the final node in the LLL
	node<T>* get_last()
	{
		return last;
	}

	/*
	Iteration functions
	*/
	
	
	
	// Returns 1 if it resets its iterator to the head of the LLL; 0 if head points to NULL
	int it_init()
	{
		if(!(head==NULL))
		{
			cur = head;
			return 1;
		}
		else return 0;
	}
	
	
	
	// Returns 1 if it advanced to the next node; 0 if the next node pointed to NULL
	int it_adv()
	{
		if(cur->next == NULL)
			return 0;
		else 
		{
			cur = cur->next;
			return 1;
		}
	}
	
	
	
	// Returns the node to which the iterator currently points
	T* it_current()
	{
		return &cur->data;
	}
	
	
	
	// Returns 1 if item comes after the iterator; 0 if they are equal; -1 if it comes before
	int it_comp(T* item)
	{
		T c = cur->data;
		if(c < *item) return 1;
		else if(c > *item) return -1;
		else return 0;
	}

	/*
	Metadata functions
	*/
	
	
	
	// Returns the current node count
	int get_count()
	{
		return count;
	}

	
	
	// Forces a re-count of nodes and returns that; does not reset node count
	int fget_count()
	{
		return fget_count(head);
	}

private:
	node<T>* head; // The head
	node<T>* last; // The last
	node<T>* cur; // The iterator 
	int count; // The number of nodes
	
	
	
	// Used to force a recount of count
	int fget_count(node<T>* strt)
	{
		if(NULL == strt) return 0;
		return fget_count(strt->next) +1;
	}
};
