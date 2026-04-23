class MyHashMap {
    private:
    vector<vector<pair<int,int>>> bucket;
    int size;

    int hash(int key)
    {
        return key % size;
    }

public:
    MyHashMap() {
        size = 1000;
        bucket.resize(size);
    }
    
    void put(int key, int value) {
        int idx = hash(key);

        for(auto &p :  bucket[idx])
        {
            if(p.first == key)
            {
                p.second = value;
                return;
            }
        }

        bucket[idx].push_back({key, value});
    }
    
    int get(int key) {
         int idx = hash(key);
       
        for(auto &p : bucket[idx])
        {
            if(p.first == key)
                return p.second;
        }
        
        return -1;
    }
    
    void remove(int key) {
         int idx = hash(key);
         for(int i=0;i<bucket[idx].size();i++)
         {
            if(bucket[idx][i].first == key)
            {
             bucket[idx].erase(bucket[idx].begin()+i);
             return;
            }
         }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */