class Twitter {
public:
    map<int, vector<pair<int,int>> > tweets;
    map<int, set<int>> follower;
    int timestamp;

    struct Comparator{
        bool operator() (pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        }
    };

    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timestamp});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, 
        Comparator> minheap;

    // Here we covered all the tweets of followees, user is following
        for(int followeeId : follower[userId]){
            for(pair<int,int> tweet : tweets[followeeId]){
                minheap.push(tweet);
                if(minheap.size()>10) minheap.pop();
            }
        }

    // Now we will also cover user's tweets
        for(pair<int,int> tweet : tweets[userId]){
            minheap.push(tweet);
            if(minheap.size()>10) minheap.pop();
        }

        vector<int> mostRecentFeed;

        while(!minheap.empty()){
            pair<int,int> tweet = minheap.top();
            minheap.pop();
            mostRecentFeed.insert(mostRecentFeed.begin(),tweet.first);
        }

        return mostRecentFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follower[followerId].erase(followeeId);
    }
};
