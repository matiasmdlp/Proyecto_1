#include <iostream>
#include <vector>
#include "Node.h"
#include "NodeRes.h"
using namespace std;

int sumar(int pos, int max, NodeRes* Arbol){        // desde la raiz pedimos la cantidad de datos contenida en sus hijos y las sumamos 
    if(Arbol[pos].getCount()!=0 || Arbol[pos].getMax()==max){
        return Arbol[pos].getCount();
        
    }else{
        Arbol[pos].setCount(sumar(2*pos+2, max, Arbol) + sumar(2*pos+1, max, Arbol));
        return Arbol[pos].getCount();   
    }
}

pair<int, int> buscarpos(int i, int y, NodeRes* Arbol){
    if(Arbol[i].getMax()==3){
        return std::make_pair(i,y);
    }

    if( y < Arbol[(2*i)+1].getCount()){
        return buscarpos((2*i)+1, y, Arbol);
    }else if((y-Arbol[(2*i)+1].getCount()) < Arbol[(2*i)+2].getCount()){
        return buscarpos((2*i)+2,(y-Arbol[(2*i)+1].getCount()), Arbol );
    }else{
        cout<< "El indice indicado no existe... " << endl;
    }
}

void sumasuper(int i, NodeRes* Arbol){  //sumar 1 desde la hoja hasta la raiz, una vez se agregue un nuevo dato.
    int y=i;
    Arbol[y].suma_sup();

    while(y>0){
        Arbol[(y-1)/2].suma_sup();
        y = (y-1)/2;
    }
}

int main() {
    int num=3;
    NodeRes* Arbol;
    Arbol[7];

    NodeRes x(num*4);
    Arbol[0] = x;

    NodeRes x1(num*2);
    x1.setPadre(&x);
    Arbol[1] = x1;

    NodeRes x2(num*2);
    x2.setPadre(&x);
    Arbol[2] = x2;

    NodeRes x3(num);
    x3.setPadre(&x1);
    x3.setCount(3);
    Arbol[3] = x3;

    NodeRes x4(num);
    x4.setPadre(&x1);
    x4.setCount(3);
    Arbol[4] = x4;

    NodeRes x5(num);
    x5.setPadre(&x2);
    x5.setCount(3);
    Arbol[5] = x5;

    NodeRes x6(num);
    x6.setPadre(&x2);
    x6.setCount(0);
    Arbol[6] = x6;

    int sum = sumar(0, num, Arbol);
    
    cout<<Arbol[0].getCount()<<endl;
    
    sumasuper(6, Arbol);

    cout<<Arbol[0].getCount()<<endl;


    pair<int, int> busca= buscarpos(0, 7,Arbol);
    int indice = busca.first;
    int pos = busca.second;

    cout<<"indice: "<<indice<<" "<<"pos: "<<pos<<endl;

    /*Node* hola = new Node(3,nullptr);
    num += hola->insertLeft(8);
    num += hola->insertRight(10);
    num += hola->insertRight(7);    
    num += hola->insert(5,1);
    cout << num << endl;
    hola->print();*/
    return 0;
}

/*g++ main.cpp Node.cpp  -o main.exe*/