/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> hmap;

        Node* temp = new Node(node->val);
        hmap[node] = temp;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* front = q.front(); q.pop();

            for(Node* n: front->neighbors) {
                if(!hmap.contains(n)) {
                    hmap[n] = new Node(n->val);
                    q.push(n);
                }
                hmap[front]->neighbors.push_back(hmap[n]);
            }
        }

        return temp;
    }
};