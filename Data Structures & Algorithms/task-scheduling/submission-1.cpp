class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>> mostFreq;
        queue<pair<int,int>> cooldown;
        vector<int> freq(26,0);
        // storing the freq of tasks
        for(int i=0; i<tasks.size(); i++) freq[tasks[i]-'A']++;
        // Inserting tasks whose freq is positive
        for(int i=0; i<26; i++){
            if(freq[i])
                mostFreq.push({freq[i],0});
        }
        
        int time = 0;
        while(!mostFreq.empty() || !cooldown.empty()){
            if(!cooldown.empty() && ((time - cooldown.front().second) > n)){
                pair<int,int> ele = cooldown.front();
                cooldown.pop();
                mostFreq.push(ele);
            }
            if(!mostFreq.empty()){
                pair<int,int> frequent = mostFreq.top();
                mostFreq.pop();
                if(frequent.first-1 > 0)
                    cooldown.push({frequent.first-1, time});
            }
            time++;
        }
        return time;

    }
};
