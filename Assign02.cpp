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

using namespace std;

void sort(int n, int a[]){
   
    for(int j=1; j<=n-1; j++){
        if(a[j]>a[j+1]){
            move(a,j);
        }
    }
    return;
}
void move(int a[],int j){
   int temp = a[j+1];
   a[j+1]= a[j];
   int k;
   Findkay(k,j,a,temp);
   a[k]= temp;

    return;
}
void Findkay(int k, int j, int a[],int temp){
    k = j;
    int sw = 0;
    while( (k>1) && (sw = 0)){
        if(a[k-1]>temp){
            a[k]=a[k-1];
            k= k-1;
        }
        else
            sw = 1;

    }
    return;
}
int main( int argc, char **argv){
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;
    int a[n];//int array size of n;
    
    return 0;
}

