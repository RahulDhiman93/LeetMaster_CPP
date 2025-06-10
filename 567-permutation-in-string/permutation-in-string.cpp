class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        unordered_set<char> s1Set;
        sort(s1.begin(), s1.end());
        
        for (char c: s1) {
            s1Set.insert(c);
        }

        for (int i = 0; i < s2.size(); ++i) {
            if (s1Set.contains(s2[i])) {
                bool found = isValid(s1, s2.substr(i, k));
                if (found)
                    return found;
            }
        }

        return false;
    }

private:
    bool isValid(string s1, string s2) {
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};