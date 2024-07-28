class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(candidates, {}, 0, target, res);
        return res;
    }
private:
    void helper(vector<int>& nums, vector<int> sub, int n, int t,  vector<vector<int>>& res) {
        if(t==0) {
            res.push_back(sub);
            return;
        }
        if(t<0 || n >= nums.size()) {
            return;
        }
    
        sub.push_back(nums[n]);
        helper(nums, sub, n, t-nums[n], res);

        sub.pop_back();
        helper(nums, sub, n+1, t, res);
    }
};