class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length(), n = t.length();
        if (m != n) return false;

        unordered_map<char, int> umap;

        for(auto c : s) {
            umap[c]++;
        }

        for(auto c : t) {
            umap[c]--;
        }

        for(auto itr = umap.begin(); itr != umap.end(); ++itr) {
            if (umap[itr->first] != 0) {
                return false;
            }
        }

        return true;
    }
};