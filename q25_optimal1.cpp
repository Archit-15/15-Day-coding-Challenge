// Intersion of 2 lists

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *createnode(int val){
    struct node *ptr = new struct node();
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
};

struct node *CheckIntersection(struct node *head1, struct node *head2){
    struct node *p = head1;
    struct node *q = head2;
    int len1 =1;
    int len2 =1;
    while(p->next != NULL || q->next != NULL){
        if(p->next !=NULL ){
            p = p->next;
            len1++;
        }
        if(q->next != NULL){
            q = q->next;
            len2++;
        }
    }
    int diff = len1 - len2;  // if diff is negative then len2 is bigger
    if(diff<0){
        while(diff!=0){
        head2 = head2->next;
        ++diff;
        }
    }
    else{
        while(diff!=0){
            head1 = head1->next;
            --diff;
        }
    }
    while(head1 != NULL){
        if(head1==head2){
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

int main()
{
    struct node *common1 = createnode(8);
    struct node *common2 = createnode(4);
    struct node *common3 = createnode(5);
    common1->next = common2;
    common2->next = common3;

    struct node *head1 = createnode(4);
    struct node *second1 = createnode(1);
    // Linking
    head1->next = second1;
    second1->next = common1;


    struct node *head2 = createnode(5);
    struct node *second2 = createnode(6);
    struct node *third2 = createnode(1);
    //Linking
    head2->next = second2;
    second2->next = third2;
    third2->next = common1;

    struct node *ans = CheckIntersection(head1,head2);

    cout<<ans->data;

    return 0;
}