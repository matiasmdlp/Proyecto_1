#include "NodeRes.h"

NodeRes::NodeRes(int val){
    Max = val;
    Count = 0;
    Arr = nullptr;
}

NodeRes::~NodeRes(){
    delete &Count, &Max;
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

void NodeRes::setArr(Node* node){
    Arr = node;
    Count = node->getCount();
}

Node* NodeRes::getArr(){
    return Arr;
}

int NodeRes::insertLeft(int num){
    return Arr->insertLeft(num);
}

int NodeRes::insertRight(int num){
    return Arr->insertRight(num);
}

int NodeRes::insert(int num, int pos){
    return Arr->insert(num, pos);
}

void NodeRes::print(){
    Arr->print();
}



