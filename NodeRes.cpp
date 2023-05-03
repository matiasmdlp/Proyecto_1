#include "NodeRes.h"

NodeRes::NodeRes(int val){
    Max = val;
    Count = 0;
    Padre = nullptr;
    Right = nullptr;
    Left = nullptr;
    Arr = nullptr;
}

NodeRes::~NodeRes(){
    if(Arr!=nullptr){
        Arr->~Node();
    }
    if(Right!=nullptr){
        Right->~NodeRes();       
    }
    if(Left!=nullptr){
        Left->~NodeRes();       
    }
    delete Padre, Right, Left, Arr, &Count, &Max;
}   

void NodeRes:: setCount(int x){
    Count = x;
} 

int NodeRes::getCount(){
    return Count;
}

void NodeRes:: setMax(int x){
    Max = x;
}

int NodeRes::getMax(){
    return Max;
}

void NodeRes::suma_sup(){
    Count++;
}

void NodeRes::setPadre(NodeRes* node){
    Padre = node;
}

NodeRes* NodeRes::getPadre(){
    return Padre;
}

void NodeRes::setRight(NodeRes* node){
    Right = node;
}

NodeRes* NodeRes::getRight(){
    return Right;
}

void NodeRes::setLeft(NodeRes* node){
    Left = node;
}

NodeRes* NodeRes::getLeft(){
    return Left;
}

void NodeRes::setArr(Node* node){
    Arr = node;
}

Node* NodeRes::getArr(){
    return Arr;
}

void NodeRes::insertLeft(int num){
    Arr->insertLeft(num);
}

void NodeRes::insertRight(int num){
    Arr->insertRight(num);
}

void NodeRes::insert(int num, int pos){
    Arr->insert(num, pos);
}

void NodeRes::print(){
    Arr->print();
}

