#ifndef NodeRes_h
#define NodeRes_h

#include <iostream>
#include "Node.h"
using namespace std;

class NodeRes{
private:
    int Max;
    int Count;
    Node* Arr;
public:
    NodeRes(int);
    ~NodeRes();
    void setCount(int);
    int getCount();
    void setMax(int);
    int getMax();
    void suma_sup();
    void setArr(Node*);
    Node* getArr();
    int insertLeft(int);
    int insertRight(int);
    int insert(int, int);
    void print();
};


#endif