#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
class intNode{

public:
	int info;
	intNode* next;
	intNode(){
		next = NULL;
	}

	intNode(int value, intNode* to_what = NULL){
		info = value;
		next = to_what;
	}
};


class IntSList{
private:
	intNode *head, *tail; 

public:

	//Constructor
	IntSList(){
		head = tail = NULL;
	}

	//Destructor
	~IntSList(){
		for (intNode* ptr; !isEmpty();){
			ptr = head->next;
			delete head;
			head = ptr;
		}
	}	

	//Is the list Empty? 
	int isEmpty(){
		return head == NULL;
	}

	//Adding Node to head
	void AddToHead(int);

	//Adding Node to Tail
	void AddToTail(int);

	//Deleting a Node from Head
	int DeleteFromHead();

	//Deleting a Node from Tail
	int DeleteFromTail();

	//Deleting a node matched from info
	int DeleteNode(int);

	//is this Element in the List?
	bool inThisList(int) const;

	void ShowList();
};

#endif