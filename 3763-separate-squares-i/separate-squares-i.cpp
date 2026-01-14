class Solution {
public:
    bool check(vector<vector<int>> &squares,double mid, double total_area){
        double botm_area = 0.0;
        for(auto &square : squares){
            double boty = square[1];
            double len = square[2];

            if(mid > (boty + len)){
                botm_area += len * len;
            }
            else if(mid > boty){
                botm_area += len * (mid - boty);
            }
        }
        return (botm_area >= total_area/2.0);
    }
    double separateSquares(vector<vector<int>>& squares) {
        double total_area = 0.0;
        double high = INT_MIN;
        double low = INT_MAX;
        for(auto &square : squares){
            double len = square[2];
            total_area += len * len;
            double x = square[0];
            double y = square[1];
            double l = square[2];
            high = max(high,y+l);
            low = min (low , y);
        }

      
        double result_y = 0.0;
        while(high - low >= 1e-5){
            double mid = low + (high - low)/2;
            result_y = mid;

            if(check(squares,mid,total_area) == true){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        return result_y;
    }
};