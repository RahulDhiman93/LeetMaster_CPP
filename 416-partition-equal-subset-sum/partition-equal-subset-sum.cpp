class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        unordered_set<int> vs;
        vs.insert(0);
        bool res = false;
        for (int i = n - 1; i >= 0; --i) {
            unordered_set<int> vscopy = vs;
            for (auto itr = vscopy.begin(); itr != vscopy.end(); itr++) {
                vs.insert(*itr + nums[i]);
                if (vs.contains(target)) {
                    res = true;
                    break;
                }
            }
            if (res)
                return res;
        }
        return false;
    }
};