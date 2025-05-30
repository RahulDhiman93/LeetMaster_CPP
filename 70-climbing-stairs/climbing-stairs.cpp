class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int one = 1, two = 1, temp = 1;
        for (int i = n-2; i >=0; i--) {
            temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};