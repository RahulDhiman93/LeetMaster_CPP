class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visited;
        int res = 0;
        int n = s.size();
        int i = 0, j = 0;

        while(j < n) {
            if(visited.contains(s[j])) {
                i++;
                j = i;
                visited.clear();
            } else {
                res = max(res, (j-i+1));
                visited.insert(s[j]);
                j++;
            }
        }

        return res;
    }
};