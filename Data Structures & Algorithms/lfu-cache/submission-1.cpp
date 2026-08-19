class LFUCache {
    struct ListNode{
        ListNode* next;
        ListNode* prev;
        int key;
        int val;
        int freq;

        ListNode(int key, int value) : key(key), val(value), freq(1),
        prev(nullptr), next(nullptr) {}
    };

    struct LinkedList{
        ListNode* left;
        ListNode* right;
        int size;

        LinkedList(){
            left = new ListNode(0,0);
            right = new ListNode(0,0);
            left->next = right;
            right->prev = left;
            size = 0;
        }

        ~LinkedList(){
            delete(left);
            delete(right);
        }

        int length(){ return size; }

        void pushRight(ListNode* node){
            ListNode* prev = right->prev;
            prev->next = node;
            node->prev = prev;
            node->next = right;
            right->prev = node;
            size++;
        }

        void pop(ListNode* node){
            ListNode* next = node->next;
            ListNode* prev = node->prev;
            prev->next = next;
            next->prev = prev;
            node->next = nullptr;
            node->prev = nullptr;
            size--;
        }

        ListNode* popLeft(){
            ListNode* node = left->next;
            pop(node);
            return node;
        }
    };

    int capacity;
    int lfucount;

    unordered_map<int,ListNode*> nodeMap; // key -> Node
    unordered_map<int, LinkedList*> listMap; // freq -> List

    void counter(ListNode* node){
        int count = node->freq;
        listMap[count]->pop(node);

        if(count == lfucount && listMap[count]->length() == 0)
            lfucount++;
        
        node->freq++;
        if(!listMap.count(node->freq))
            listMap[node->freq] = new LinkedList();
        
        listMap[node->freq]->pushRight(node);
    }

public:

    LFUCache(int capacity) : capacity(capacity), lfucount(0) {}
    
    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end()) return -1;

        ListNode* node = nodeMap[key];
        counter(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(nodeMap.find(key) != nodeMap.end()){
            ListNode* node = nodeMap[key];
            node->val = value;
            counter(node);

            return;
        }

        if(nodeMap.size() == capacity){
            ListNode* toRemove = listMap[lfucount]->popLeft();
            nodeMap.erase(toRemove->key);
            delete(toRemove);
        }

        ListNode* node = new ListNode(key, value);
        nodeMap[key] = node;
        
        if(!listMap.count(1))
            listMap[1] = new LinkedList();
        listMap[1]->pushRight(node);
        lfucount = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */