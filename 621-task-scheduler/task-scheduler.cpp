class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        vector<int> c(26);

        for(int i=0;i<tasks.size();++i) {
            ++c[tasks[i]-'A'];
        }
        for(int i=0;i<26;++i) {
            if(c[i]) {
                pq.push(c[i]);
            }
        }

        int res=0;
        while(!q.empty() || !pq.empty()) {
            res++;
            if(!pq.empty()) {
                if (pq.top()-1) {
                    q.push({pq.top()-1, res+n});
                }
                pq.pop();
            }
            if(!q.empty() && q.front().second == res) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return res;
    }
};