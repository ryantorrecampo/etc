#include <iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
};

class list {
    private:
        node *head, *tail;
    public:
        list() {
            head = NULL;
            tail = NULL;
        }

        void add(int n) {
            node *tmp = new node;
            tmp->data = n;
            tmp->next = NULL;

            if(head == NULL){
                head = tmp;
                tail = tmp;
            } else {
                tail->next = tmp;
                tail = tail->next;
            }
        }

        void display() {
            node *tmp;
            tmp = head;
            while(tmp!=NULL) {
                cout << tmp->data << endl;
                tmp = tmp->next;
            }
        }

        node* getHead() {
            return head;
        }

        void recursiveDisplay(node *head) {
            if(head == NULL) {
                cout << "End of list" << endl;
            } else {
                cout << head->data << endl;
                recursiveDisplay(head->next);
            }
        }

        static void concatenate(node *a, node *b) {
            if(a != NULL && b != NULL) {
                if(a->next == NULL) {
                    a->next = b;
                } else {
                    concatenate(a->next, b);
                }
            } else {
                cout << "Either a or b is null" << endl;
            }
        }

        void front(int n) {
            node *tmp = new node;
            tmp->data = n;
            tmp->next = head;
            head = tmp;
        }

        void after(node *a, int n) {
            node *p = new node;
            p->data = n;
            p->next = a->next;
            a->next = p;
        }

        void del(node *before_del) {
            node *temp;
            temp = before_del->next;
            before_del->next = temp->next;
            delete temp;
        }

};

int main() {

    list a;
    list b;

    a.add(1);
    a.add(3);
    a.display();
    a.recursiveDisplay(a.getHead());

    b.add(2);
    b.add(4);
    a.concatenate(a.getHead(), b.getHead());
    a.recursiveDisplay(a.getHead());

    a.front(27);
    a.after(a.getHead(), 30);
    a.recursiveDisplay(a.getHead());



    

    return 0;
}