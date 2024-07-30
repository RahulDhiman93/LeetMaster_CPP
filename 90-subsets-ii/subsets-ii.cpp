class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(nums, {}, 0, res);
        return res;
    }
private:
    void helper(vector<int>& nums, vector<int> subset, int n, vector<vector<int>>& res) {
        res.push_back(subset);
        for (int i = n; i < nums.size(); i++) {
            if (i > n && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]);
            helper(nums, subset, i+1, res);
            subset.pop_back();
        }
    }
};