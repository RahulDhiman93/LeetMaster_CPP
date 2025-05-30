struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {   
private:
    int capacity;
    unordered_map<int, Node*> hmap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!hmap.contains(key)) {
            return -1;
        }

        Node* node = hmap[key];
        remove(node);
        add(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (hmap.contains(key)) {
            Node* old = hmap[key];
            remove(old);
        }

        Node* node = new Node(key, value);
        hmap[key] = node;
        add(node);

        if (hmap.size() > capacity) {
            Node* del = head->next;
            remove(del);
            hmap.erase(del->key);
        }
    }

    void add(Node* node) {
        Node* lastNode = tail->prev;
        lastNode->next = node;
        node->prev = lastNode;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */