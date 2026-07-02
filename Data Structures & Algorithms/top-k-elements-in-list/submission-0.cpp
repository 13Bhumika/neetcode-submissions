class Solution {
private:
    vector<int> result(vector<int>&nums, int k){
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        vector<pair<int,int>> frequency;
        for(auto it: hash){
            int key=it.first;
            int value=it.second;
            frequency.push_back({value,key});
        }
        sort(frequency.begin(),frequency.end()); 
        vector<int> answer;

        for(int i=frequency.size()-1; i>=0;i--){
            answer.push_back(frequency[i].second);
            if(answer.size()==k) break;
        }       
        return answer;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return result(nums,k);
        
    }
};