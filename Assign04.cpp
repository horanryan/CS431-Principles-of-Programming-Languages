#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class Node{                 // a node of list which will store word, its count and address of next node

    public:
        int count;
        string ind;        
        Node* next;
};

class List{

    public:

        List(){head = NULL;};     // assign null to head in the constructor
        ~List();

        Node* find(const string& str){       // a function find which will find if there is a node containing word str and return that node if not return NULL
            Node* current = head;
            while(current!=NULL){           // iterate through all the nodes and compare the words
                if (current->ind==str)
                    return current;
                current = current->next;
            }

            return NULL;

        }

        void insert(const string& str){       // an insert function which will insert a node, if the str already exists it increases its count else add a new node
            Node* temp = find(str);          // search for the node containing str by calling find function

            if (temp!=NULL){               // if the temp is not null just increase its counter and return
                temp->count+=1;
                return;
            }
            else{                           // else if it is a new node, we have to insert in such a way so that the list remains sorted

                Node* newNode = new Node();   // made a new node and initialized its ind and counter value
                newNode->ind = str;
                newNode->count = 1;

                if (head == NULL){              // if the list is empty just assign the head with new node and return
                    newNode->next = NULL;
                    head = newNode;
                    return;
                }
                else{

                    if (head->next == NULL){            // else if the list contains only one node,

                        if (head->ind > str){          // if first indent is greater than str, means insert str at first position
                            newNode->next = head;
                            head = newNode;
                            return;

                        }
                        else{                           // else insert at last(second) position
                            newNode->next = NULL;
                            head->next = newNode;
                            return;
                        }

                    }

                    if (head->ind > str){            //if more than one nodes and  if the head value is greater than str that means we have to insert new node at first position
                        newNode->next = head;
                        head = newNode;
                        return;
                    }


                    Node* current = head;

                    while(current->next!=NULL){            // iterate through all the nodes and search for a node that contains the value greater than str, insert the node before that node
                        if (current->next->ind>str){
                            newNode->next = current->next;
                            current->next = newNode;
                            return;
                        }
                        current = current->next;
                    }
                    newNode->next = NULL;              // if such node is not found insert the new node in the last
                    current->next = newNode;
                    return;
                }

            }

        }
        void display(){                 // a display function which displays the list

            if (head==NULL){
                cout<<"List is empty!"<<endl;
                return;
            }
            cout<<" Words : \tCount"<<endl;
            Node* current = head;
            while(current!=NULL){
                cout<<current->ind<<" :\t"<<current->count<<endl;
                current = current->next;
            }
        }
    private:
        Node* head;
};

int main(int argc, char ** argv){

    List* listD = new List();            // made two lists one with d and one without d
    List* listDNF = new List();            // DNF - D NOT FOUND

    ifstream file;                   
    file.open("dtext.txt");            // insert your file name here
    if (!file.is_open()){                 // if the file could not be opened just end the program with error

        cout<<"file couldn't be opened!"<<endl;
        return -1;
    }

    string word;
    while (file >> word)            // else traverse through all the word
    {
        if (word[0]=='D' || word[0]=='d')    
            listD->insert(word);
        else
            listDNF->insert(word);
    }

    cout<<"\nWords starting with D or d: \n"<<endl;       
    listD->display();
    cout<<"\nWords starting with other character: \n"<<endl;
    listDNF->display();

    return 0;

}
