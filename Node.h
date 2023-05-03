#ifndef Node_h
#define Node_h
#include <iostream>
using namespace std;

class Node{
private:
    int* Data;
    int Max;
    int Count;
    Node* Next;
public:
    Node(int, Node*);
    ~Node();
    void setCount(int);
    int getCount();
    void setNext(Node*);
    Node* getNext();
    int insertLeft(int);
    int insertRight(int);
    int insert(int, int);
    void setData(int* Data);
    int* getData();
    void print();
    bool find(int);
};

#endif