// Rotate linked list by K to right
#include<iostream>
#include<bits/stdc++.h>

struct node{
    int data;
    struct node *next;
}

struct node *rotate(struct node *head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }

    int len=1;
    struct node *ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
        len++;
    }
    ptr->next = head;
    int i = k%len;
    int position = len - i;
    int j = 1;
    ptr = head;
    while(j<position){
        ptr = ptr->next;
        j++;
    }
    head = ptr->next;
    ptr->next = NULL;
    return head;
}