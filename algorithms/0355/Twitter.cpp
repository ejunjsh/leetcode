class Twitter {
public:
    Twitter():time(0){};
    
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto id : friends[userId]) {
            for (auto a : tweets[id]) {
                if (q.size() > 0 && q.top().first > a.first && q.size() > 10) break;
                q.push(a);
                if (q.size() > 10) q.pop();
            }
        }
        while (!q.empty()) {
            res.insert(res.begin(), q.top().second);
            q.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            friends[followerId].erase(followeeId);
        }
    }
    
private:
    int time;
    unordered_map<int, unordered_set<int>> friends;
    unordered_map<int, vector<pair<int, int>>> tweets;
};