class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int i = 0, j = n - 1;
        int temp = 0;

        while(i<j) {
            temp = (j-i) * min(height[i], height[j]);
            res = max(res, temp);
            
            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return res;
    }
};