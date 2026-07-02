class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> hash;
      vector<pair<int, int>> ans;
      vector<int> result;

      for(int i=0; i<nums.size(); i++){
        hash[nums[i]]++;
      }

      for(auto it:hash){
        ans.push_back({it.second, it.first});
      }

      sort(ans.rbegin(), ans.rend());

      for(int i =0; i<k; i++){
        result.push_back(ans[i].second);
      }
      return result;
        
    }
};
