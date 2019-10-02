#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct node{
    string name = "";
    string number;
    node* next = NULL;
};

void readFile(struct node *head, char *filename){
    ifstream infile(filename);
    string name;
    string number;
    while(infile >> name >> number){
        // cout << name << " " << number << endl;
        node *temp = new node;
        temp->name = name;
        temp->number = number;
        temp->next = NULL;
        head = temp;
        cout << head->name << endl;

    }
    
}

void printList(struct node *head) {
    cout << head->name << endl;
    // cout << head->next->name << endl;
}

struct node head;
struct node *curr;

int main(int argc, char **argv) {
    readFile(&head,argv[1]);
    // cout << head.name << endl;
    // cout << head.next->name << endl;
    printList(&head);
    
    return 0;
}