// Copy list with random pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *itr = head;
        while(itr!=NULL){
            Node *copynode = new Node(itr->val);
            copynode->next = itr->next;
            itr->next = copynode;
            itr = itr->next->next;
        }
        itr = head;
        while(itr!=NULL){
            if(itr->random!=NULL){
                itr->next->random = itr->random->next;
            }
            else{
                itr->next->random = NULL;
            }
            itr = itr->next->next;
        }
        itr = head;
        Node *psuedonode = new Node(0);
        Node *copy = psuedonode;
        Node *front;
        while(itr!=NULL){
            front = itr->next->next;
            copy->next = itr->next;
            itr->next = front;
            itr = front;
            copy = copy->next;
        }
        return psuedonode->next;
    }
};