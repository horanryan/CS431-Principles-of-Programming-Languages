/*
Ryan Horan
CS431-Principles of Programming Languages
September 2022
*/

#include <iostream>
#include <cstring>

using namespace std;

void concentric(char* charArray, int k){
    

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

    concentric(charArray, k);

    return 0;
}
