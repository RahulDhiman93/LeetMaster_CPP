class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visited;
        int res = 0;
        int n = s.size();
        int i = 0, j = 0;

        while (j < n) {
            while (visited.contains(s[j])) {
                visited.erase(s[i]);
                i++;
            }
            res = max(res, (j - i + 1));
            visited.insert(s[j]);
            j++;
        }

        return res;
    }
};