#include<iostream>
#include "intSLList.h"
using namespace std;

void IntSList::AddToHead(int value){
	head = new intNode(value, head);
	if (tail == NULL){
		//This means the List was empty
		//Thus:
		tail = head;
	}
}


void IntSList::AddToTail(int value){
	if (tail != NULL){
		intNode* node  = new intNode(value);
		tail->next = node;
		tail = node;
	}

	else {
		head = tail = new intNode(value);
	}

}

int IntSList::DeleteFromHead(){
	int info;
	info = head->info;
	intNode* tmp = head;
	head = head->next;
	if (head == tail){
		tail = NULL;
	}
	delete tmp;
	return info;
}


int IntSList::DeleteFromTail(){

	int info;

	//If one node 
	if ((head == tail) && tail != NULL){
		info = tail->info;
		tail = NULL;
		head = NULL;
	}
	//If more than one node
	intNode* temp;
	for (temp = head; temp->next!=tail; temp = temp->next){
		}
	info = tail->info;
	intNode* to_del = tail;
	tail = temp;
	tail->next = NULL;
	delete to_del;
	return info;
}


int IntSList::DeleteNode(int value){

	if (inThisList(value)!= true){
		cout<<"value: "<<value<<" :is not found in the list"<<endl;
		return 0;
	}

	int info;
	intNode *temp_lead , *temp_follow ;
	for (temp_lead = head, temp_follow = NULL ; temp_lead!=tail; temp_follow = temp_lead, temp_lead = temp_lead->next){
		if (temp_lead->info == value){


			if (temp_lead == head){
				info = DeleteFromHead();
				
				return 1;
			}

			

			else if (temp_lead != head){

				info = temp_lead->info;
				intNode* to_del = temp_lead;
				temp_follow->next = temp_lead->next;

				delete to_del;

				return 1;
			}

		}	
	}

	 if (temp_lead == tail){
		intNode* to_del = tail;
		info = tail->info;
		tail = temp_follow;
		delete to_del;

		return 1;
	}

}

bool IntSList::inThisList(int value) const{
	intNode* temp;
	for (temp = head; temp != tail; temp = temp->next){
		if ((temp->info == value) || (temp->next->info == value) )
			return true;
	}
}

void IntSList::ShowList(){

	if (isEmpty())
	{
		cout<<"List is Empty..."<<endl;
	}
	else{

		intNode* ptr;
		cout<<" || ";
		for(ptr = head; ptr != tail; ptr = ptr->next){
			cout<<ptr->info<<" -> ";
		}
		cout<<ptr->info<<" || "<<endl;
	}
}

