#include "phonebook.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    contact *myPhoneBook = nullptr;
    int size;
    string filename, _fname;
    cout << "Enter the size:" << endl;
    cin >> size;
    createPhoneBook(myPhoneBook, size);
    cout << "Enter the filename:" << endl;
    cin >> filename;
    if(readFromFile(myPhoneBook, filename, size) == false) {
        deletePhonebook(myPhoneBook);
        return -1;
    }
    printPhoneBook(myPhoneBook, size);
    cout << "Enter the first name of who you want to delete:" << endl;
    cin >> _fname;
    
    if(deleteContact(myPhoneBook, _fname, size) == true) {
        cout << "Contact deleted" << endl;
    } else {
        cout << "Contact not found" << endl;
    }
    printPhoneBook(myPhoneBook, size);
    deletePhonebook(myPhoneBook);
    return 0;
}