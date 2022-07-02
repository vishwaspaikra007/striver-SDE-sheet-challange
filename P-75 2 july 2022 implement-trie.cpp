// striver SDE sheet challange implement-trie
// author Vishwas Paikra
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct trie {
    trie *hash[26];
    bool isEndOfWord = false;
};
class Trie {
   struct trie *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new trie();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        struct trie *curr = root;
        for(char a: word) {
            if(!curr->hash[a-'a']) {
                curr->hash[a-'a'] = new trie();
            }
            curr = curr->hash[a-'a'];
        }
        curr->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct trie *curr = root;
        for(char a: word) {
            if(!curr->hash[a-'a']) {
                return false;
            }
            curr = curr->hash[a-'a'];
        }
        return curr->isEndOfWord == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct trie *curr = root;
        for(char a: prefix) {
            if(!curr->hash[a-'a']) {
                return false;
            }
            curr = curr->hash[a-'a'];
        }
        return true;
    }
};
