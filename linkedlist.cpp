#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct entry {
   char name[90]="";
   char phone_num[12]="";
   struct entry *next_node=NULL;
};

struct entry list_head;
struct entry *list_current_node;

void displayListContents(struct entry *list_head) {
  list_current_node =list_head;
  string line;
  int count = 0;
  while (list_current_node!=NULL) {
      cout << count << "|" << list_current_node->name << "\n";
      list_current_node=list_current_node->next_node;
      count++;
  }
}

void readFile(struct entry *list_head, char *filename) {
    ifstream infile(filename);
    if(infile.is_open() == true) {
      return true;
    } else {
      cout << "File not found\n";
      return false;
    }
    // string fname;
    // string lname;
    // string phoneNumber;
    // string email;
    // bool isHead = true;
    // while (infile >> name >> number){
    //   struct entry *s = new entry;
    //   struct entry *temp = new entry;
    //   strcpy(temp->name, name.c_str());
    //   strcpy(temp->phone_num, number.c_str());
    //   temp->next_node = NULL;
    //   s = list_head;
    //   if(isHead){
    //     strcpy(s->name, name.c_str());
    //     strcpy(s->phone_num, number.c_str());
    //     isHead = false;
    //   }else{
    //     while(s->next_node!=NULL){
    //       s = s->next_node;
    //     }
    //     s->next_node = temp;
    //   }
      
    // }
}


char* entrySearch(struct entry *list_head,char searchTerm[90]) {
  string search(searchTerm);

  entry *curr = list_head;
  while(curr!=NULL){
    string listName(curr->name);
    if(search.compare(listName) == 0){
      // cout << curr->phone_num << endl;
      return curr->phone_num;
    }
    curr = curr->next_node;
  }
  return NULL;
}

void saveResults(char *results){
  ofstream ofs("output.txt");
  if(!ofs){
    cout << "error" << endl;
  }
  ofs << results << endl;
  ofs.close();
}

int main(int argc, char **argv) {
    readFile(&list_head,argv[1]);
    displayListContents(&list_head);
    char searchTerm[90];
    cin >> searchTerm;
    char *results =  entrySearch(&list_head,searchTerm);
    saveResults(results);
    return 0;
}
