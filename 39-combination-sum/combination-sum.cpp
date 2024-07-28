class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(candidates, {}, 0, 0, target, res);
        return res;
    }
private:
    void helper(vector<int>& nums, vector<int> sub, int sum, int n, int t,  vector<vector<int>>& res) {
        if(sum == t) {
            vector<int> temp = sub;
            res.push_back(sub);
            return;
        }
        if(sum > t || n >= nums.size()) {
            return;
        }
    
        sub.push_back(nums[n]);
        helper(nums, sub, sum+nums[n], n, t, res);

        sub.pop_back();
        helper(nums, sub, sum, n+1, t, res);
    }
};