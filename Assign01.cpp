/*
Ryan Horan
CS431-Principles of Programming Languages

*/
#include <iostream>

using namespace std; 

void INTDIV(int N, int D, int Q, int R);


int main(int argc, char **argv){
    //Get two integers from user
    int N,D,R,Q;
    cout << " Enter two positive integers to divide: ";
    cin >> N >> D;
    INTDIV(N,D,Q, R);
    

    cout << N << '\n' << D << '\n' << Q << '\n' << R << endl;
    return 0;
}
void INTDIV(int N, int D, int Q, int R){
     Q = 0;
    while(N >= D){
        N -= D;
        Q += 1;       
    }
    
    R = N;
    return;
}