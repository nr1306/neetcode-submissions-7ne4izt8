class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>> mostFreq;
        queue<pair<int,int>> cooldown;
        vector<int> freq(26,0);
        // storing the freq of tasks
        for(int i=0; i<tasks.size(); i++) freq[tasks[i]-'A']++;
        // Inserting tasks whose freq is positive
        for(int i=0; i<26; i++)
            if(freq[i]) mostFreq.push({freq[i],0});
        
        int time = 0;
        while(mostFreq.size() || cooldown.size()){
            time++;
            // we'll remove ele from queue when its cooldown period of task  is completed, and if cooldown is not over for first task no need to check rest of tasks in queue coz they got inserted later
            if(cooldown.size() && time - cooldown.front().second > n){
                pair<int,int> ele = cooldown.front();
                cooldown.pop();
                mostFreq.push(ele);
            }
            if(mostFreq.size()){
                // Taking the most freq task out of heap and put it into cooldown queue
                pair<int,int> frequent = mostFreq.top();
                mostFreq.pop();
                // That makes no sense to reinsert that task if task is completed 
                if(frequent.first-1 > 0)
                cooldown.push({frequent.first-1, time});
            }
        }
        return time;

    }
};
