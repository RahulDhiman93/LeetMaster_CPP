class MinStack {
private:
    struct Node {
        int val;
        int minVal;
        Node* next;

        Node(int val, int minVal, Node* next) {
            this->val = val;
            this->minVal = minVal;
            this->next = next;
        }

        Node() {
            this->next = nullptr;
        }
    };

    Node* head;

public:
    MinStack() {
        head = new Node();
    }
    
    void push(int val) {
        Node* top = head->next;
        Node* newNode;
        if (top != nullptr) {
            int topMinVal = top->minVal;
            int minVal = min(val, topMinVal);
            newNode = new Node(val, minVal, top);
        } else {
            newNode = new Node(val, val, top);
        }
        head->next = newNode;
    }
    
    void pop() {
        Node* top = head->next;
        if (top != nullptr) {
            head->next = top->next;
            top->next = nullptr;
        }
    }
    
    int top() {
        Node* top = head->next;
        if (top != nullptr)
            return top->val;
        
        return 0;
    }
    
    int getMin() {
        Node* top = head->next;
        if (top != nullptr)
            return top->minVal;
        
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */