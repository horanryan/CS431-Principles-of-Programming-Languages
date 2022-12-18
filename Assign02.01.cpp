#include <iostream>
#include <stdlib.h>
#include <ctime> 

using namespace std;

//Function declarations
void sort(); 
void move(); 
int Findkay(int);

//Global variables
int a[10];
int n = sizeof(a)/sizeof(a[0]);

int main(void){
    srand(time(NULL));
    cout <<  " arr before the sort: ";
    for(int i = 0; i < n; i++){ 
        a[i] = rand() % n;
        cout << a[i] << " "; 
    }

    cout << '\n';
    sort(); 

    cout << " arr after the sort: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}

/*
Written by Kevin Zheng

Written C++ Codeblocks GNU GCC Compiler

Made on 9/13/22

Variables:

Purpose: To check if an  arr value is greater than the other

Resources:
*/

//Global Variables
int j = 0;
void sort(){
    for(j = 0; j < n-1; j++){
        if(a[j] > a[j+1]){
            move();
        }
    }
}

/*
Written by Kevin Zheng

Written C++ Codeblocks GNU GCC Compiler

Made on 9/13/22

Variables: temp

Purpose: To switch  arr values around 

Resources:
*/

//Global Variables
int k = 0; 
void move(){
    int temp = a[j+1];
    a[j+1] = a[j];
    Findkay(temp); 
    a[k] = temp; 
}

/*
Written by Kevin Zheng

Written C++ Codeblocks GNU GCC Compiler

Made on 9/13/22

Variables: sw

Purpose: To check temp with every value before the present point in the  arr. 

Resources:
*/

//Global variables
int Findkay(int temp){
    int sw = 0; 
    k = j; 
    while(k > 0 && sw == 0){
        if(a[k-1] > temp){
            a[k] = a[k-1];
            k = k - 1; 
        }
        else
        {
        sw = 1;
        } 
    }

    return 0; 
}

