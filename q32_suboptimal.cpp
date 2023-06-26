// 138. Copy List with Random Pointer

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
        Node *temp = head;
        unordered_map<Node *, Node *> hashmap;
        while(temp!=NULL){
            Node *copynode = new Node(temp->val);
            hashmap[temp] = copynode;
            temp = temp->next;
        }
        Node *t = head;
        while(t!=NULL){
            Node *copynode = hashmap[t];
            copynode->next = (t->next != NULL) ? hashmap[t->next] : NULL;
            copynode->random = (t->random!=NULL) ? hashmap[t->random] : NULL;
            t = t->next;
        }
        return hashmap[head];
    }
};