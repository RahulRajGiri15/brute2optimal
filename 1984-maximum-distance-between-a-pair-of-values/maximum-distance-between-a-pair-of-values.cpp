class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0; //nums1
        int j = 0; //nums2

        int result = 0;

        while(i < m && j < n) {
            if(nums1[i] > nums2[j]) {
                i++;
            } else {
                result = max(result, j-i);
                j++;
            }
        }
        
        return result;
    }
};