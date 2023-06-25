// 237. Delete Node in a Linked List
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void deletenode(struct node *ptr){
    if(ptr->next==NULL){
        //*ptr = NULL;
    }
    else{
        ptr->data = ptr->next->data;
        ptr->next = ptr->next->next;
    }
}


void traversal(struct node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = new struct node();
    struct node *second = new struct node();
    struct node *third = new struct node();
    struct node *fourth = new struct node();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 150;
    third->next = fourth;

    fourth->data = 210;
    fourth->next = NULL;

    cout<<"Printing before deleting: \n";
    traversal(head);

    cout<<"\nPrinting after deleting: \n";
    deletenode(head);
    traversal(head);
    return 0;
}