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

// When we encounter the word and that word is equal to the word we are looking for
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

// When we reach to the last char of the prefix word no matter that word is there in Trie or not
            if(i == prefix.size()-1){
                return true;
            }
        }
        return false;
    }
};
