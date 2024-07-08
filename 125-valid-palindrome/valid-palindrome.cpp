class Solution {
public:
    bool isPalindrome(string s) {
        string str = getSimpleStr(s);
        for(int i=0,j=str.size()-1; i<str.size() && j>=0; ++i, --j) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }

private:
    string getSimpleStr(string str) {
        string ss;
        for(char c : str) {
            if (c>='A' && c <='Z') {
                ss.push_back(static_cast<char>(tolower(c)));
            } else if (c>='a' && c<='z') {
                ss.push_back(c);
            } else if (c>='0' && c<='9') {
                ss.push_back(c);
            }
        }
        return ss;
    }
};