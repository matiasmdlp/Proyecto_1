#ifndef ListArr_H
#define ListArr_H

#include "Node.h"
#include "NodeRes.h"
#include "ListArrADT.h"
#include <vector>
using namespace std;

class ListArr : public ListArrADT{
private:
	vector<NodeRes> Arbol;
	Node* Head;
	int num_nodos;
	int nivel;
	int num_hojas;
	int num_intnod;
	int num_nodRes;
	int max;
	int Max_Arbol;
	int Tail_Arbol;

	void calcMAx();
	void Build();
	void deletearbol();
	void deletenodes();
	void sumasuper(int i);
	int sumar(int);
	void setNodeMax(int, int);
	void asociar();
	pair<int, int> buscarpos(int i, int y);

		
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
	int getMax();
	int getCount();		
	Node* getArrList();
};


#endif

