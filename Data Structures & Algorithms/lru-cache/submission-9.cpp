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

    }*head, *tail;

    map<int, ListNode*> mp;
    int size;

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
        ListNode* after = node->next;
        ListNode* before = node->prev;
        before->next = after;
        after->prev = before;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        ListNode* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
        }

        ListNode* node = new ListNode();
        node->key = key;
        node->val = value;
        insertAfterHead(node);

        if(mp.size() > size){
            ListNode* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete(lru);
        }
    }
};
