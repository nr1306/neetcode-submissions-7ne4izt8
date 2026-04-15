class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;
        for(char task : tasks){
            freq[task]++;
        }

        priority_queue< pair<int,int> > maxheap;
        for(auto itr : freq){
            maxheap.push({itr.second, 0});
        }

        queue<pair<int,int>> cooldown;
        int time = 0;

        while(maxheap.size() || cooldown.size()){
            time++;

            if(cooldown.size()){
                if(time-cooldown.front().second > n){
                    pair<int,int> task = cooldown.front();
                    cooldown.pop();
                    maxheap.push(task);
                }
            }
            if(maxheap.size()){
                pair<int,int> task = maxheap.top();
                maxheap.pop();
                if(task.first-1 > 0) // if it is not last task
                    cooldown.push({task.first-1, time});
            }
        }

        return time;
    }
};
