class LRUCache {
public:
    struct Node{
        int key = -1;
        int val = -1;
        Node* next;
        Node* prev;

        Node(){
            next = nullptr;
            prev = nullptr;
        }
    };
    
    Node* head;
    Node* tail;
    map<int, Node*> mp;
    int size;

    LRUCache(int capacity) {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node* node){
        Node *latest = head->next;
        head->next = node;
        latest->prev = node;
        node->prev = head;
        node->next = latest;

        mp[node->key] = node;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* afterNode = node->next; 
        prevNode->next = afterNode;
        afterNode->prev = prevNode; 
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;   
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
        }

        Node* node = new Node();
        node->key = key;
        node->val = value;
        insertAfterHead(node);

        if(mp.size() > size){
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */