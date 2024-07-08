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
        unordered_map<Node*, Node*> umap;

        Node* cur = head;
        while (cur != NULL) {
            Node* copy = new Node(cur->val); 
            umap[cur] = copy;
            cur = cur->next;
        }

        cur = head;
        while(cur != NULL) {
            Node* copy = umap[cur];
            copy->next = umap[cur->next];
            copy->random = umap[cur->random];
            cur = cur->next;
        }

        return umap[head];
    }
};