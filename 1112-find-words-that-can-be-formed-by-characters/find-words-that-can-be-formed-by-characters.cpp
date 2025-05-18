class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charsMap;
        for (int i = 0; i < chars.size(); ++i) {
            charsMap[chars[i]]++;
        }

        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            unordered_map<char, int> checkMap;
            for (char c : words[i]) {
                checkMap[c]++;
            }

            bool good = true;
            for (char c : words[i]) {
                if (!charsMap.contains(c) || checkMap[c] > charsMap[c]) {
                    good = false;
                    break;
                }
            }

            if (good) {
                res += words[i].size();
            }
        }

        return res;
    }
};