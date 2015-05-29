#include <iostream>

#include "msg_list.h"

msg_list::msg_list(){

	front = NULL;
	back = NULL;

}

void msg_list::append(datagram*d){

	msg_list_node* q=new msg_list_node;

	q->d = d;
	q->next = NULL;

	if (front == NULL&&back == NULL){

		front = q;
		back = q;

	}

	else{

		back->next = q;
		back = q;

	}

}

void msg_list::display() {
	msg_list_node *tmp;  int i;
	
	if(front==NULL) {
		cout << "** List is empty. **\n";
		return;
	}
	
	tmp = front;  i = 1;
	while(tmp!=NULL) {
		cout << "Datagram " << i++ << ":  \n";
		(tmp->d)->display();
		cout << "\n";
		tmp = tmp->next;
	}
	
}


