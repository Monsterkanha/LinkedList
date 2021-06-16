#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
//recursively reverse is remaining 

class LinkedList{
    Node* head;
    public:
    
        LinkedList()
        {
            head = NULL;
        }
        ~LinkedList() {};
        void insert(int x);
        void push(int x);
        void insert_after(int x, int p);
        void print();
        void delete_(int n);
        void delete_data(int data);
        void reverse_it();
        void printrf();
        // void reverse_R());

        void nextprint()
        {
            cout<<(head->next)->data;
        }
};
void LinkedList::insert(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void LinkedList::push(int x)
{
    Node* temp = new Node();
    temp->data = x;
    if(head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else{
        Node* p = head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = NULL;
    }
}
void LinkedList::insert_after(int x, int p)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    Node* ptr = head;
    while(p > 1)
    {
        ptr = ptr->next;
        p--;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
void LinkedList::delete_(int n)
{
    Node* temp = head;
    if(n == 1)
    {
        head = temp->next;
        delete temp;
        return;
    }
    while(n > 2)
    {
        temp = temp->next;
        n--;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next; 
    delete temp2;

}
void LinkedList::delete_data(int x)
{
    Node *p, *q;
    p = head;
    q = NULL;
    while(p!= NULL && p->data != x)
    {
        q = p;
        p = p->next;
    }
    if(p == NULL)
    {
        cout<<"NOT PRESENT"<<endl;
        return;
    }
    if(p == head)
    {
        head = p->next;
        delete p;
        return;
    }
    q->next = p->next;
    delete p;
    return;
}
void LinkedList::print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void LinkedList::reverse_it()
{
    Node *curr, *prev , *next;
    curr = head;
    prev = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void reverseprint(Node* temp)
{
    if(temp == NULL)
    {
        return;
    }
    reverseprint(temp->next);
    cout<<temp->data<<" ";
    
}


void LinkedList::printrf()
{
    Node* temp = head;
    reverseprint(temp);
    
}
int main()
{
    LinkedList* list = new LinkedList();
    list->insert(100);
    list->insert(200);
    list->insert(300);
    list->insert(400);
    list->insert(500);
    list->push(600);
    list->push(700);
    list->insert_after(5, 4);
    list->insert_after(1, 2);
    list->print();
    // list->ReverseusingR();
    list->print();

    list->nextprint();
    

    delete list;
    
}