#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <cmath>
#include "ListArr.h"
#include "Node.h"
#include "NodeRes.h"
#include "Array.h"
#include "LinkedList.h"


using namespace std;

int main() {
    srand(time(NULL));
    vector<float> ArrLeft(5);
    vector<float> ArrRight(5);
    vector<float> ArrFind(5);

    vector<float> ListLeft(5);
    vector<float> ListRight(5);
    vector<float> ListFind(5);

    vector<float> ListArrLeft(5);
    vector<float> ListArrRight(5);
    vector<float> ListArrFind(5);
    
    int num;
    int n;
    int b;
    float Time; 
    clock_t time_Arr;

    ////**** Arr *****////

    for(int n=10000; n<=10000000; n*10){
        Array* Arr_insert = new Array(n+40); 
        for(int i=0; i<n; i++){
            num = rand(); 
            Arr_insert->insert_Left(num);
        }

        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            Arr_insert->insert_Left(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ArrLeft.push_back(Time);
       
            
        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            Arr_insert->insert_Right(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ArrRight.push_back(Time);

            
        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            Arr_insert->find(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ArrFind.push_back(Time);


        Arr_insert->~Array();
    }

    ////**** List *****////

    /*
    for(int n=10000; n<=10000000; n*10){
        LinkedList* List = new LinkedList(); 
        for(int i=0; i<n; i++){
            num = rand(); 
            List->insert_Left(num);
        }


        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            List->insert_Left(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ListLeft.push_back(Time);
       
        
    
        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            List->insert_Right(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ListRight.push_back(Time);

        
    
        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            List->find(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ListFind.push_back(Time);


        List->~LinkedList();
    }
    */

    ////**** ListArr *****////
    /*
    b=1;
    for(int n=10000; n<=10000000; n*10){
        ListArr* ListArr_insert = new ListArr(b);
        
        for(int i=0; i<n; i++){
            num = rand(); 
            ListArr_insert->insert_right(num);
        }

            
        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            ListArr_insert->insert_left(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ListArrLeft.push_back(Time);
       


        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            ListArr_insert->insert_right(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ListArrRight.push_back(Time);

        
    
        time_Arr = clock();

        for(int j=0; j<20; j++){
            num = rand();
            ListArr_insert->find(num);
        }

        time_Arr = clock() - time_Arr;
        Time=(float)(time_Arr/CLOCKS_PER_SEC)/20;
        ListArrFind.push_back(Time);


        ListArr_insert->~ListArr();
    }
    */

    n=10000;
    for(int i=0; i<5; i++){
        cout<<"n: "<<n<<" "<<"Arr_Left: "<<ArrLeft[i]<<endl;
        cout<<"n: "<<n<<" "<<"Arr_Right: "<<ArrRight[i]<<endl;
        cout<<"n: "<<n<<" "<<"Arr_Find: "<<ArrFind[i]<<endl;
        /*
        cout<<"n: "<<n<<" "<<"List_Left: "<<ListLeft[i]<<endl;
        cout<<"n: "<<n<<" "<<"List_Right: "<<ListRight[i]<<endl;
        cout<<"n: "<<n<<" "<<"List_Find: "<<ListFind[i]<<endl;

        cout<<"n: "<<n<<" "<<"ListArr_Left: "<<ListArrLeft[i]<<endl;
        cout<<"n: "<<n<<" "<<"ListArr_Right: "<<ListArrRight[i]<<endl;
        cout<<"n: "<<n<<" "<<"ListArr_Find: "<<ListArrFind[i]<<endl;
        */
        n = n*10;
    }
    return 0;
}

/*g++ main.cpp ListArr.cpp NodeRes.cpp  Node.cpp LinkedList.cpp Array.cpp -o main.exe*/


