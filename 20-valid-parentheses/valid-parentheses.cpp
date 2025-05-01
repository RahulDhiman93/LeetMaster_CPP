class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hmap;
        hmap['{'] = '}';
        hmap['['] = ']';
        hmap['('] = ')';

        stack<char> container;

        for(char c : s) {
            if (hmap.contains(c)) {
                container.push(c);
            } else {
                if (container.size() == 0)
                    return false;
                char top = container.top();
                container.pop();
                if (c != hmap[top])
                    return false;
            }
        }

        return container.size() > 0 ? false : true;
    }
};