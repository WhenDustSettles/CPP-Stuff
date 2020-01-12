#include<iostream>
#include"SLL.h"

int main(int argc, char const *argv[])
{	

	//Test code below
	IntSList list;

	cout<<"<<<<Singly Linked List>>>>"<<endl;
	cout<<"Choose Functionalities below"<<endl;
	cout<<"Press 1 to Add to Head."<<endl;
	cout<<"Press 2 to Add to Tail."<<endl;
	cout<<"Press 3 to Delete from Head."<<endl;
	cout<<"Press 4 to Delete from Tail."<<endl;
	cout<<"Press 5 to Delete any Node."<<endl;
	cout<<"Press 6 to Check if input is present in the list."<<endl;
	cout<<"Press 7 to Show the List."<<endl;
	cout<<"Press 0 to quit anytime."<<endl;

	int choice;
	int val;

	while(true){

		cin>>choice;

		if (choice == 1){
			cout<<"Element to Add: ";
			cin>>val;
			list.AddToHead(val);
		}

		else if (choice == 2){
			cout<<"Element to Add: ";
			cin>>val;
			list.AddToTail(val);
		}

		else if (choice == 3){
			cout<<"Deleting from Head: ";
			list.DeleteFromHead();
		}	

		else if (choice == 4){
			cout<<"Deleting from Tail: ";

			list.DeleteFromTail();
		}	

		else if (choice == 5){
			cout<<"Element to Delete from List: ";
			cin>>val;
			list.DeleteNode(val);
		}

		else if (choice == 6){
			bool out;
			cout<<"Element to check presence of: ";
			cin>>val;
			out = list.inThisList(val);
			cout<<out<<endl;
		}

		else if (choice == 7){
			list.ShowList();
		}

		else if (choice == 0){
			break;
		}


		cout<<"Next Command: ";
	}


	return 0;
}
