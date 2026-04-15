class LRUCache {
public:
    struct ListNode{
        ListNode* next;
        ListNode* prev;
        int key;
        int val;

        ListNode(){
            next = nullptr;
            prev = nullptr;
            key = -1;
            val = -1;
        }

    }* head, *tail;

    int size;
    map<int,ListNode*> mp;

    LRUCache(int capacity) {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }

    void insertAfterHead(ListNode* node){
        ListNode* latest = head->next;
        head->next = node;
        node->prev = head;
        node->next = latest;
        latest->prev = node;

        mp[node->key] = node;
    }

    void deleteNode(ListNode* node){
        ListNode* before = node->prev;
        ListNode* after = node->next;
        before->next = after;
        after->prev = before;
    }
    
    int get(int key){
        if(mp.find(key) == mp.end()) return -1;

        ListNode* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            ListNode* node = mp[key];
            deleteNode(node);
        }

        ListNode* newNode = new ListNode();
        newNode->key = key;
        newNode->val = value;
        insertAfterHead(newNode);
        

        if(mp.size() > size){
            ListNode* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete(lru);
        }
    }
};
