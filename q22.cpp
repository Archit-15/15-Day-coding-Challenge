// 2. Add Two Numbers   TC-> O(max(n1,n2))
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

struct node *addTwo(struct node *head1,struct node *head2){
    struct node *dummy = new struct node();
    struct node *temp = dummy;
    int carry = 0;
    while(head1!=NULL || head2!=NULL || carry!=0){
        int sum = 0;
        if(head1!=NULL){
            sum = sum + head1->data;
            head1 = head1->next;
        }
        if(head2!=NULL){
            sum = sum + head2->data;
            head2 = head2->next;
        }
        sum = sum + carry;
        carry = sum/10;
        struct node *N = new struct node();
        N->data = (sum%10);
        temp->next = N;
        temp = N;
    }
    temp->next = NULL;
    return dummy->next;
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

    third1->data = 3;
    third1->next = NULL;

    struct node *head2 = new struct node();
    struct node *second2 = new struct node();
    struct node *third2 = new struct node();

    head2->data = 5;
    head2->next = second2;

    second2->data = 6;
    second2->next = third2;

    third2->data = 4;
    third2->next = NULL;

    struct node *ans = addTwo(head1,head2);
    traversal(ans);
    return 0;
}
