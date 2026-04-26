class Tweet
{
    public:
    int time;
    int tweetId;
    Tweet(int t, int id)
    {
        time = t;
        tweetId = id;
    }

   struct cmp {
    bool operator()(Tweet &a, Tweet &b) {
        return a.time < b.time; // max heap
    }
   };
};

class User{
    
    int userId;
    public:
    unordered_set<int> followers;
    list<Tweet> tweets;
    User(int userId) : userId(userId){}
        
     void addtweet(Tweet t)
     {
        tweets.push_front(t); // insertion at the end
     }

     void addFollower(int followeeId)
     {
        followers.insert(followeeId);
     }

     void removeFollower(int followeeId)
     {
        followers.erase(followeeId);
     }

    
};
class Twitter {
   unordered_map<int, User*> userMap;
   priority_queue<Tweet, vector<Tweet>, Tweet::cmp> pq;
   int timeCounter;
public:
    Twitter() {
        timeCounter=0;
    }
    
    void postTweet(int userId, int tweetId) {
        timeCounter++;

        if(userMap.find(userId) == userMap.end())
        {
            userMap[userId]= new User(userId);
        }

        User* user = userMap[userId];
        Tweet   t(timeCounter, tweetId);
        user->addtweet(t);
    }
    
    vector<int> getNewsFeed(int userId) {
      vector<int> result;

    if(userMap.find(userId) == userMap.end())
        return result;

    while(!pq.empty()) pq.pop(); // clear heap

    User* user = userMap[userId];

    // own tweets
    int count = 0;
    for(auto &tweet : user->tweets) {
        pq.push(tweet);
        if(++count == 10) break;
    }

    // following tweets
    for(auto &followeeId : user->followers) { // rename this ideally
     if(followeeId == userId) continue;
        if(userMap.find(followeeId) == userMap.end()) continue;

        count = 0;
        for(auto &tweet : userMap[followeeId]->tweets) {
            pq.push(tweet);
            if(++count == 10) break;
        }
    }

    int index = 0;
    while(!pq.empty() && index < 10) {
        result.push_back(pq.top().tweetId);
        pq.pop();
        index++;
    }

    return result;

    }
    
    void follow(int followerId, int followeeId) {
        if(userMap.find(followerId) == userMap.end())
        {
            userMap[followerId]= new User(followerId);
        }

        if(userMap.find(followeeId) == userMap.end())
        {
            userMap[followeeId]= new User(followeeId);
        }

       User* user = userMap[followerId];
        user->addFollower(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(userMap.find(followerId) == userMap.end()
        || userMap.find(followeeId) == userMap.end())
        {
            return;
        }

       User* user = userMap[followerId];
        user->removeFollower(followeeId);
    }
};
