#include <cstdlib>

/* LINEAR ORDERED LIST
LOL.h
Nick Giampietro
giampiet@pdx.edu
10 Oct 2013

See description below.

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

/*	LOL--Linear Ordered List
	
	A linear ordered list is structurally
	identical to a linearly-linked list, but
	requires that type T can be compared via
	the operator< comparator. LOL will use
	this comparator to locate the appropriate
	place in the list to which a new node's
	data belongs.

*/
template <class T> class LOL
{
public:
	LOL()
	{
		head = NULL;
		last = NULL;
		cur = NULL;
		count = 0;
	}

	~LOL()
	{
		if(it_init())
		{
			while(it_adv())
				delete prev;
			delete cur;
			prev = NULL;
			cur = NULL;
		}
		// Delete all nodes
	}

	/*
	Head/Last functions
	*/
	
	
	
	// Creates a new node and makes item its data; prepends it to the LLL
	int add(T* item)
	{
		// Create new node with T
		node<T>* tmp = new node<T>;
		tmp->data = *item;
	
		// If no items in the LOL, don't check comparison;
		// just add to head
		if(head == NULL)
		{
			head = tmp;
			count++;
			return 1;
		}

		// If only one item in the LOL, compare to head
		// and add appropriately
		else if (head->next == NULL)
		{
			cur = head;
			if(cur->data < tmp->data)
			{
				head->next = tmp;
				tmp->next = NULL;
			}
			else
			{
				tmp->next = head;
				head = tmp;
			}
			count++;
			return 1;
		}
	
		// Otherwise see where it belongs.
		else if (head->next)
		{
			cur = head;
			while(cur->next)
			{
				if(cur->data < tmp->data)
				{
					prev = cur;
					cur = cur->next;
				}
				else
				{
					tmp->next = cur;
					prev->next = tmp;
				}
			}
			count++;
			return 1;
		}

		else return 0;
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
		if(head)
		{
			cur = head;
			return 1;
		}
		else return 0;
	}
	
	
	
	// Returns 1 if it advanced to the next node; 0 if the next node pointed to NULL
	int it_adv()
	{
		// If not at the end, move prev and cur forward by one
		if(cur->next)
		{
			prev = cur;
			cur = cur->next;
			return 1;
		}
		// If at the end, return that it's done and don't move forward
		else return 0;
	}
	
	
	
	// Returns the node to which the iterator currently points
	T* it_current()
	{
		return &(cur->data);
	}
	
	
	
	// Returns 1 if item comes after the iterator; 0 if they are equal; -1 if it comes before
	int it_comp(T* item)
	{
		T c = cur->data;
		if(c < (*item)) return 1;
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
	node<T>* head; // the head
	node<T>* last; // the last one
	node<T>* cur; // the iterator
	node<T>* prev; // the dragged iterator
	int count; // how many nodes there are
	
	
	// Used to force a recount of count
	int fget_count(node<T>* strt)
	{
		if(NULL == strt) return 0;
		return fget_count(strt->next) +1;
	}
};
