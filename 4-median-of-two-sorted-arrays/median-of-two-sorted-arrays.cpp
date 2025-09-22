class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        for(int i=0;i<nums1.size();i++){
            result.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            result.push_back(nums2[i]);
        }
        sort(begin(result),end(result));
        int n = result.size();
        double md = 0;
        if(n%2 != 0){
            md = result[n/2];
        }
        else{  ////n = 4 
            int lw = n/2 - 1; ////lw =2
            int up = n/2; ////up = 3
            md = (result[lw]+ result[up])/2.0;
        }
        return md;
    }
};