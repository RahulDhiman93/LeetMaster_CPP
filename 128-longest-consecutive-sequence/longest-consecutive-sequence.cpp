class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;

        for(int i=0; i<nums.size(); i++) {
            if (!s.contains(nums[i]-1)) {
                int len = 0;
                while(s.contains(nums[i]+len)) {
                    len++;
                }
                res = max(res, len);
            }
        }

        return res;
    }
};