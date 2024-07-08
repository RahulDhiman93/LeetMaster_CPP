class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> umap;
        for (int i=0; i<s.size(); i++) {
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for (auto i = umap.begin(); i != umap.end(); i++) {
            if (i->second != 0) {
                return false;
            }
        } 
        return true;
    }
};