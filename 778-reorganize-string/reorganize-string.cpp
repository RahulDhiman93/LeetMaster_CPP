class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> hmap;
        for(char c: s) {
            hmap[c]++;
        }

        string res;

        priority_queue<pair<int, char>> pq;
        for(auto itr = hmap.begin(); itr != hmap.end(); itr++) {
            pq.push(make_pair(itr->second, itr->first));
        }

        while(!pq.empty()) {
            pair<int, char> top = pq.top(); pq.pop();
            if (res.empty() || res.back() != top.second) {
                res += top.second;
                top.first--;
                if (top.first > 0) {
                    pq.push(top);
                }
            } else {
                if (pq.empty()) {
                    return "";
                }

                pair<int, char> sTop = pq.top(); pq.pop();
                res += sTop.second;
                sTop.first--;
                if (sTop.first > 0) {
                    pq.push(sTop);
                }
                pq.push(top);
            }
        }

        return res;
    }
};