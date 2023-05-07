#include"LinkedList.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList() {
	Count = 0;
	Head = nullptr;
}

LinkedList::~LinkedList(){
	while (Head->next != nullptr) {
		Node* aux = Head;
        Head = aux->next;
        delete aux;
	}
    delete Head;
}

void LinkedList::insert_Left(int number) {
	Node* newNode = new Node(number);
	Node* aux = Head;
	Head = newNode;
	newNode->next = aux;
	Count++;
}

void LinkedList::insert_Right(int number) {
	Node* newNode = new Node(number);
	if (Head != nullptr) {
		Node* current = Head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	else {
		Head = newNode;
	}
	Count++;
}

void LinkedList::insert(int number, int pos) { 
	Node* newNode = new Node(number);
	if (pos <= Count + 1 && pos>=1) {
		if (pos == 1) {
			Node* aux = Head;
			Head = newNode;
			newNode->next = aux;
		}
		else {
			Node* current = Head;
			Node* aux;
			for (int i = 1; i < pos-1; ++i) {
				current = current->next;
			}
			aux = current->next;
			current->next = newNode;
			newNode->next = aux;
			
		}
		Count++;
	}
	else {
		cout << "No existe esta posicion:"<<endl;
		return;
	}
}

bool LinkedList::find(int number) {
	Node* current = Head;
	if (current == nullptr) return false;
	while (current->next != nullptr) {
		if (current->data == number) return true;
		else current = current->next;
	}
	if (current->data == number) return true;
	return false;
}

int LinkedList::size() {
	return Count;
}

void LinkedList::print() {
	cout << "Datos: "<< endl;
	Node* current = Head;
	if (current == nullptr) return;
	if (current->next == nullptr) {
		cout << current->data << endl;
		return;
	}
	while (current->next != nullptr) {
		cout << current->data << endl;
		current = current->next;
	}
	cout << current->data << endl;
}