class Node{
public:
    vector<Node*> children;
    bool end;

    Node(){
        children.resize(26, NULL);
        end= false;
    }
};
class PrefixTree{
public:
    Node* root;

    PrefixTree() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* ptr= root;
        for(char ch: word){
            if(!ptr->children[ch-'a']) ptr->children[ch-'a']= new Node();
            ptr= ptr->children[ch-'a'];
        }
        ptr->end=true;
    }
    
    bool search(string word) {
        Node* ptr= root;
        for(char ch: word){
            if(!ptr->children[ch-'a']) return false;
            else ptr=ptr->children[ch-'a'];
        }
        if(ptr->end==true) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node* ptr= root;
        for(char ch: prefix){
            if(!ptr->children[ch-'a']) return false;
            else ptr=ptr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */