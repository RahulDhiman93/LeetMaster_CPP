class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hmap;
        for(const auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            hmap[key].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& pair : hmap) {
            res.push_back(pair.second);
        }
        return res;
    }
};