#include <iostream>
using namespace std;
class List;
class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(NULL) {}
    friend class List;
};

class List
{
    Node *head;
    Node *tail;

public:
    List() : head(NULL), tail(NULL) {}
    void push_back(int data){
        if(tail  == NULL){
            Node *n = new Node(data);
            head  = tail = n ;
        }
        else{
            Node *n = new Node(data);
            tail->next = n;
            tail = n ;
        }
    }
    void display(List &l){
        while (head != NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
    }
    void merge(List &l , List &l2){
        while(l2.head != NULL){
            l.push_back(l2.head->data);
            l2.head = l2.head->next;
        }
        display(l);
    }

};

int main()
{

    List l ;
     l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    // l.display(l);
    List l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    l.merge(l , l2);

    return 0;
}
