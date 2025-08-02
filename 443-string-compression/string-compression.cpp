struct Node {
    char val;
    Node* next;
    Node* prev;

    Node(char val, Node* next, Node* prev) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class Solution {
private:
    unordered_map<char, int> hashMap;
    Node* head = new Node(' ', nullptr, nullptr);
    Node* tail = new Node(' ', nullptr, nullptr);

    void add(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->next = tail;
        node->prev = prev;
        tail->prev = node;
    }

public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n <= 1)
            return n;

        head->next = tail;
        tail->prev = head;

        int i = 0, j = 0;
        while (i <= j && j < n) {
            if (chars[i] == chars[j]) {
                hashMap[chars[i]]++;
                j++;
            } else {
                Node* newNode = new Node(chars[i], nullptr, nullptr);
                add(newNode);

                if (hashMap[chars[i]] > 1) {
                    string count = to_string(hashMap[chars[i]]);
                    for (char c : count) {
                        Node* newNode = new Node(c, nullptr, nullptr);
                        add(newNode);
                    }
                }
                hashMap.erase(chars[i]);
                i = j;
            }
        }

        for (auto itr = hashMap.begin(); itr != hashMap.end(); itr++) {
            Node* newNode = new Node(itr->first, nullptr, nullptr);
            add(newNode);

            if (itr->second > 1) {
                string count = to_string(itr->second);
                for (char c : count) {
                    Node* newNode = new Node(c, nullptr, nullptr);
                    add(newNode);
                }
            }
        }

        Node* nodeCheck = head->next;
        while (nodeCheck && nodeCheck != tail) {
            cout << nodeCheck->val << " ";
            nodeCheck = nodeCheck->next;
        }

        Node* node = head->next;
        int k = 0;
        while (node && node != tail && k < n) {
            chars[k] = node->val;
            node = node->next;
            k++;
        }

        return k;
    }
};