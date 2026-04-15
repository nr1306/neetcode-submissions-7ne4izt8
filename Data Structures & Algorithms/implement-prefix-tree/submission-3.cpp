class PrefixTree {
    struct Trie{
        Trie *ch[26];
        string word;
    };

    Trie* root = new Trie();

public:

    PrefixTree() {
        for(int i=0; i<26; i++)
            root->ch[i] = nullptr;
        root->word = "";
    }
    
    void insert(string word) {
        Trie* curr = root;
        for(char alph : word){
            if(!curr->ch[alph-'a']){
                curr->ch[alph-'a'] = new Trie();
            }
            curr = curr->ch[alph-'a'];
        }
        curr->word = word;
    }
    
    bool search(string word) {
        Trie* curr = root;
        for(char alph : word){
            if(!curr->ch[alph-'a']) return false;
            
            curr = curr->ch[alph-'a'];
            if(curr->word == word) return true; // If we found a node where the word is stored
        }
        return false; // If we are looking for apps, and word stored is appss and apps is not stored then also will return false
    }
    
    bool startsWith(string prefix) {
        Trie* curr = root;
        for(char alph : prefix){
            if(!curr->ch[alph-'a']) return false;
            
            curr = curr->ch[alph-'a']; // will traverse until we found all the alph of prefix word we are looking no matter whether it is the whole word or not
        }
        return true;
    }
};
