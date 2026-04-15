class FreqStack {
    priority_queue<vector<int>> heap;
    map<int,int> freq;
    int index; // we took the index coz if the freq is smae then the element will be stored in heap based on val of index, that we are asked in ques
public:
    FreqStack() {
        index = 0;
    }
    
    void push(int val) {
        freq[val]++;
        heap.push({freq[val], index++, val});
    }
    
    int pop() {
        vector<int> ele = heap.top();
        heap.pop();
        int val = ele[2];
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */