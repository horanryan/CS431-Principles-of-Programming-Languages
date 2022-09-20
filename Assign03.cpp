/*
Ryan Horan
CS431-Principles of Programming Languages
September 13 2022

Due: October 28th, 2022

language: c++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0
compiler: g++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0


Accept a sequence of k characters from the user and use the characters to produce a k concentric
squares. Assuming an index origin of 1, the outermost square is made up of the letter a[k], the
square inside that is made from the letter a[k-1], the square inside that is made from the letter
a[k-2], and so on, with the innermost square made from the letter a[1]

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
/*
    Main function of program, gets user input for a string to create a concentric square.
    After getting the user input call function concentric to print the concentric square.
*/
int main(int argc, char ** argv){
    // Get string form user to create concentric rectangle
    string userInput;
    cout << "Enter the characters you want: " <<'\n';
    cin >> userInput;
    
   
    // get the length of string for creating the size of character array
    int k = userInput.length();
    char charArray[k+1];
    // convert string into array of chars
    strcpy(charArray, userInput.c_str());
    //call concentric passing in the array and the length of the string
    concentric(charArray, k, k);

    return 0;
}
