class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int m = dimensions.size();
        int n = dimensions[0].size();
        
        float maxdign = -1;
        float maxarea = -1;

        for(int i=0;i<m;i++){
            float dig = 0;
                dig = sqrt((dimensions[i][0]*dimensions[i][0]) + (dimensions[i][1]*dimensions[i][1]));
                float area =  dimensions[i][0] * dimensions[i][1];

                if(dig > maxdign){
                    maxdign = dig;
                    maxarea = area;
                }
                else if(dig == maxdign && area > maxarea){
                    maxarea = area;
                }
        }
        return maxarea;
    }
};