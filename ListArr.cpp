#include "ListArr.h"
#include <math.h>

ListArr::ListArr(int x){   
    max = x;
    nivel = 0;
    Arbol[max];
    Head = new Node(max);
    Head->setCount(0);
    Tail_Arbol=0;
    num_nodos=1;
    num_hojas=1;
    Build();
} 

ListArr::~ListArr(){
    deletearbol();
    /*deletenodes();*/
    delete &Arbol; 
    delete Head, &nivel, &num_nodos,&num_hojas, &num_nodRes,&max, &Max_Arbol;
}

void ListArr::insert_left(int x){ //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
    pair<int, int> buscar = buscarpos(0, 0);
    int indice = buscar.first;
    int posicion = buscar.second;
    int val = num_nodos;
    int val2 = Arbol[indice].getArr()->getCount();

    num_nodos += Arbol[indice].insertLeft(x);

    if(num_nodos>val){
        Build();

    }else{
        if(val2<max){
            sumasuper(indice);
        }else{
            sumasuper(indice+1);
        }
    } 

}

void ListArr::insert_right(int x){ // Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
    pair<int, int> buscar = buscarpos(0, Arbol.at(0).getCount());
    int indice = buscar.first;
    int val = num_nodos;
    int val2 = Arbol[indice].getArr()->getCount();

    num_nodos += Arbol[indice].insertRight(x);

    if(num_nodos>val){
        Build();
    }else{
        sumasuper(indice);
    } 
}

void ListArr::insert(int x, int y){ //Inserta un nuevo valor x en el índice y del ListArr.
    pair<int, int> buscar = buscarpos(0, y);
    int indice = buscar.first;
    int posicion = buscar.second;
    int val = num_nodos;

    num_nodos += Arbol[indice].insert(x, posicion);

    if(num_nodos>val){
        Build();
    }else{
        if(Arbol[indice].getArr()->getCount()<=max){
            sumasuper(indice);
        }else if(Arbol[indice+1].getArr()->getCount()<=max){
            sumasuper(indice+1);
        }
    }    
}

void ListArr::print(){ //Imprime por pantalla todos los valores almacenados en el ListArr.
    Arbol[num_intnod].print();
}

bool ListArr:: find(int x){ //Busca en el ListArr si el valor v se encuentra almacenado.
    Head->find(x);
}

int ListArr::size(){ //Retorna la cantidad de elementos almacenados en el ListArr
    return Arbol[0].getCount();
}

bool ListArr::isEmpty(){ 
    if(Arbol[0].getCount()==0){
        return true;
    }else{
        return false;
    }
}

void ListArr::Build(){ // si existe un Arbol, lo elimina y crea otro, en cas de no existir, solo crea uno
    calcMAx();
    Arbol.clear();

    for(int i=0; i<num_intnod; i++){
        Arbol.push_back(NodeRes(0));
    }
    
    for(int i=num_intnod; i<(num_intnod + num_nodos); i++){
        Arbol.push_back(NodeRes(0));
    }

    Tail_Arbol = num_intnod + num_nodos-1;
    setNodeMax(0, Max_Arbol);
        
    asociar();
    
}

void ListArr::calcMAx(){
    if(num_nodos>num_hojas){
        nivel++;
    }
    
    Max_Arbol = pow(2, nivel)*max;
    num_hojas = pow(2, nivel);
    num_nodRes = 2*num_hojas-1;
    num_intnod = num_nodRes - num_hojas;
    Tail_Arbol = num_intnod + num_nodos;
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

    if( y <= Arbol[(2*i)+1].getCount()){
        return buscarpos((2*i)+1,y);
    }else if((y-Arbol[(2*i)+1].getCount()) <= Arbol[(2*i)+2].getCount()){
        return buscarpos((2*i)+2,(y-Arbol[(2*i)+1].getCount()));
    }else{
        cout<< "El indice indicado no existe... " << endl;
    }
}

void ListArr::deletearbol(){
    for(int i=0; i<num_nodRes; i++){
        Arbol[i].~NodeRes();
    }
}

void ListArr::deletenodes(){
    for(int i=0; i<num_nodos; i++){
        Node* aux=Head;
        Head = Head->getNext();
        delete aux;
        if(Head->getNext()==nullptr){
            delete Head;
        }
    }
    Node* Head=nullptr;
}

void ListArr::sumasuper(int i){  //sumar 1 desde la hoja hasta la raiz, una vez se agregue un nuevo dato.
    int y=i;
    Arbol[y].suma_sup();

    while(y>0){
        Arbol[(y-1)/2].suma_sup();
        y = (y-1)/2;
    }
}

void ListArr::setNodeMax(int pos, int max_val){
    int val=max_val;
    Arbol[pos].setMax(val);
    Arbol[pos].setCount(0);

    if(val>max){
        setNodeMax(2*pos+1, (val/2));
        setNodeMax(2*pos+2, (val/2));
    }
}

void ListArr::asociar(){
    Node* aux = Head;
    for(int i=num_intnod; i<(num_intnod + num_nodos); i++){
        this->Arbol[i].setArr(aux);
        this->Arbol[i].setCount(this->Arbol[i].getArr()->getCount());
        this->Arbol[i].getArr()->setMax(max);

        if(aux->getNext()!=nullptr){
            aux = aux->getNext();
        }
        
    }

    sumar(0);

}

int ListArr::getMax(){
    return Max_Arbol;
}

Node* ListArr::getArrList(){
    return Head;
}

int ListArr::getCount(){
    return Arbol[0].getCount();
}