class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(string word: wordList) {
            dict.insert(word);
        }

        if(!dict.contains(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int res = 1;

        while(!q.empty()) {
           int count = q.size();
           for(int i = 0; i < count; ++i) {
                string word = q.front();
                q.pop();

                if(word == endWord) {
                    return res;
                }
                dict.erase(word);

                for(int j = 0; j < word.size(); ++j) {
                    char c = word[j];
                    for(int k = 0; k < 26; ++k) {
                        word[j] = k + 'a';
                        if(dict.contains(word)) {
                            q.push(word);
                            dict.erase(word);
                        }
                        word[j] = c;
                    }
                }
           }
           res++;
        }

        return 0;
    }
};