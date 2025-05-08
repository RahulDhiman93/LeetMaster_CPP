class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(candidates, target, 0, {}, res);
        return res;
    }

private:
    void helper(vector<int>& candidates, int target, int index, vector<int> sub, vector<vector<int>>& res) {
        if (target < 0 || index >= candidates.size())
            return;

        if (target == 0) {
            res.push_back(sub);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            sub.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i, sub, res);
            sub.pop_back();
        }
    }
};