class Twitter {
public:
    map<int, set<int>> following; // user's followee
    map<int, vector<pair<int,int>>> tweets; // It will map user to his tweets along with timestamps
    
    struct Comparator{
        bool operator() (pair<int, int>& a, pair<int,int>& b){
            return a.second > b.second; // This will create minheap REMEMBER
        }
    };
    
    int timestamp;
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId,timestamp});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        Comparator> minheap;
    // checking the tweets of Id user follows
        for(int followeeId : following[userId]){
            for(auto tweetPair : tweets[followeeId]){
                minheap.push(tweetPair);
                if(minheap.size() > 10) minheap.pop();
            }
        }

    // Then checking the timestamps of user's own tweets
        for(auto tweetPair : tweets[userId]){
            minheap.push(tweetPair);
            cout << minheap.top().first << " " << minheap.top().second << endl;
            if(minheap.size() > 10) minheap.pop();
        }

    // Now heap contains 10 most recent tweets among his followees and its own
        vector<int> mostRecentTweets; // This will store the recent 10 tweets but in reverse order of timestamps
        while(!minheap.empty()){
            auto tweetPair = minheap.top();
            mostRecentTweets.push_back(tweetPair.first);
            minheap.pop();
        }
        reverse(mostRecentTweets.begin(), mostRecentTweets.end());
        return mostRecentTweets;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].erase(followeeId);
    }
};
