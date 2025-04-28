class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        vector<vector<int>> res;
        sort(sorted.begin(), sorted.end());

        for(int k = 0; k < n; k++) {
            if(k > 0 && sorted[k] == sorted[k-1]) {
                continue;
            }
            int i = k+1, j = n-1;
            while(i<j) {
                int sum = sorted[i] + sorted[j] + sorted[k];
                if (sum < 0) {
                    i++;
                } else if (sum > 0) {
                    j--;
                } else {
                    res.push_back({sorted[i], sorted[j], sorted[k]});
                    i++;
                    while(sorted[i] == sorted[i-1] & i<j){
                        i++;
                    }
                }
            }
        }

        return res;
    }
};