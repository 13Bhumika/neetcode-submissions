class Solution {
private:
    int square(int n){
        int result=0;

        while(n!=0){
            int digit= n%10;
            result+= digit*digit;
            n=n/10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> hash;

        while(true){
            n=square(n);
            if(n==1) return true;
            if(hash.find(n)!=hash.end()) return false;
            hash.insert(n);
        }
    }
};