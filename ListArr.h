#ifndef ListArr_H
#define ListArr_H

#include "Node.h"
#include "NodeRes.h"
#include "ListArrADT.h"
#include <vector>
using namespace std;

class ListArr : public ListArrADT{
private:
	NodeRes* Arbol;
	Node* Head;
	int num_nodos;
	int exp;
	int num_hojas;
	int max;
		
public:
	ListArr(int);
	~ListArr();
    void insert_left(int);
    void insert_right(int);
    void insert(int,int);  
    void print();
    bool find(int); 
	bool isEmpty();
	int size();
	void Agregar();
	int sumar(int);
	pair<int, int> buscarpos(int i, int y);
};

#endif

