class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int>temp;
        for(int i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }
        vector<int>temp2;
        for(int i=0;i<n-k;i++){
            temp2.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0;i<k;i++){
            nums.push_back(temp[i]);
        }
        int j=0;
        for(int i=k;i<n;i++){
            nums.push_back(temp2[j]);
            j++;
        }
        
    }
};