class LFUCache {
public:

    struct ListNode{
        ListNode* next;
        ListNode* prev;
        int key;
        int val;
        int freq;

        ListNode(int key, int val) : key(key), val(val), freq(1),
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
            ListNode* prev = node->prev;
            ListNode* next = node->next;
            prev->next = next;
            next->prev = prev;
            node->prev = nullptr;
            node->next = nullptr;
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

    unordered_map<int , ListNode*> nodeMap; // key -> Node
    unordered_map<int, LinkedList*> listMap; // Freq -> Linked List

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


    LFUCache(int capacity) : capacity (capacity) , lfucount(0){}

    ~LFUCache() {
        for (auto& pair : nodeMap) {
            delete pair.second;
        }
        for (auto& pair : listMap) {
            delete pair.second;
        }
    }

    
    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end()) return -1;

        ListNode* node = nodeMap[key];
        counter(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

// If key is already present - will just update node's value and update the counter and return

        if(nodeMap.find(key) != nodeMap.end()){
            ListNode* node = nodeMap[key];
            node->val = value;
            counter(node);

            return;
        }

// If key is not present in the map - will check if capacity is reached or not - if it does - will fetch lru node with the help of lfucount from listMap and pop the left most node

        if(nodeMap.size() == capacity){
            ListNode* lfu = listMap[lfucount]->popLeft();
            nodeMap.erase(lfu->key);
            delete lfu;
        }

// After removing lfu - will create the new node - insert it in nodeMap

        ListNode* node = new ListNode(key,value);
        nodeMap[key] = node;

// And will check if in listMap - if linkedList is not created for freq 1 - will create a linkedList  and push the new node to the right in that

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