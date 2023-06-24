// 206. Reverse a linked list (using recussion)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void traversal(struct node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

struct node *reverselist(struct node *head){
    if(head->next==NULL){
        return head;
    }
    struct node *newhead = reverselist(head->next);
    struct node *nexthead = head->next;
    nexthead->next = head;
    head->next = NULL;
    return newhead;
}   


int main()
{
    struct node *head = new struct node();
    struct node *second = new struct node();
    struct node *third = new struct node();
    struct node *fourth = new struct node();

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = NULL;

    cout<<"Printing the list before reversiong it: \n";
    traversal(head);

    cout<<"\nPrinting the list after reversring it: \n";
    head = reverselist(head);
    traversal(head);

    return 0;
}