class Node{
public:
    vector<Node*> children;
    bool end;

    Node(){
        children.resize(26, NULL);
        end= false;
    }
};

bool searchHelper(Node* ptr, int i, string& word){
    if(i==word.size()) return ptr->end;
    if(!ptr) return false; 

    if(word[i]!='.'){
        if(ptr->children[word[i]-'a']==NULL) return false;
        return searchHelper(ptr->children[word[i]-'a'], i+1, word);
        }else{
        bool result= false;
        for(int ch=0; ch<26; ch++){
            if(ptr->children[ch]==NULL) continue;
            else result= searchHelper(ptr->children[ch], i+1, word);
            if(result) return result;
        }
        return result;
    }
}

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root= new Node();
    }
    
    void addWord(string word) {
        Node* ptr = root;
        for(char ch: word){
            if(!ptr->children[ch-'a']) ptr->children[ch-'a']= new Node();
            ptr=ptr->children[ch-'a'];
        }
        ptr->end= true;
    }
    
    bool search(string word) {
        return searchHelper(root, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */