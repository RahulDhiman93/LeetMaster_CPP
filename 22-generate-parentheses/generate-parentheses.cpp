class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("(", res, n, 1, 0);
        return res;
    }

private:
    void helper(string str, vector<string>& res, int n, int lc, int rc) {
        if (lc==n && rc==n) {
            res.push_back(str);
            return;   
        }
        if(lc<n){
            helper(str+'(', res, n, lc+1, rc);
        }
        if(lc>rc){
            helper(str+')', res, n, lc, rc+1);
        }
    }
};