// 25. Reverse Nodes in k-Group (hard)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverselist(ListNode *start,ListNode *end){
        ListNode *temp;
        ListNode *curr = start;
        ListNode *prev = NULL;
        while(prev!=end){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            if(temp!=NULL){
                curr = temp;
            }
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *start = head;
        ListNode *end = head;
        int i = 1;
        while(i<k){
            end = end->next;
            if(end==NULL){
                return head;
            }
            ++i;
        }
        ListNode *newhead = reverseKGroup(end->next,k);
        reverselist(start,end);   
        start->next = newhead;
        return end;
    }
};