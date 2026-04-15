
class LRUCache {
public:
    struct ListNode{
        ListNode* next;
        ListNode* prev;
        int val;
        int key;

        ListNode(){
            key = -1;
            val = -1;
            next = nullptr;
            prev = nullptr;
        }
    };

    ListNode* head, *tail;
    int size;
    map<int, ListNode*> mp;

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
        latest->prev = node;
        node->next = latest;

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

        ListNode* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
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
