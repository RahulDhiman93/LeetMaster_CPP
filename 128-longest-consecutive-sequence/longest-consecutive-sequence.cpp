class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> validate;
        int res = 0;

        for(int num: nums) {
            validate.insert(num);
        }

        for(int num: validate) {
            if (validate.find(num -1) == validate.end()) {
                int subRes = 1;
                while(validate.find(num + subRes) != validate.end()) {
                    subRes++;
                }
                res = max(res, subRes);
            }
        }

        return res;

        // unordered_set<int> numSet(nums.begin(), nums.end());
        // int longest = 0;

        // for (int num : numSet) {
        //     if (numSet.find(num - 1) == numSet.end()) {
        //         int length = 1;
        //         while (numSet.find(num + length) != numSet.end()) {
        //             length++;
        //         }
        //         longest = max(longest, length);
        //     }
        // }
        // return longest;
    }
};