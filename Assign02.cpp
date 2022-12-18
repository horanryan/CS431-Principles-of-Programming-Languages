/*
Ryan Horan
CS431-Principles of Programming Languages
September 13 2022

Due: October 7th, 2022

language: c++ 17
compiler: g++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0

Operationalize a sort function based on flow chart


*/
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void sort();
void move();
int Findkay(int);
int a[5];
int n = sizeof(a)/sizeof(a[0]);

int main(void){
    srand(time(NULL));    
    for (int i= 0;i < n; i++){
        a[i] = rand() % n;
    }
    sort();
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    

    return 0;
}

int j = 0;

void sort(){   
    for(int j= 0; j<=n-1; j++){
        if(a[j]>a[j+1]){
            move();
        }
    }
    return;
}
int k = 0;
void move(){
   int temp = a[j+1];
   a[j+1]= a[j];
   Findkay(temp);
   a[k]= temp;

    return;
}
int Findkay(int temp){
    k = j;
    int sw = 0;
    while( (k>0) && (sw == 0)){
        if(a[k-1]>temp){
            a[k]=a[k-1];
            k= k-1;
        }
        else
            sw = 1;
    }
    return 0;
}
