class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> data;
        Node *curr = head;
        while (curr) {
            data[curr] = new Node (curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            data[curr]->next = data[curr->next];
            data[curr]->random = data[curr->random];
            curr = curr->next;
        }
        return data[head];
    }
};