struct Trie{
    Trie* ch[26];
    string word = "";

    Trie(){
        for(int i=0; i<26; i++) ch[i] = nullptr;
    }
};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* temp = root;
        for(int i=0; i<word.size(); i++){
            char letter = word[i];
// If letter does not exists in Trie we'll create a new reference for that letter
            if(temp->ch[letter-'a'] == nullptr)
                temp->ch[letter-'a'] = new Trie();
            
            // move to next reference
            temp = temp->ch[letter-'a'];
        }
        temp->word = word;
    }

    bool dfs(Trie* temp, string word, int i){
        if(i == word.size()){
            if(temp->word.size()) return true;
            else return false;
        } 
        

        if(word[i] == '.'){
            for(int j=0; j<26; j++){
                if(temp->ch[j] != nullptr && dfs(temp->ch[j], word, i+1)){
                    return true;
                }
            }
            return false;
        }
        else if(temp->ch[word[i]-'a']){
            return  dfs(temp->ch[word[i]-'a'], word, i+1);
        }
        else return false;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
