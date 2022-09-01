/*
Ryan Horan
CS431-Principles of Programming Languages

*/
#include <iostream>

using namespace std; 

int main(int argc, char **argv){
    //Get two integers from user
    int N,D,R,Q;
    cout << " Enter two positive integers to divide: ";
    cin >> N >> D;
    Q = 0;
    while(N >= D){
        N -= D;
        Q += 1;       
    }    
    R = N;
    

    cout << "Numerator: " << N << '\n'; 
    cout << "Denominator: "<< D << '\n';
    cout <<  "Quotient: " << Q << '\n';
    cout << "Remainder: " << R << '\n';
    return 0;
}