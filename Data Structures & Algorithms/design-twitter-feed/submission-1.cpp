#include <ranges>

struct Tweet {
    int tweetId;
    int time;

    Tweet(int tweetId, int time)
        : tweetId(tweetId), time(time) {}
};

class Twitter {
public:
    Twitter() = default;

    void postTweet(int userId, int tweetId) {
        m_Tweets[userId].push_back(Tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId) {
        std::function<bool(Tweet&, Tweet&)> cmp = [](Tweet& t1, Tweet& t2) -> bool {
            return t1.time > t2.time; };
        std::priority_queue<Tweet, std::vector<Tweet>, decltype(cmp)> feed(cmp);

        m_UserBase[userId].insert(userId);
        for (int followeeId : m_UserBase[userId]) {
            for (Tweet tweet : m_Tweets[followeeId] | std::views::reverse | std::views::take(10)) {
                feed.push(tweet);
                if (feed.size() > 10)
                    feed.pop();
            }
        }

        std::vector<int> feedVector;
        while (!feed.empty()) {
            feedVector.push_back(feed.top().tweetId);
            feed.pop();
        }
        std::reverse(feedVector.begin(), feedVector.end());
        return feedVector;
    }

    void follow(int followerId, int followeeId) {
        m_UserBase[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        m_UserBase[followerId].erase(followeeId);
    }

private:
    std::unordered_map<int, std::unordered_set<int>> m_UserBase;
    std::unordered_map<int, std::vector<Tweet>> m_Tweets;
    int time = 0;
};
