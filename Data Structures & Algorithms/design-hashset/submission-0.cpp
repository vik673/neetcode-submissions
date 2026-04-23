class MyHashSet {
      int size;
      vector<vector<int>> bucket;

      int hash(int key)
      {
        return key%size;
      }

public:
    MyHashSet() {
        size = 1000;
        bucket.resize(size);
    }
    
    void add(int key) {
        int idx = hash(key);
        for(int val : bucket[idx])
        {
            if(val == key) return;
        }
        bucket[idx].push_back(key);
    }
    
    void remove(int key) {
         int idx = hash(key);
         for(int i=0;i<bucket[idx].size();i++)
         {
            if(bucket[idx][i]==key)
            {
                bucket[idx].erase(bucket[idx].begin()+i);
                return;
            }
         }
    }
    
    bool contains(int key) {
        int idx = hash(key);

        for(int val : bucket[idx])
        {
           if(val == key) return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */