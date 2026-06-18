#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
    private:
        int timeStamp; //track time each tweet sent at with global counter
        unordered_map<int, unordered_set<int>> followingMap; //check who is following who
        unordered_map<int, vector<pair<int, int>>> AllTweets; //all related tweets for a person is stored in a vector of pairs, we deal 
        //with the top 10 most recent wtihin getNewsFeed
public:
    Twitter() {
        timeStamp = 0;
       
    }
    
    void postTweet(int userId, int tweetId) {
        AllTweets[userId].push_back({timeStamp++, tweetId}); //push pair storing timestamp and tweetID into AllTweets
    }
    
    vector<int> getNewsFeed(int userId) {
    std::priority_queue<pair<int, int>> pq; //maxHeap, largest .first (most recent) will show up

    for(const auto twt : AllTweets[userId]){
        pq.push(twt); //push all usertTweets
    }

    for(auto followee : followingMap[userId]){
        for(const auto twt : AllTweets[followee])
        pq.push(twt); //push all tweets from followees into the pq
    }

    vector<int> res;
    while(!pq.empty() && res.size() < 10){
        int currID = pq.top().second; //until top 10 found, push currIDs onto the vector
        pq.pop();
        res.push_back(currID);
    }
    return res;

    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followingMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followingMap[followerId].erase(followeeId);
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
// @lc code=end

