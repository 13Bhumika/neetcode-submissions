class Solution {
    private:
    vector<int> Sum(vector<int>&arr,int target){
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]+arr[j]==target){
                     return {i,j};
                }
            }
        }
        return {};
    }
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>hash_map;
        for(int i=0;i<arr.size();i++){
            int num=arr[i];
            int comp=target-num;
            if(hash_map.find(comp)!=hash_map.end()){
                return {hash_map[comp],i};
            }
            hash_map[num]=i;
        }
        return {};
    }
};