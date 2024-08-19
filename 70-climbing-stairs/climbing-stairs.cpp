class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int f = 1;
        int s = 2;
        int res = 0;
        for(int i=2;i<n;i++) {
            res = f + s;
            f = s;
            s = res;
        }
        return res;
    }
};