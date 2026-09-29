class WordDictionary {
public:
    struct Trie{
        Trie* ch[26];
        bool isWord;

        Trie(){
            for(int i=0; i<26; i++)
                ch[i] = nullptr;
            isWord = false;
        }
    }*trie;

    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        Trie* node = trie;
        for(char c : word){
            if(!node->ch[c-'a'])
                node->ch[c-'a'] = new Trie();
            
            node = node->ch[c-'a'];
        }
        node->isWord = true;
    }
    
    bool solve(string word, Trie* node, int i){
        if(i == word.size()){
            return node->isWord;
        }
        char c = word[i];

        if(c == '.'){
            for(int j=0; j<26; j++){
                if(node->ch[j] && solve(word,node->ch[j],i+1))
                    return true;
            }
            return false;
        }
        
        if(!node->ch[c-'a']) return false;

        return solve(word,node->ch[c-'a'],i+1);
        
    }
    
    bool search(string word) {
        return solve(word,trie,0);
    }

};
