//Merge linked lists

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

struct node *mergesort(struct node *l1,struct node *l2){
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    if(l1->data > l2->data){
        swap(l1,l2);
    }

    struct node *res = l1;

    while(l1!=NULL && l2!=NULL){
        struct node * temp = NULL;
        while(l1 != NULL && l1->data <= l2->data){
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1,l2);
    }
    return res;
}

int main()
{
    struct node *head1 = new struct node();
    struct node *second1 = new struct node();
    struct node *third1 = new struct node();

    head1->data = 2;
    head1->next = second1;

    second1->data = 4;
    second1->next = third1;

    third1->data = 10;
    third1->next = NULL;

    struct node *head2 = new struct node();
    struct node *second2 = new struct node();
    struct node *third2 = new struct node();

    head2->data = 1;
    head2->next = second2;

    second2->data = 3;
    second2->next = third2;

    third2->data = 7;
    third2->next = NULL;

    struct node *merged_head = mergesort(head1,head2);
    traversal(merged_head);
    return 0;
}