#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct contact {
    bool available;
    string fname;
    string lname;
    string phoneNumber;
    string email;
};

void createPhoneBook(contact *& myPhoneBook, int size) {
    myPhoneBook = new contact[size];
    for(int i = 0; i < size; i++) {
        myPhoneBook[i].available = true;
    }
}

bool addContact(contact *myPhoneBook, string _fname, string _lname, string _phoneNumber, string _email, int size) {
    for (int i = 0; i < size; i++) {
        if(myPhoneBook[i].available == false) continue;
        myPhoneBook[i].fname = _fname;
        myPhoneBook[i].lname = _lname;
        myPhoneBook[i].phoneNumber = _phoneNumber;
        myPhoneBook[i].email = _email;
        myPhoneBook[i].available = false;
        return true;
    }
    return false;
}

bool deleteContact(contact *myPhoneBook, string _fname, int size) {
    for(int i = 0; i < size; i++) {
        if(myPhoneBook[i].fname.compare(_fname) == 0){
            myPhoneBook[i].available = true;
            return true;
        }
    }
    return false;
}

void printPhoneBook(contact *myPhoneBook, int size) {
    cout << "FName\t\tLName\t\tPhone number\t\temail" << endl;
    for(int i = 0; i < size; i++) {
        if(myPhoneBook[i].available == false) {
            cout << myPhoneBook[i].fname << "\t\t" << myPhoneBook[i].lname << "\t\t" << myPhoneBook[i].phoneNumber << "\t\t" << myPhoneBook[i].email << endl;
        }
    }
}

bool readFromFile(contact *myPhoneBook, string filename, int size) {
    ifstream infile(filename);
    if(infile.is_open() == true) {
        string fname;
        string lname;
        string phoneNumber;
        string email;
        int i = 0;
        while(infile >> fname >> lname >> phoneNumber >> email) {
            if(myPhoneBook[i].available == true) {
                addContact(myPhoneBook, fname, lname, phoneNumber, email, size);
                i++;
            } else {
                cout << "The phonebook is full\n";
                break;
            }
        }
        infile.close();
        return true;
    } else {
      cout << "File not found\n";
      return false;
    }
}

void deletePhonebook(contact *& myPhoneBook) {
    delete [] myPhoneBook;
}