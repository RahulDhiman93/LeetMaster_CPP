class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charsMap;
        for (int i = 0; i < chars.size(); ++i) {
            charsMap[chars[i]]++;
        }

        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            unordered_map<char, int> checkMap = charsMap;
            int temp = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                if (checkMap.contains(words[i][j])) {
                    temp++;
                    checkMap[words[i][j]]--;
                    if (checkMap[words[i][j]] == 0) {
                        checkMap.erase(words[i][j]);
                    }
                }
            }
            if (temp == words[i].size()) {
                res += temp;
            }
        }

        return res;
    }
};