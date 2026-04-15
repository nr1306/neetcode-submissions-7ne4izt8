struct Trie{
    Trie* ch[26];
    string word;

    Trie(){
        for(int i=0; i<26; i++) ch[i] = nullptr;
        word = "";
    }
};

class PrefixTree {
public:
    Trie* root;

    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie* temp = root;
        for(int i=0; i<word.size(); i++){
            char letter = word[i];
            if(temp->ch[letter-'a'] == nullptr){
                temp->ch[letter-'a'] = new Trie();
            }
            temp = temp->ch[letter-'a'];
        }
        temp->word = word;
    }
    
    bool search(string word) {
        Trie* temp = root;
        for(int i=0; i<word.size(); i++){
            char letter = word[i];
            if(temp->ch[letter-'a'] == nullptr) return false;

            temp = temp->ch[letter-'a']; // move ahead to next letter

            if(temp->word.size() > 0 && temp->word == word){
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* temp = root;
        for(int i=0; i<prefix.size(); i++){
            char letter = prefix[i];
            if(temp->ch[letter-'a'] == nullptr) return false;

            temp = temp->ch[letter-'a']; // move ahead to next letter

            if(i == prefix.size()-1){
                return true;
            }
        }
        return false;
    }
};
