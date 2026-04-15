class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words (wordList.begin(), wordList.end());
        words.erase(beginWord); // coz we have already queued this word

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == endWord) return steps;

            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(words.find(word) != words.end()){
                        words.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
