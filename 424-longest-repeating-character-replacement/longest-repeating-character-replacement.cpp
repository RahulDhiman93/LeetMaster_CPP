class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hmap;
        int n = s.size();
        int i = 0, j = 0;
        int maxF = 0, res = 0;

        while(j < n) {
            hmap[s[j]]++;
            maxF = max(maxF, hmap[s[j]]);

            if((j-i+1) - maxF <= k) {
                res = max(res, j-i+1);
                j++;
            } else {
                hmap[s[i]]--;
                hmap[s[j]]--;
                i++;
            }
        }

        return res;
    }
};