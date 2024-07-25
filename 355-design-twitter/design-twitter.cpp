class Twitter {
private:
    unordered_map<int, set<int>> userFollowMap;
    stack<pair<int, int>> userTweetMap;
public:
    Twitter() {
        userFollowMap = {};
        userTweetMap = {};
    }
    
    void postTweet(int userId, int tweetId) {
        userTweetMap.push({tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        stack<pair<int, int>> pq = userTweetMap;
        while(!pq.empty() && res.size() < 10) {
            if (pq.top().second == userId || userFollowMap[userId].contains(pq.top().second)) {
                res.push_back(pq.top().first);
            }
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */