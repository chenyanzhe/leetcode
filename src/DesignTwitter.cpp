#include "DesignTwitter.hpp"

Twitter::Twitter() : ts(0) {}

void Twitter::postTweet(int userId, int tweetId) {
    tweets[userId].emplace_front(tweetId, ts++);
}

vector<int> Twitter::getNewsFeed(int userId) {
    vector<int> ret;
    FeedQ fq;
    for (auto fo : followers[userId]) {
        if (!tweets[fo].empty())
            fq.push({tweets[fo].begin(), tweets[fo].end()});
    }
    if (!tweets[userId].empty())
        fq.push({tweets[userId].begin(), tweets[userId].end()});

    while (!fq.empty() && ret.size() < 10) {
        FeedType t = fq.top();
        fq.pop();
        ret.push_back(t.cur->tweetId);
        auto nextIter = next(t.cur);
        if (nextIter != t.end)
            fq.push({nextIter, t.end});
    }

    return ret;
}

void Twitter::follow(int followerId, int followeeId) {
    if (followerId != followeeId)
        followers[followerId].insert(followeeId);
}

void Twitter::unfollow(int followerId, int followeeId) {
    if (followerId != followeeId && followers[followerId].count(followeeId))
        followers[followerId].erase(followeeId);
}