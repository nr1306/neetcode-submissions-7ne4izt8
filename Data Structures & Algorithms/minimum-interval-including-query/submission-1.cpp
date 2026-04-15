class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        /* Brute force will take time O(N*Q) 
        N is size of number of intervals
        Q is the size of queries

        We can optimize it to log complexity, if we sort both intervals and queries
        So, first we'll store the original location of queries index in order to not to mess up the order, we want to return answer in
        */
        int N = intervals.size();
        int Q = queries.size();
        map<int,vector<int>> queryPos;
        for(int i=0; i<Q; i++){
            queryPos[queries[i]].push_back(i);
        }

        sort(intervals.begin(),intervals.end());
        sort(queries.begin(), queries.end());

        // We'll use minheap inorder to retrieve smallest length interval first in O(1)
        priority_queue<
            pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>> 
        > minheap;

        // we'll go throught the queries, and we'll go through the intervals, and find out every interval the query belongs then we'll fetch root element from heap and it will be the smallest length interval for the query
        // To check whether this query belong to the interval we'll compare it with the start time of that interval
        // While fetching the resutlt from the heap for the minimum length of interval, we are also going to store endtime with length of interval, so we'll check whether this query is <= endtime of that interval to be sure that this interval contain this query

        vector<int> res(Q,-1);
        for(int i=0,j=0; i<Q; i++){
            int q = queries[i];
          
            while(j<N && q >= intervals[j][0]){
                int start = intervals[j][0];
                int end = intervals[j][1];
                minheap.push({end-start+1 , end});
                j++;
            }
            
    // After storing all the intervals q query can lie between 
    // we'll check the minheap now for the min interval length, 
    // also will check the preinserted interval whether that interval is valid or not 
    // For the current query by checking it with its endtime

            while(!minheap.empty()){
                pair<int,int> timePair = minheap.top();
                if(q <= timePair.second){
                    vector<int> ind = queryPos[q]; // correct pos of query q
                    if(ind.size() == 1)
                        res[ind[0]] = minheap.top().first;  // length of min interval
                    else{
                        for(int index : ind)
                            res[index] = minheap.top().first;
                    }
                    break;
                }
                minheap.pop(); // coz it won't help us for future queries as well
            }
        }
        return res;
    }
};
