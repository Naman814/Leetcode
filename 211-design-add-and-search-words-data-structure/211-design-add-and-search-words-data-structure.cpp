struct TrieNode{
    bool isEnd;
    TrieNode *child[26];

    TrieNode(){
        isEnd = false;
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};

class WordDictionary {
public:
    TrieNode* head = new TrieNode();
    
    void addWord(string word) {
        TrieNode *curr = head;
        for(int i=0; i<word.length(); i++)
        {
            int index = word[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word, int index=0, TrieNode* root=NULL) {
        if(index == 0 && root == NULL)
            root = head;
        if(index == word.length())
            return root->isEnd;
        
        if(word[index] != '.')
        {
            int temp = word[index]-'a';
            if(root->child[temp])
                return search(word, index+1, root->child[temp]);
            return false;
        }
        for(int i=0; i<26; i++)
            if(root->child[i])
                if(search(word, index+1, root->child[i]))
                    return true;
        
        return false;
    }
};