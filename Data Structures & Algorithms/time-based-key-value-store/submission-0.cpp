class Node{
public: 
    string key;
    string value;
    int time_stamp;

    Node(string& key, string& value, int time_stamp){
        this->key=key;
        this->value=value;
        this->time_stamp= time_stamp;
    }
    Node(){
        key="";
        value="";
        time_stamp=0;
    }
};
class TimeMap {
    unordered_map<string,vector<Node>> hash;
public:
    TimeMap() {
        
    }
    string binarySearch(vector<Node> &arr ,int time_stamp){
        int low= 0;
        int high= arr.size()-1;
        string result="";
        while(low<=high){
            int mid= (low+high)/2;
            if(arr[mid].time_stamp<=time_stamp){
                result=arr[mid].value;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return result;
    }

    void set(string key, string value, int timestamp) {
        hash[key].push_back(Node(key, value, timestamp));  
    }
    
    string get(string key, int timestamp) {
        if(hash.find(key)==hash.end()) return "";
        return binarySearch(hash[key],timestamp);    
    }
};