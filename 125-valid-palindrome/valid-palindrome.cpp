class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> str;
        int diff = 'A' - 'a';

        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                str.push_back(c - diff);
            } else if (c >= 'a' && c <= 'z') {
                str.push_back(c);
            } else if (c >= '0' && c <= '9') {
                str.push_back(c);
            }
        }

        int i = 0, j = str.size() - 1;

        while(i < j) {
            if(str[i] != str[j])
                return false;
            
            i++; j--;
        }

        return true;
    }
};