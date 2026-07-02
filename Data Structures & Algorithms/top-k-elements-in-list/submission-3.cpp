class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> hash;
      vector<pair<int, int>> v;
      vector<int> ans;

      for(int i=0; i<nums.size(); i++){
        hash[nums[i]]++;
      }

      for(auto it:hash){
        v.push_back({it.second, it.first});
      }

      sort(v.rbegin(), v.rend());

      for(int i=0; i<k; i++){
        ans.push_back(v[i].second);
      }
      return ans;
      
    }
};
