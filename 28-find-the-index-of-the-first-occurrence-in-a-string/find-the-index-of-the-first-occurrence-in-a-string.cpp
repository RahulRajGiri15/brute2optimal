class Solution {
public:
    int strStr(string haystack, string needle) {
        int foundfrst = -1;
        for(int i=0;i<haystack.size();i++){
            int k =i;
            int j =0;
            bool mila = true;
            while(j<needle.size()){
                if(haystack[i+j] != needle[j]){
                    mila = false;
                    break;
                }
                j++;
            }
            if(mila == true && foundfrst == -1){
                foundfrst = k;
            }
        }
        return foundfrst;
    }
};