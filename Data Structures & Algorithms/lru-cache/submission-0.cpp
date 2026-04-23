class LRUCache {
private:
struct Node{
    int key, value;
    Node* prev, *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

Node* head;
Node* tail;
int capacity;
unordered_map<int, Node*> cache;

void addAtBegin(Node* node)
{
    node->prev = head;
    node->next = head->next;
    
    head->next->prev = node;
    head->next = node;
}

void removeNode(Node* node)
{
    Node* prev = node->prev;
    Node* next = node->next;

    prev->next = next;
    next->prev = prev;
}

void moveTohead(Node* node)
{
    removeNode(node);
    addAtBegin(node);
}

Node* removeLast()
{
    Node* node = tail->prev;
    removeNode(node);
    return node;
}


public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;

        Node* node = cache[key];
        moveTohead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            Node* node = cache[key];
            node->value = value;
            moveTohead(node);
        }
        else
        {
            Node* node = new Node(key, value);
            cache[key] = node;
            addAtBegin(node);

            if(cache.size() > capacity)
            {
              Node* tailNode = removeLast();
              cache.erase(tailNode->key);
              delete tailNode; 
            }
        }
    }
};
