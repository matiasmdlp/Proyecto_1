#ifndef NodeRes_h
#define NodeRes_h

#include <iostream>
#include "Node.h"
using namespace std;

class NodeRes{
private:
    int Max;
    int Count;
    NodeRes* Padre;
    NodeRes* Right;
    NodeRes* Left;
    Node* Arr;
public:
    NodeRes(int);
    ~NodeRes();
    void setCount(int);
    int getCount();
    int getMax();
    void suma_sup();
    void setPadre(NodeRes*);
    NodeRes* getPadre();
    void setRight(NodeRes*);
    NodeRes* getRight();
    void setLeft(NodeRes*);
    NodeRes* getLeft();
    void setArr(Node*);
    Node* getArr();
    void insertLeft(int);
    void insertRight(int);
    void insert(int, int);
    void print();
};

#endif