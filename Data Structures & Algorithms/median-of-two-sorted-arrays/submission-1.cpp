class Solution {
private:
    vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            arr.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            arr.push_back(nums2[j]);
            j++;
        }

        return arr;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr = mergeArray(nums1, nums2);

        int n = arr.size();
        if (n % 2 == 0) {
            return (arr[n/2 - 1] + arr[n/2]) / 2.0;
        } else {
            return arr[n/2];
        }
    }
};
