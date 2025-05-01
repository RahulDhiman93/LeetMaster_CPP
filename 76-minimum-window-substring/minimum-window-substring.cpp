class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;

        for (char c : t) {
            tmap[c]++;
        }

        int have = 0, need = tmap.size();
        int i = 0;
        int resLen = INT_MAX;
        pair<int, int> res;

        for(int j = 0; j < s.size(); j++) {
            smap[s[j]]++;

            if (tmap.contains(s[j]) && smap[s[j]] == tmap[s[j]])
                have++;

            while(have == need) {
                if ((j - i + 1) < resLen) {
                    resLen = j - i + 1;
                    res = {i, j};
                }
                smap[s[i]]--;
                if (tmap.contains(s[i]) && smap[s[i]] < tmap[s[i]])
                    have--;
                
                i++;
            }
        }

        if (resLen == INT_MAX)
            return "";

        return s.substr(res.first, resLen);
    }
};