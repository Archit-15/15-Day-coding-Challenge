//234. Palindrome Linked List
class Solution {
public:
    ListNode *reverselist(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *temp;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode* temp = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead = reverselist(slow->next);
        while(newhead!=NULL){
            if(temp->val != newhead->val){
                return false;
            }
            temp = temp->next;
            newhead = newhead->next;
        }
        return true;
    }
};