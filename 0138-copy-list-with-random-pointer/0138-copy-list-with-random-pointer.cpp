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
        Node dummy (0);
        Node *new_head = &dummy;
        Node *tmp_head = head;
        unordered_map<Node *, Node *> data;
        while (head) {
            data[head] = new Node (head->val);
            head = head->next;
        }

        head = tmp_head;
        while (head) {
            data[head]->next = data[head->next];
            data[head]->random = data[head->random];
            head = head->next;
        }
        
        return data[tmp_head];
    }
};