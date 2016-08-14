#ifndef DESIGN_TWITTER_HPP_
#define DESIGN_TWITTER_HPP_

#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter();

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId);

    /** Retrieve the 10 most recent tweet ids in the user's news feed.
     *  Each item in the news feed must be posted by users who the user followed or by the user herself.
     *  Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId);

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId);

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId);

private:
    struct TweetType {
        int tweetId;
        int ts;

        TweetType(int tweetId, int ts) : tweetId(tweetId), ts(ts) {}
    };

    typedef list<TweetType>::iterator TweetIter;

    struct FeedType {
        TweetIter cur;
        TweetIter end;
    };

    struct OrderByTS {
        bool operator()(const FeedType &a, const FeedType &b) {
            return a.cur->ts < b.cur->ts;
        }
    };

    typedef priority_queue<FeedType, vector<FeedType>, OrderByTS> FeedQ;

    unordered_map<int, list<TweetType>> tweets;

    unordered_map<int, unordered_set<int>> followers;

    int ts;
};

#endif // DESIGN_TWITTER_HPP_