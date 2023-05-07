#ifndef ListArrADT_H
#define ListArrADT_H

#include <iostream>

class ListArrADT{
public:
    virtual int size()=0;
    virtual void insert_left(int v)=0;
    virtual void insert_right(int)=0;
    virtual void insert(int,int)=0;  
    virtual void print()=0;
    virtual bool find(int v)=0;  
    virtual bool isEmpty()=0;
};


#endif