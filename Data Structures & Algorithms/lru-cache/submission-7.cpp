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
    
    int size;
    map<int,ListNode*> mp; 

    LRUCache(int capacity) {
        size = capacity;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
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
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        ListNode* ans = mp[key];
        deleteNode(ans);
        insertAfterHead(ans);
        return ans->val;
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
