class PrefixTree {
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

    PrefixTree() {
        trie = new Trie();
    }
    
    void insert(string word) {
        Trie* node = trie;
        for(char c : word){
            if(!node->ch[c-'a'])
                node->ch[c-'a'] = new Trie();
            node = node->ch[c-'a'];
        }   
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = trie;
        for(char c : word){
            if(!node->ch[c-'a']) return false;

            node = node->ch[c-'a'];
            if(node->isWord) return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* node = trie;
        for(char c : prefix){
            if(!node->ch[c-'a']) return false;

            node = node->ch[c-'a'];
        }
        return true;
    }
};
