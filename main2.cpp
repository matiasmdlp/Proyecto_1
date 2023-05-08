#include <iostream>
#include "ListArr.h"
#include "Node.h"
#include "NodeRes.h"

using namespace std;

int main() {
    ListArr Arbol(3);

    Arbol.insert_left(7);
    Arbol.insert_left(4);
    Arbol.insert_left(8);

    cout<<"Max: "<<Arbol.getMax()<<endl;

    Arbol.print();
    Arbol.insert_left(12);
    Arbol.print();
    Arbol.insert_left(6);
    Arbol.insert_left(22);
    Arbol.print();

    Arbol.insert_right(55);
    Arbol.insert_right(23);
    Arbol.insert(19,4);
    Arbol.print();

    if(Arbol.find(3)){
        cout<<"el numero se encuentra en el arbol."<<endl;
    }else{
        cout<<"El numero no se encuentra en el arbol."<<endl;
    }

    cout<<"El numero de datos en el arbol es de: "<<Arbol.getCount()<<endl;

    return 0;
}

/*g++ main.cpp ListArr.cpp NodeRes.cpp  Node.cpp -o main.exe*/