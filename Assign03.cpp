/*
Ryan Horan
CS431-Principles of Programming Languages
September 2022
*/

#include <iostream>
#include <cstring>

using namespace std;

void concentric(char* charArray, int k, int index){
    //modified code from https://www.geeksforgeeks.org/print-concentric-rectangular-pattern-in-a-2d-matrix/
    int i;
    if( index < 1)
        return;
    for( i = k; i > index; i--)
        cout << charArray[i-1]<< ' ';
    for( i = 1; i < 2*index-1; i++)
        cout << charArray[index-1] << ' ';
    for( i = index; i <=k; i++)
        cout << charArray[i-1]<< ' ';
    cout <<'\n';
    //recursive call
    concentric(charArray,k,index-1);
    if( index < 1)
        return;
    for( i = k; i > index; i--)
        cout << charArray[i-1]<< ' ';
    for( i = 1; i < 2*index-1; i++)
        cout << charArray[index-1] << ' ';
    for( i = index; i <=k; i++)
        cout << charArray[i-1]<< ' ';
    cout <<'\n';
    return;

}
int main(int argc, char ** argv){
    // Get string form user to create concentric rectangle
    string userInput;
    cout << "Enter the characters you want: " <<'\n';
    cin >> userInput;
    
    // cout << userInput << '\n';
    // cout << userInput.length() << '\n';
    // get the length of string for creating the size of character array
    int k = userInput.length();
    char charArray[k+1];
    // convert string into array of chars
    strcpy(charArray, userInput.c_str());

    concentric(charArray, k, k);

    return 0;
}
