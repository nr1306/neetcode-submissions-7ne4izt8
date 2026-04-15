class WordDictionary {
    struct Trie{
        Trie* ch[26];
        string word;

        Trie(){
            for(int i=0; i<26; i++)
                ch[i] = nullptr;
            word = "";    
        }
    }*root;

public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(char alph : word){
            if(!curr->ch[alph-'a']) 
                curr->ch[alph-'a'] = new Trie();
            curr = curr->ch[alph-'a'];
        }
        curr->word = word;
    }

    bool find(Trie* curr, string word, int i){
        if(i == word.size()){
            if(curr->word.size()) return true;
            return false;
        }

        char alph = word[i];
        if(alph != '.'){
            if(!curr->ch[alph-'a']) return false;
            curr = curr->ch[alph-'a'];
            return find(curr, word, i+1);
        }
        else{
            for(int j=0; j<26; j++){
                if(curr->ch[j]){
                    if(find(curr->ch[j], word, i+1))
                        return true;
                }
            }
            return false;
        }
        
        return false;
    }
    
    bool search(string word) {
        return find(root, word, 0);
    }
};
