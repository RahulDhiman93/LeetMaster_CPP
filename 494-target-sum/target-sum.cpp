class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> cache;
        int m = nums.size();
        return dfs(cache, nums, target, m, 0, 0);
    }

private:
    int dfs(map<pair<int, int>, int>& cache, vector<int>& nums, int& target,
            int& m, int i, int sum) {
        if (i == m) {
            return sum == target ? 1 : 0;
        }
        if (cache.contains({i, sum})) {
            return cache[{i, sum}];
        }

        int option1 = dfs(cache, nums, target, m, i + 1, sum + nums[i]);
        int option2 = dfs(cache, nums, target, m, i + 1, sum - nums[i]);
        cache[{i, sum}] = option1 + option2;
        return cache[{i, sum}];
    }
};