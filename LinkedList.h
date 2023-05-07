#ifndef LinkedList_h
#define LinkedList_h

class LinkedList {
private:
	struct Node{	
		Node(int number) {
			data = number;
			next = nullptr;
		}
		int data;
		Node* next;
	};
	int Count;
	Node* Head;
public:
	LinkedList();
    ~LinkedList();
	void insert_Left(int); 
	void insert_Right(int);
	void insert(int, int);
	bool find(int);
	int size(); 
	void print();
};


#endif