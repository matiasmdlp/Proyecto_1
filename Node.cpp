#include "Node.h"

Node::Node(int val){
    Max = val;
    Next = nullptr;
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
    if(Count==0){
        Data[pos]=num;
        sumaCount();
        return 0;
    }else if(Count<Max){
        if(pos==Count){
            Data[pos]=num;
            sumaCount();
            return 0;
        }else if(pos < Count){
            for(int i = Count; i>pos; i--){
                Data[i]=Data[i-1];
            }
            Data[pos]=num;
            sumaCount();
            return 0;
        }
    }else if(Count==Max){
        if(Next!=nullptr){
            if(Next->getCount() < Next->getMax()){
                Next->insertLeft(Data[Max-1]);
                for(int i=Count-1; i>pos; i--){
                    Data[i]=Data[i-1];
                }
                Data[pos]=num;
                return 0;
            }else{
                Node* extra = new Node(Max);
                extra->setCount(0);
                extra->setMax(Max);
                extra->setNext(Next);
                Next->insertLeft(Data[Max-1]);
                for(int i=Count-1; i>pos; i--){
                    Data[i]=Data[i-1];
                }
                Data[pos]=num;
                /*print();*/
                return 1;
            }
            
        }else{
            Node* extra = new Node(Max);
            extra->setCount(0);
            extra->setMax(Max);
            Next->insertLeft(Data[Max-1]);
            for(int i=Count-1; i>pos; i--){
                Data[i]=Data[i-1];
            }
            Data[pos]=num;
            /*print();*/
            return 1;
        }
    }
    
}


int Node::insertLeft(int num){
    if(Count==0){
        Data[0]=num;
        Count++;
        return 0;
    }else if(Count<Max){
        for(int i=Count; i>0; i--){
            Data[i]=Data[i-1];
        }
        Data[0]=num;
        Count++;
        return 0;
    }else if(Next!=nullptr){
        if(Next->getCount() < Next->getMax()){
            Next->insertLeft(Data[Max-1]);
            for(int i=Count-1; i>0; i--){
                Data[i]=Data[i-1];
            }
            Data[0]=num;
            return 0;
        }else{
            Node* extra = new Node(Max);
            extra->setNext(Next);
            extra->setCount(0);
            extra->setMax(Max);
            Next = extra;
            Next->insertLeft(Data[Max-1]);
            for(int i=Count-1; i>0; i--){
                Data[i]=Data[i-1];
            }
            Data[0]=num;
            return 1;
        }
    }else{
        Node* extra = new Node(Max);
        extra->setCount(0);
        extra->setMax(Max);
        Next = extra;
        Next->insertLeft(Data[Max-1]);
        for(int i=Count-1; i>0; i--){
            Data[i]=Data[i-1];
        }
        Data[0]=num;
        return 1;
    }
}

int Node::insertRight(int num){
    if(Count<Max){
        Data[Count]=num;
        sumaCount();
        return 0;
    }else{
        Node* extra = new Node(Max);
        extra->setCount(0);
        extra->setMax(Max);
        Next = extra;
        Next->insertLeft(num);
        return 1;
    }
}

void Node::print(){
    Node* nodo = Next;
    for(int i=0; i<Count; i++){
        std::cout<<Data[i]<<" - ";
    }

    if(Next!=nullptr){
        std::cout<<std::endl;
        nodo->print();
    }else{
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
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

void Node::setMax(int x){
    Max=x;
}
int Node::getMax(){
    return Max;
}

void Node::sumaCount(){
    Count++;
}

