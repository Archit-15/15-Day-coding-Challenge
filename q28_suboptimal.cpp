// 142. Linked List Cycle II (Beginning node of a cycle)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> st;
        while(head!=NULL){
            if(st.find(head) != st.end()){
                break;
            }
            st.insert(head);
            head = head->next;
        }
        return head;
    }
};
