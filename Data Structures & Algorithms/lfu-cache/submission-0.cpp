
class LFUCache {
    struct Node{
     int key, value, cnt;
     Node* next, *prev;
     Node(int k, int v) : key(k), value(v), cnt(1), next(nullptr), prev(nullptr) {}
    };

    struct List{
        Node* head, *tail;
        int size;
        List()
        {
            head = new Node(0,0);
            tail = new Node(0,0);
            size =0;

            head->next = tail;
            tail->prev = head;
        }
        void AddFront(Node* node)
        {
            node->next = head->next;
            node->prev =head;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        void deleteNode(Node* node)
        {
            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            prevNode->next = node->next;
            nextNode->prev = node->prev;

            size--;
        }
    };

    int capacity;
    int minfreq;
    int currSize;

    unordered_map<int, List*> freqlist; // freq list map
    unordered_map<int, Node*> keyNode; // Key Node map


public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minfreq = 0;
        
    }

    void updateTheFreqList(Node* node)
    {
        keyNode.erase(node->key);
        freqlist[node->cnt]->deleteNode(node);
        if(node->cnt == minfreq && freqlist[node->cnt]->size ==0)
        {
            minfreq++;
        }

        List* nextHigherList = new List();
        if(freqlist.find(node->cnt +1) != freqlist.end())
        {
            nextHigherList = freqlist[node->cnt+1];
        }
         
         node->cnt  +=1;
         nextHigherList->AddFront(node);
         freqlist[node->cnt] = nextHigherList;
         keyNode[node->key] = node;
    }

    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            int val = node->value;
            updateTheFreqList(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // check capacity is 0
        if(capacity == 0) return;

        // check the key is already present
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node = keyNode[key];
            node->value = value;
            updateTheFreqList(node);
        }
        // check cacpcity is full, erase last node
        else
        {
            if(currSize == capacity)
            {
               List* list = freqlist[minfreq];
               keyNode.erase(list->tail->prev->key);
               freqlist[minfreq]->deleteNode(list->tail->prev);
               currSize--;
            }
            
            // add new Node with minFreq 1
            currSize++;
            Node* node = new Node(key, value);
            List* list = new List();
            minfreq=1;
            if(freqlist.find(minfreq) != freqlist.end())
            {
                list = freqlist[minfreq];
            }
            list->AddFront(node);
            keyNode[key] = node;
            freqlist[minfreq] = list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */