class Solution {
private:
    bool outOfIntegerLimits(long long num){
        return (num> INT_MAX || num< INT_MIN);
    }
    long long solveRec(vector<int>& nums){
        long long result=INT_MIN;
        long long prefix=1, suffix=1;

        for(int i=0; i<nums.size(); i++){
            prefix*=nums[i];
            suffix*=nums[nums.size()-i-1];
            result= max(result, max(prefix, suffix));

            if(prefix==0 || outOfIntegerLimits(prefix)) prefix=1;
            if(suffix==0 || outOfIntegerLimits(suffix)) suffix=1;
        }
        return result;
    }
public:
    int maxProduct(vector<int>& nums) {
        return solveRec(nums);        
    }
};