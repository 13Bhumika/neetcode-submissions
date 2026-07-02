class Node{
public:
    int key;
    int value;

    Node(int key, int value){
        this->key= key;
        this->value= value;
    }
    Node(){
        key=0;
        value=0;
    }
};
class DLL{
public:
    DLL* prev;
    Node data;
    DLL* next;

    DLL(Node data){
        this->data= Node(data.key, data.value);
        next= NULL;
        prev= NULL;
    }
    DLL(){
        next= NULL;
        prev= NULL;
    }

};
class LRUCache {
private:
    unordered_map<int, DLL*>hash;
    int max_cap;
    int curr_size;
    DLL* head;
    DLL* tail;
public:
    LRUCache(int capacity) {
        max_cap= capacity;
        curr_size=0;
        head= new DLL();
        tail= new DLL();

        head->next=tail;
        tail->prev=head;
    }
    void moveToFront(DLL* node){
        DLL *node_next= node->next;
        DLL *node_prev= node->prev;

        node_prev->next= node->next;
        node_next->prev= node->prev;

        DLL *tail_prev= tail->prev;
        tail_prev->next= node;
        node->prev= tail_prev;
        tail->prev= node;
        node->next= tail;
    }
    void removeLeastNode() {
        DLL* node = head->next;

        DLL* node_next = node->next;
        DLL* node_prev = node->prev;

        node_prev->next = node_next;
        node_next->prev = node_prev;

        
        hash.erase(node->data.key);

        delete node;
    }

    int get(int key) {
        if(hash.find(key)== hash.end()) return -1;
        else{
            moveToFront(hash[key]);
            return hash[key]->data.value;
        }
    }
    
    void put(int key, int value) {
        if(hash.find(key)!= hash.end()){
            hash[key]->data.value= value;
            moveToFront(hash[key]);
            return;
        }
        if(curr_size==max_cap){
            removeLeastNode();
            curr_size--;
        }
        DLL *node= new DLL(Node(key, value));
        hash[key]=node;

        DLL* tail_prev = tail->prev;
        tail_prev->next = node;
        node->prev = tail_prev;
        tail->prev = node;
        node->next = tail;

        curr_size ++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */