class Solution {
private:
    bool isPossible(vector<int>& piles, long long h, long long rate) {
        long long hours = 0;

        for(int i = 0 ; i < piles.size() ; i ++) {
            if(piles[i] <= rate) hours ++;
            else if(piles[i] % rate == 0) {
                hours += piles[i] / rate;
            }
            else {
                hours += (piles[i] / rate) + 1;
            }
        }

        return hours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(), piles.end());

        int result = -1;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(isPossible(piles, h, mid)) {
                result = mid;
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }

        return result;
    }
};