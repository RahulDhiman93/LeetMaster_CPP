class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        helper(s, {}, 0, res);
        return res;
    }
private:
    void helper(string& s, vector<string> substr, int n, vector<vector<string>>& res) {
        if(n == s.size()) {
            res.push_back(substr);
            return;
        }
        for(int i=n;i<s.size();i++) {
            if (isPal(s, n, i)) {
                string str = s.substr(n, i-n+1);
                substr.push_back(str);
                helper(s, substr, i+1, res);
                substr.pop_back();
            }
        }
    }

    bool isPal(string& str, int i, int j) {
        while(i<j) {
            if(str[i]!=str[j]) {
                return false;
            }
            i++; j--;
        }
        return true;
    }
};