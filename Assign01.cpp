/*
Ryan Horan
CS431-Principles of Programming Languages

*/
#include <iostream>

using namespace std; 

int INTDIV(int numer, int denom, int quot, int remndr);


int main(int argc, char **argv){
    //Get two integers from user
    int N,D,R,Q;
    cout << " Enter two positive integers to divide: ";
    cin >> N >> D;
    INTDIV(N,D,Q,R);
    
    return 0;
}
int INTDIV(int numer, int denom, int quot, int remndr){
    quot = 0;
    while(numer >= denom){
        numer =numer-denom;
        quot = quot+1;
    }
    remndr = numer;
    return numer, denom, quot, remndr;

}