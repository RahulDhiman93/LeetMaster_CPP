class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dict;
        for (string word : wordList) {
            dict.insert(word);
        }

        if (!dict.contains(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int res = 1;

        while (!q.empty()) {
            int count = q.size();
            while (count) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return res;
                }
                dict.erase(word);

                for (int i = 0; i < word.size(); ++i) {
                    char c = word[i];
                    for (int j = 0; j < 26; ++j) {
                        word[i] = j + 'a';
                        if (dict.contains(word)) {
                            q.push(word);
                            dict.erase(word);
                        }
                        word[i] = c;
                    }
                }
                count--;
            }
            res++;
        }

        return 0;
    }
};