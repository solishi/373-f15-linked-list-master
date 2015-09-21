#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	for (list_t * point =head;point->next!=NULL;point=point->next){
		if ((new_element->index > point->index)&&(new_element->index<=point->next->index)){
			list_t* temp=new list_t;
			temp->next=point->next;
			temp->index=new_element->index;
			point->next=temp;
			return head;
		}
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t *n_list=NULL;
	list_t *c_list=head;
	list_t *t_list;
	while (c_list!=NULL){
		t_list=c_list->next;
		c_list->next=n_list;
		n_list=c_list;
		c_list=t_list;
	}
	return n_list;
}
