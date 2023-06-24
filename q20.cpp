// 876. Middle of the Linked List
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *middle(struct node* head){
    struct node *ptr = head;
    int i=1;
    while(ptr->next!=NULL){
        ptr = ptr->next;
        i++;
    }
    if(i%2==0){
        int j=1;
        while(j<((i/2)+1)){
            head = head->next;
            j++;
        }
    }
    else{
        int j=1;
        while(j<((i/2)+1)){
            head = head->next;
            j++;
        }
    }
    return head;
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

    second->data = 45;
    second->next = third;

    third->data = 51;
    third->next = fourth;

    fourth->data = 100;
    fourth->next = fifth;

    fifth->data = 200;
    fifth->next = NULL;
    // 23-45-51-100-200

    struct node *mid = middle(head);
    cout<<mid->data;
    return 0;
}