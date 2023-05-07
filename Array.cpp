#include"Array.h"
#include<iostream>

using namespace std;

#include"Array.h"
#include<iostream>

using namespace std;

Array::Array(int capacity) {
	data = new int[capacity];
	Max = capacity;
	Count = 0;
}

Array::~Array(){
    delete &Max, &Count;
    delete[] data;
}

void Array::insert_Left(int number) { 
	if (Count + 1 <= Max) {
		for (int i = 0; i < Max; i++) {
			data[Max - i] = data[Max - i - 1];
		}
		data[0] = number;
		Count++;
	}
	else {
		cout << "Esta Lleno"<<endl;
		return;
	}
}

void Array::insert_Right(int number) {
	if (Count + 1 <= Max) {
		data[Count] = number;
		Count++;
	}
	else {
		cout << "Esta Lleno"<<endl;
		return;
	}
}

void Array::insert(int number, int pos) { 
	if (Count + 1 <= Max && Count >= pos-1) {
		for (int i = 0; i <= Max - pos; i++) {
			data[Max - i] = data[Max - i - 1];
		}
		data[pos-1] = number;
		Count++;
	}
	else {
		cout << "Esta Lleno"<<endl;
		return;
	}
}

bool Array::find(int number) {
	for (int i = 0; i < Count; ++i) {
		if (data[i] == number) return true;
	}
	return false;
}

int Array::size(){
	return Count;
}

void Array::print() {
	cout << "Datos: " << Count << endl;
	for (int i = 0; i < Count; ++i) {
		cout << data[i] << endl;
	}
}
