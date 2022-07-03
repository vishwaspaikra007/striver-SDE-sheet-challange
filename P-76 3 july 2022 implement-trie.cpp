// striver SDE sheet challange implement-trie
// author Vishwas Paikra
struct trie {
    trie *arr[26];
    int wordCount = 0;
    int wordsStartedWith = 0;
};
class Trie{
    trie *root;
    public:

    Trie(){
        root = new trie();
    }

    void insert(string &word){
        trie *curr = root;
        for(char c: word) {
            if(!curr->arr[c-'a'])
                curr->arr[c-'a'] = new trie;
            curr = curr->arr[c-'a'];
            ++curr->wordsStartedWith;
        }
        ++curr->wordCount;
    }

    int countWordsEqualTo(string &word){
        trie *curr = root;
        for(char c: word) {
            if(!curr->arr[c-'a'])
                curr->arr[c-'a'] = new trie;
            curr = curr->arr[c-'a'];
        }
        return curr->wordCount;
    }

    int countWordsStartingWith(string &word){
        trie *curr = root;
        for(char c: word) {
            if(!curr->arr[c-'a'])
                curr->arr[c-'a'] = new trie;
            curr = curr->arr[c-'a'];
        }
        return curr->wordsStartedWith;
    }

    void erase(string &word){
        trie *curr = root;
        for(char c: word) {
            if(!curr->arr[c-'a'])
                curr->arr[c-'a'] = new trie;
            curr = curr->arr[c-'a'];
            if(curr->wordsStartedWith > 0) 
                --curr->wordsStartedWith;
        }
        if(curr->wordCount > 0) --curr->wordCount;
    }
};
