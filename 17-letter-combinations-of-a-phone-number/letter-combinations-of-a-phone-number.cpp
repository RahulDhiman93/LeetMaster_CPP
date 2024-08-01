class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        unordered_map<char, string> dmap = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        helper(digits, 0, "", dmap, res);
        return res;
    }

private:
    void helper(string digits, int d, string str, unordered_map<char, string>& dmap,
                vector<string>& res) {
        if (str.size() == digits.size()) {
            res.push_back(str);
            return;
        }
        if (str.size() > digits.size())
            return;
        if (d >= digits.size())
            return;

        string s = dmap[digits[d]];

        for (int i = 0; i < s.size(); ++i) {
            str.push_back(s[i]);
            helper(digits, d + 1, str, dmap, res);
            str.pop_back();
        }
    }
};