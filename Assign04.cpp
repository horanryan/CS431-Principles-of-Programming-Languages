/*
Ryan Horan
CS431-Principles of Programming Languages
November 2022

Due: November 18th, 2022

language: c++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0
compiler: g++ (Ubuntu 11.2.0-19ubuntu1) 11.2.0

Write a program in an object-oriented language (either C++ or FORTRAN95):

1. Queries the user for the name of a file of text.
2. Opens the file, and maintains two lists: one list for words beginning with the letter
"D" or "d", and a second list for words beginning with any other letter. Each list
must maintain words in alphabetical order.
3. Each node in the list must contain the word and the number of times that the word appears.
4. Display (a screen at a time) each of the lists showing the alphabetized list of words and the
number of times that each appears.

*/



#include<string>
#include<iostream>
#include<fstream>
using namespace std;
    // used https://www.geeksforgeeks.org/constructors-c/?ref=lbp as a reference for classes 
class Node{                 // a node of list which will store word, its count and address of next node

    public:
        int count;
        string element;        
        Node* next;
};
//used https://www.geeksforgeeks.org/constructors-c/?ref=lbp as a reference for classes
class List{
    //needs to be public for access later
    public: 

        List(){head = NULL;};   
        //check all nodes and checking is word is already in a node
        Node* felement(const string& str){       
            Node* cur = head;
            while(cur!=NULL){      
                if (cur->element==str)
                    return cur;
                cur = cur->next;
            }

            return NULL;

        }
        Node* head;
     // used https://www.tutorialspoint.com/cplusplus/cpp_class_member_functions.htm for making functions inside of class   
        void display(){  

            if (head==NULL){
                cout<<"empty list"<<endl;
                return;
            }
            cout<<" word : count"<<endl;
            Node* cur = head;
            while(cur!=NULL){
                cout<<cur->element<<" :\t"<<cur->count<<endl;
                cur = cur->next;
            }
        }
        //insert a node, if the str already exists increase its count 
        // reference https://www.geeksforgeeks.org/string-felement-in-cpp/ on how felement function call works
        void insert(const string& str){       
            Node* temp = felement(str);        
            if (temp!=NULL){              
                temp->count+=1;
                return;
            }
            else{ 
                Node* newNode = new Node(); 
                newNode->element = str;
                newNode->count = 1;
            // if the list is empty head is the new node
                if (head == NULL){              
                    newNode->next = NULL;
                    head = newNode;
                    return;
                }
                else{
                    //if list contains only one node,
                    if (head->next == NULL){            
                        // if first element is greater than str, means insert str at first position
                        if (head->element > str){          
                            newNode->next = head;
                            head = newNode;
                            return;

                        }
                        //insert at last position
                        else{                           
                            newNode->next = NULL;
                            head->next = newNode;
                            return;
                        }

                    }
                     //if nodes > 1 &&  if the head > str ,insert new node at first position
                    if (head->element > str){
                        newNode->next = head;
                        head = newNode;
                        return;
                    }


                    Node* cur = head;
                    // loop through nodes search for a node greater than str, insert the node before that node
                    while(cur->next!=NULL){           
                        if (cur->next->element>str){
                            newNode->next = cur->next;
                            cur->next = newNode;
                            return;
                        }
                        cur = cur->next;
                    }
                    // if such node is not found insert the new node in the last
                    newNode->next = NULL;              
                    cur->next = newNode;
                    return;
                }

            }

        }
        
};

int main(int argc, char ** argv){

    List* listD = new List();            // made two lists one with d and one without d
    List* listDNF = new List();            // DNF - D NOT FOUND

    ifstream file;                   
    file.open(argv[1]);            
    if (!file.is_open()){                 // if the file could not be opened just end the program with error

        cout<<"file couldn't be opened!"<<endl;
        return -1;
    }

    string word;
    while (file >> word)           
    {
        if (word[0]=='D' || word[0]=='d')    
            listD->insert(word);
        else
            listDNF->insert(word);
    }

    cout<<"\nstarting with d or D: \n"<<endl;       
    listD->display();
    cout<<"\nnot starting with d or D: \n"<<endl;
    listDNF->display();

    return 0;

}
