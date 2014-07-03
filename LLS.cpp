//Rob Fugate
//Program 2: Merge Sort with Linked List
//Date: 2-19-2013

#include <iostream>
#include <string>
#include "LL.h"

using namespace std;

void LL::sort(){					//Linked List Class - Called from main
	if(head) head = head->sort();			//Checks to see if there is a head if so pass it to sort in LLN
}

LLN * LLN::split(){					//Splits the list from this point down. This is the head of one list the other list is returned.
	if(next == NULL) return NULL;
	LLN *a = next->split();				
	LLN *c = this->next;
	next = a;
	return c;
}

LLN * LLN::sort(){					//Sorts the list from this point forward Returns the head of the new sorted list
	if(next == NULL) return this;			//1 element list
	LLN *ptr;
	LLN *temp;
	temp = this;					//Pointer is equal to the current node
	ptr = temp->split();				//ptr points to the split nodes that were returned from split method
	if(next) temp = temp->sort();
	if(ptr->next) ptr=ptr->sort();

	LLN *answer = temp->merge(ptr);			//answer pointer points to the new merged list and then answer is returned
	return answer;	
}

LLN * LLN::merge(LLN *b){				//Merge this with b into a single sorted list. Returning the head.
	if(b==NULL) return this;	
	LLN *ptr;					//Merge pointer

	if(s < b->s){					//This if statement will compare the two nodes
		ptr=this;
		if(this->next)			
			ptr->next = this->next->merge(b);
		else
			ptr->next=b;
	}
	else{
		ptr = b;
		if(b->next)
			ptr->next=b->next->merge(this);
		else
			ptr->next=this;
	}
	return ptr;
}
