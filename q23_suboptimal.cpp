// 21. Merge Two Sorted Lists
// TC -> O(n1+n2) SC-> O(n1+n2) optimal version takes O(1) space complexity

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                ListNode *node = new ListNode(list1->val);
                temp->next = node;
                temp = node;
                list1 = list1->next;
            }
            else{
                ListNode *node = new ListNode(list2->val);
                temp->next = node;
                temp = node;
                list2 = list2->next;
            }
        } 
        while(list1!=NULL){
            ListNode *nd = new ListNode(list1->val);
            temp->next = nd;
            temp = nd;
            list1 = list1->next;
        }  
        while(list2!=NULL){
            ListNode *nd = new ListNode(list2->val);
            temp->next = nd;
            temp = nd;
            list2 = list2->next;
        }   
        return dummy->next;
    }
};