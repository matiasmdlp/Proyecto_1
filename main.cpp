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
    
    int num;
    int n;
    int b;
    float Time; 
    clock_t time_Arr1;
    clock_t time_Arr2;
    clock_t time_Arr3;
    
       

    ////**** ListArr *****////
    b=64;
    n=10000;
    /// g++ main.cpp ListArr.cpp NodeRes.cpp  Node.cpp LinkedList.cpp Array.cpp -o main.exe  ///
    
        ListArr* ListArr_insert = new ListArr(b);
        
        for(int i=0; i<n; i++){
            num = rand(); 
            ListArr_insert->insert_right(num); 
            cout<<i<<endl;
        }

            
        time_Arr1 = clock();

        for(int j=0; j<20; j++){
            num = rand();
            ListArr_insert->insert_left(num);
        }
        cout<<"salio de insertLeft "<<endl;

        time_Arr1 = clock() - time_Arr1;
        Time=(float)(time_Arr1)/(float)20;
        cout<<"Promedio de tiempo [ms] para insert_Left() x 20: "<<Time<<" // "<<"n: "<<n<<endl;
        /*ListArrLeft.push_back(Time);*/
       


        time_Arr2 = clock();

        for(int j=0; j<20; j++){
            num = rand();
            ListArr_insert->insert_right(num);
        }
        cout<<"salio de insertright"<<endl;

        time_Arr2 = clock() - time_Arr2;
        Time=(float)(time_Arr2)/(float)20;
        cout<<"Promedio de tiempo [ms] para insert_Right() x 20: "<<Time<<" // "<<"n: "<<n<<endl;
        /*ListArrRight.push_back(Time);*/

            
        time_Arr3 = clock();

        for(int j=0; j<20; j++){
            num = rand();
            ListArr_insert->find(num);
        }
        cout<<"salio de Find"<<endl;

        time_Arr3 = clock() - time_Arr3;
        Time=(float)(time_Arr3)/(float)20;
        cout<<"Promedio de tiempo [ms] para Find() x 20: "<<Time<<" // "<<"n: "<<n<<endl;
        /*ListArrFind.push_back(Time);*/


        ListArr_insert->~ListArr();




    ////**** Arr *****////
     
    /*    
    n=10000;
        Array* Arr_insert = new Array(n+40);
        
        for(int i=0; i<n; i++){
            num = rand(); 
            Arr_insert->insert_Right(num);
        }
        

        time_Arr1 = clock();
        cout<<endl;

        for(int j=0; j<20; j++){
            num = rand();
            Arr_insert->insert_Left(num);
        }

        time_Arr1 = clock() - time_Arr1;
        Time=(float)(time_Arr1/CLOCKS_PER_SEC)/20;
        cout<<"Promedio de tiempo [ms] para insert_left x 20: "<<(float)(time_Arr1)/(float)20<<endl;
            
        time_Arr2 = clock();
        cout<<endl;

        for(int j=0; j<20; j++){
            num = rand();
            Arr_insert->insert_Right(num);
        }

        time_Arr2 = clock() - time_Arr2;
        Time=(float)(time_Arr2/CLOCKS_PER_SEC)/20;
        cout<<"Promedio de tiempo [ms] para inser_Right x 20: "<<(float)(time_Arr2)/(float)20<<endl;

            
        time_Arr3 = clock();
        cout<<endl;

        for(int j=0; j<20; j++){
            num = rand();
            Arr_insert->find(num);
        }

        time_Arr3 = clock() - time_Arr3;
        Time=(float)(time_Arr3/CLOCKS_PER_SEC)/20;
        cout<<"Promedio de tiempo [ms] para Find() x 20: "<<(float)(time_Arr3)/(float)20<<endl;


        Arr_insert->~Array();
        cout<<"elimina Arr  "<<endl;
    */
        

    ////**** List *****////

    /*
    n=10000;
    for(int k=0; k<5; k++){
        LinkedList* List = new LinkedList(); 
        for(int i=0; i<n; i++){
            num = rand(); 
            List->insert_Left(num);
        }


        time_Arr1 = clock();

        for(int j=0; j<20; j++){
            num = rand();
            List->insert_Left(num);
        }

        time_Arr1 = clock() - time_Arr1;
        Time=(float)(time_Arr1)/(float)20;
        cout<<"Promedio de tiempo [ms] para inser_Left x 20: "<<Time<<" "<<"n: "<<n<<endl;
       
        
    
        time_Arr2 = clock();

        for(int j=0; j<20; j++){
            num = rand();
            List->insert_Right(num);
        }

        time_Arr2 = clock() - time_Arr2;
        Time=(float)(time_Arr2)/(float)20;
        cout<<"Promedio de tiempo [ms] para inser_Right x 20: "<<Time<<" "<<"n: "<<n<<endl;

        
    
        time_Arr3 = clock();

        for(int j=0; j<20; j++){
            num = rand();
            List->find(num);
        }

        time_Arr3 = clock() - time_Arr3;
        Time=(float)(time_Arr3)/(float)20;
        cout<<"Promedio de tiempo [ms] para Find() x 20: "<<Time<<" "<<"n: "<<n<<endl;


        List->~LinkedList();
        n = n*10;
        cout<<endl;
    }
    */
 
    
    
        
    
    
    return 0;
}

/*g++ main.cpp ListArr.cpp NodeRes.cpp  Node.cpp LinkedList.cpp Array.cpp -o main.exe*/


