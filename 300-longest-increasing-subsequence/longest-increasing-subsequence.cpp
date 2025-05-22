class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        unordered_map<int, int> memo;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, dfs(nums, memo, i));
        }
        return res;
    }

private:
    int dfs(vector<int>& nums, unordered_map<int, int>& memo, int index) {
        if (index >= nums.size()) {
            return 0;
        }

        if (index == nums.size() - 1) {
            return 1;
        }

        if (memo.contains(index)) {
            return memo[index];
        }

        int ans = 1;
        for (int i = index; i < nums.size(); i++) {
            if (nums[i] > nums[index]) {
                ans = max(ans, 1+dfs(nums, memo, i));
            }
        }
        memo[index] = ans;
        return memo[index];
    }
};