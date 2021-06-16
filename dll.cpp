#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *prev ,*next;
        
};
class Dll{
    Node* head;
    Node* tail;
    
    public:
        Dll()
        {
            head = NULL;
            tail = NULL;
        }
        ~Dll() {};
        void push(int data);
        void print();
        void insertAtLast(int data);
        void insert(int data , int p);
        void pop();
        void pop_back();
        void delete_(int p);
};
void Dll::push(int data)
{
    Node* temp = new Node();
    temp->data= data;
    if(head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = tail = temp;
        return;
    }
    if(head != NULL)
    {
        head->prev = temp;  
    }
    temp->next = head;
    temp->prev = NULL;
    head = temp;

}
void Dll::insertAtLast(int data)
{
    Node* temp = new Node();
    temp->data = data;
    if(head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = tail = temp; 
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
    tail = temp;
}
void Dll::insert(int data , int p)
{
    if(p == 1)
    {
        Dll::push(data);
        return;
    }
    Node* temp = new Node();
    temp->data = data;
    Node* ptr = head;
    while(p > 1)
    {
        ptr = ptr->next;
        p--;
    }
    temp->prev = ptr->prev;
    ptr->prev->next = temp;
    temp->next = ptr;
    ptr->prev = temp;

    
}
void Dll::pop()
{
    if(head == NULL)
    {
        cout<<"NO Element present"<<endl;
        return;
    }
    if(head == tail)
    {
        Node* temp = head;
        
        head = tail = NULL;
        delete temp;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void Dll::pop_back()
{
    if(head == NULL)
    {
        cout<<"NO Element present"<<endl;
        return;
    }
    if(head == tail)
    {
        Node* temp = head;
        head = tail = NULL;
        delete temp;
        return;
    }
    Node* temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    delete temp;

}
void Dll::delete_(int p)
{
    Node* ptr = head;
    while(p > 1)
    {
        ptr = ptr->next;
        p--;
    }
    if(ptr == head)
    {
        head = head->next;
        head->prev = NULL;
    }
    else if(ptr == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    delete ptr;

}
void Dll::print()
{
    Node* temp;
    temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    Dll* d = new Dll();
    d->push(5);
    d->push(6);
    d->push(7);
    d->push(8);
    d->insertAtLast(1);
    d->insertAtLast(2);
    d->insertAtLast(3);
    d->insertAtLast(4);
    // d->print();
    d->insert(10, 2);
    d->insert(11,3);
    d->print();
    d->delete_(3);
    d->print();
    d->delete_(4);
    d->print();

    delete d;
    
}