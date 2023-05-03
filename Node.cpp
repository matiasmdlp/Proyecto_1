#include "Node.h"

Node::Node(int val, Node* nodo1){
    Max = val;
    Next = nodo1;
    Count = 0;
    Data = new int[Max]; 
}

Node::~Node(){
    delete[] Data;
    delete Next, &Max, Count;
}

void Node::setCount(int x){
    Count = x;
}

int Node::getCount(){
    return Count;
}
void Node::setData(int* x){
    Data = x;
}

int* Node::getData(){
    return Data;
}

void Node::setNext(Node* x){
    Next = x;
}

Node* Node::getNext(){
    return Next;
}

int Node::insert(int num, int pos){
    if(Count<Max){
        for(int i=Count-1; i>=pos; i--){
            Data[i+1]=Data[i];
        }
        Data[pos]=num;
        Count++;
        return 0;
    }else{
        if(Next==nullptr || Next->Count==Max){
            if(pos<Count){
                Node* aux = new Node(Max, nullptr);
                aux->Next = Next;
                Next = aux;
                aux->insertLeft(Data[Max-1]);
                for(int i=Max-2; i>=pos; i--){
                    Data[i+1]=Data[i];
                }
                Data[pos]=num;
                return 1;
            }else{
                Node* aux = new Node(Max, nullptr);
                aux->Next = Next;
                Next = aux;
                aux->insertLeft(num);
                
                return 1;
            }
        }else if(Next->Count < Max){
            Next->insertLeft(Data[Max-1]);
            for(int i=Max-2; i>=pos; i--){
                Data[i+1]=Data[i];
            }
            Data[pos]=num;
            return 0;
        }
    }
}

int Node::insertLeft(int num){
    return insert(num, 0);
}

int Node::insertRight(int num){
    return insert(num, Count);
}

void Node::print(){
    for(int i=0; i<Count; i++){
        std::cout<<Data[i]<<" - ";
    }
    if(Next!=nullptr){
        std::cout<<std::endl;
        Next->print();
    }else{
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
}

bool Node::find(int num){
    bool x = false;
    for(int i=0; i<Count; i++){
        if(Data[i]==num){
            x=true;
        }
    }
    if(x==false && Next!=nullptr){
        x = Next->find(num);
    }
    return x; 
}