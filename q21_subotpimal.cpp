// 19. Remove Nth Node From End of List
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

struct node * deletefromend(struct node *head,int n){
    struct node *dummy = new struct node();
    dummy->next = head;
    struct node *left = dummy;
    struct node *right = head;
    int i=1;
    while(i<=n){
        right = right->next;
        i++;
    }
    while(right!=NULL){
        right = right->next;
        left = left->next;
    }
    if(left->next!=NULL){
        left->next = left->next->next;
    }
    return dummy->next;
}

int main()
{
    struct node *head = new struct node();
    struct node *second = new struct node();
    struct node *third = new struct node();
    struct node *fourth = new struct node();
    struct node *fifth = new struct node();

    head->data = 23;
    head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 100;
    third->next = fourth;

    fourth->data = 45;
    fourth->next = fifth;

    fifth->data = 2;
    fifth->next = NULL;
    //23-13-100-45-2

    cout<<"Printing the list before deleting: \n";
    traversal(head);

    cout<<"\nPrinting the list after delete it: \n";
    head = deletefromend(head,2);
    traversal(head);

    return 0;
}