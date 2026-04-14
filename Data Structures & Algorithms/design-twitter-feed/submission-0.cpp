class Twitter {
public:
    map<int, unordered_set<int>> followers;
    vector<pair<int,int>> tweets; //userId, tweetId

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int n = tweets.size();
        vector<int> res;

        //find followees
        unordered_set<int> followees;
        for(auto u: followers)
        {
            if(u.first != userId)
            {
                if(u.second.find(userId) != u.second.end())
                {
                    followees.insert(u.first);
                }
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            int id = tweets[i].first;
            
            //if tweet belongs to user or someone he is following (followee)
            if( id==userId || 
            followees.find(id) != followees.end()
            )
            {
                res.push_back(tweets[i].second);
            }
            if(res.size()==10) {break;}
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followers.find(followeeId) == followers.end()) //not found
        {
            unordered_set<int> s = {followerId};
            followers[followeeId] = s;
        }
        else{ //found
            followers[followeeId].insert(followerId);
        }   
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followeeId].erase(followerId);
    }
};
