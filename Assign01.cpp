/*
Ryan Horan
CS431-Principles of Programming Languages
September 2022

Integer Division to show how global variables can rot

*/
#include <iostream>

using namespace std; 

//Global Variables
<<<<<<< HEAD
int N;
int D;
int R;
int Q;

void INTDIV(){
     Q = 0;
=======
int N,D,R,Q;

void INTDIV(){
    Q = 0;
>>>>>>> f4a1488ae9360f023b313db0c22c4743507ce6c9
    while(N >= D){
        N -= D;
        Q += 1;       
    }    
<<<<<<< HEAD
    R = N;  

}

int main(int argc, char **argv){
    //Get two integers from user
    cout << " Enter two positive integers to divide: ";
    cin >> N >> D;
    INTDIV();    
=======
    R = N;    
}

int main(int argc, char **argv){
    //Get two integers from user   
    cout << " Enter two positive integers to divide: ";
    cin >> N >> D;
    INTDIV();
    
>>>>>>> f4a1488ae9360f023b313db0c22c4743507ce6c9

    cout << "Numerator: " << N << '\n'
         << "Denominator: "<< D << '\n'
         << "Quotient: " << Q << '\n'
         << "Remainder: " << R << '\n';
    return 0;
}
