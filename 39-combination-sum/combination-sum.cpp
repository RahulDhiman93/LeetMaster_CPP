class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        backtrack(candidates, {}, 0, target, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<int> sub, int n, int t, vector<vector<int>>& res) {
        if (t==0){
            res.push_back(sub);
            return;
        }

        if (t<0 || n >= nums.size()) {
            return;
        }

        for(int i = n; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            backtrack(nums, sub, i, t-nums[i], res);
            sub.pop_back();
        }
    }
};