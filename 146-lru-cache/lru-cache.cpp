class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int keyPass, int value) {
        key = keyPass;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> umap;
    int cap=0;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;        
    }
    
    int get(int key) {
        if (umap.contains(key)) {
            remove(umap[key]);
            insert(umap[key]);
            return umap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (umap.contains(key)) {
            remove(umap[key]);
        }
        umap[key] = new Node(key, value);
        insert(umap[key]);

        if (umap.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            umap.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */