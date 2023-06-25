//Intersection of 2 lists

#include<iostream>
#include<set>
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
    unordered_set<struct node *> st;
    while(head1!=NULL){ 
        st.insert(head1);
        head1 = head1->next;
    }
    while(head2!=NULL){
        if(st.find(head2) != st.end()){
            break;
        }
        head2 = head2->next;
    }
    return head2;
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