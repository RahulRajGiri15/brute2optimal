// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j] == target){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

///////////////////////


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0 , j = n-1;
        while(i <m && j >= 0){
    
            if(matrix[i][j] > target ){
                j--;
            }
            else if(matrix[i][j] < target){
                i++;
            }
            else{
                return true;
            }

        }
        return false;
    }
};



////////////////////////

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int l = 0 , h = m*n -1;
//         while(l <= h){
//             int mid = l + (h-l)/2;
//             ///// row -> mid/n;
//             ///// col -> mid%n;
//             if(matrix[mid/n][mid%n] > target ){
//                 h = mid -1;
//             }
//             else if(matrix[mid/n][mid%n] < target){
//                 l = mid+1;
//             }
//             else{
//                 return true;
//             }

//         }
//         return false;
//     }
// };