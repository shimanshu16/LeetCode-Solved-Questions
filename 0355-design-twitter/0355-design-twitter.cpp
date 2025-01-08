class Tweet {
public:
    int time;
    int tweet_id;
    Tweet* next;
    Tweet* prev;
    Tweet(int t, int i) : time(t), tweet_id(i), next(nullptr), prev(nullptr) {}
};
class TweetList {
public:
    Tweet* head;
    Tweet* tail;
    int size;
    TweetList() : size(0) {
        head = new Tweet(-1, -1);
        tail = new Tweet(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void addTweet(Tweet* node) {
        if (size == 10) {
            Tweet* t = tail->prev;
            t->prev->next = tail;
            tail->prev = t->prev;
            delete t;
            --size;
        }
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        ++size;
    }
};
class User {
public:
    int user_id;
    unordered_set<User*> followList;
    TweetList* tweets;
    User(int i) : user_id(i) { tweets = new TweetList(); }
};
struct compare {
    bool operator()(Tweet* t1, Tweet* t2) { return t1->time < t2->time; }
};
class Twitter {
    int timeStamp;
    unordered_map<int, User*> users;
    void validateUserId(int& userId) {
        if (users.find(userId) == users.end())
            users.insert({userId, new User(userId)});
    }

public:
    Twitter() : timeStamp(0) {}

    void postTweet(int userId, int tweetId) {
        validateUserId(userId);
        users[userId]->tweets->addTweet(new Tweet(timeStamp++, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        validateUserId(userId);
        priority_queue<Tweet*, vector<Tweet*>, compare> pq;
        if (users[userId]->tweets->size != 0)
            pq.push(users[userId]->tweets->head->next);
        for (auto& x : users[userId]->followList)
            if (x->tweets->size != 0)
                pq.push(x->tweets->head->next);
        if (pq.empty())
            return {};
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            Tweet* t = pq.top();
            ans.push_back(t->tweet_id);
            pq.pop();
            if (t->next->time != -1)
                pq.push(t->next);
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        validateUserId(followerId);
        validateUserId(followeeId);
        if (followerId != followeeId)
            users[followerId]->followList.insert(users[followeeId]);
    }

    void unfollow(int followerId, int followeeId) {
        validateUserId(followerId);
        validateUserId(followeeId);
        if (followerId != followeeId)
            users[followerId]->followList.erase(users[followeeId]);
    }
};