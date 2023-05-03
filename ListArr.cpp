#include "ListArr.h"
#include <math.h>

ListArr::ListArr(int x){   
    max = x;
    Arbol[max];
    Head= new Node(max,nullptr);
    num_nodos=1;
} 

ListArr::~ListArr(){
    
}

void ListArr::insert_left(int x){ //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
    
}

void ListArr::insert_right(int x){ // Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
    
}

void ListArr::insert(int x, int y){ //Inserta un nuevo valor x en el índice y del ListArr.
    
}

void ListArr::print(){ //Imprime por pantalla todos los valores almacenados en el ListArr.
    
}

bool ListArr:: find(int x){ //Busca en el ListArr si el valor v se encuentra almacenado.

}

int ListArr::size(){ //Retorna la cantidad de elementos almacenados en el ListArr
    
}

bool ListArr::isEmpty(){ 
    
}

int ListArr::sumar(int pos){        // desde la raiz pedimos la cantidad de datos contenida en sus hijos y las sumamos 
    if(Arbol[pos].getCount()!=0 || Arbol[pos].getMax()==max){
        return Arbol[pos].getCount();
        
    }else{
        Arbol[pos].setCount(sumar(2*pos+1) + sumar(2*pos+2));
        return Arbol[pos].getCount();   
    }
}

pair<int, int> ListArr::buscarpos(int i, int y){ // indice i(inicio de la busqueda, normalmente 0), posicion a encontrar "y", las posiciones se cuentan desde el 0; 
    if(Arbol[i].getMax()==max){
        return std::make_pair(i,y);
    }

    if( y < Arbol[(2*i)+1].getCount()){
        return buscarpos((2*i)+1,y);
    }else if((y-Arbol[(2*i)+1].getCount()) < Arbol[(2*i)+2].getCount()){
        return buscarpos((2*i)+2,(y-Arbol[(2*i)+1].getCount()));
    }else{
        cout<< "El indice indicado no existe... " << endl;
    }
}

/////****/////****/////****/////****/////
/*
void ListArr::Build(){ // si existe un Arbol, lo elimina y crea otro, en cas de no existir, solo crea uno
      
}

void ListArr::crear(int pos){   //esta funcion asigna de forma recursiva el numero maximo que puede almacenar cada nodo
    
}

void ListArr::asociar(){    //asocia cada hoja con un nodo del ListArr
    
}

void ListArr::limpiar(int pos){  //en caso de insertar un nodo ListArr en medio, es necesario realizar la suma nuevamente, para esto limtiamos la cantidad de datos en cada nodo.
    
}

int ListArr::sumar(int pos){        // desde la raiz pedimos la cantidad de datos contenida en sus hijos y las sumamos 
    if(Arbol[pos].numdata!=0 || Arbol[pos].maxdata==b){
        return Arbol[pos].numdata;
        
    }else{
        Arbol[pos].numdata = sumar(2*pos+1) + sumar(2*pos+2);
        return Arbol[pos].numdata;   
    }
}

void ListArr::sumasuper(int i){  //sumar 1 desde la hoja hasta la raiz, una vez se agregue un nuevo dato.
    int y=i;
    Arbol[y].numdata++;

    while(y>0){
        Arbol[(y-1)/2].numdata++;
        y = (y-1)/2;
    }
}

pair<int, int> ListArr::buscarpos(int i, int y){
    if(Arbol[i].maxdata==b){
        return std::make_pair(i,y);
    }

    if( y < Arbol[(2*i)+1].numdata){
        return buscarpos((2*i)+1,y);
    }else if((y-Arbol[(2*i)+1].numdata) < Arbol[(2*i)+2].numdata){
        return buscarpos((2*i)+2,(y-Arbol[(2*i)+1].numdata));
    }else{
        cout<< "El indice indicado no existe... " << endl;
    }
}
*/