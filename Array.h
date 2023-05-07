#ifndef Array_h
#define Array_h

#include<iostream>
using namespace std;

class Array {
private:
	int Max;
	int Count;
	int* data;

public:
	Array(int);
    ~Array();
	void insert_Left(int);
	void insert_Right(int);
	void insert(int, int);
	bool find(int);
	int size();
	void print();
};


#endif