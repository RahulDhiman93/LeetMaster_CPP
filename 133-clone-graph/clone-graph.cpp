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
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> umap;

        Node* newNode = new Node(node->val);
        umap[node] = newNode;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for(Node* subNode: curr->neighbors) {
                if(!umap.contains(subNode)) {
                    umap[subNode] = new Node(subNode->val);
                    q.push(subNode);
                }
                umap[curr]->neighbors.push_back(umap[subNode]);
            }
        }

        return newNode;
    }
};