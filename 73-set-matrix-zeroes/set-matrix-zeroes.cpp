///////////////brute approach --- taking extra space 

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>>result = matrix;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j] == 0){
//                     for(int k=0;k<n;k++){
//                         result[i][k] = 0;
//                     }
//                     for(int k=0;k<m;k++){
//                         result[k][j] = 0;
//                     }
//                 }
//             }
//         }
//         matrix = result;
        
//     }
// };

//////////////better approach -- taking a row and column of m , n size
////make the index = 0 in row and column where size is o

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int>rw(m,1);
//         vector<int>cl(n,1);
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j] == 0){
//                     rw[i] = 0;
//                     cl[j] = 0;
//                 }
//             }
//         }
//         for(int k=0;k<m;k++){
//             if(rw[k] == 0){
//                 for(int l=0;l<n;l++){
//                     matrix[k][l] =0;
//                 }
//             }
//         }
//         for(int k=0;k<n;k++){
//             if(cl[k] == 0){
//                 for(int l=0;l<m;l++){
//                     matrix[l][k] = 0;
//                 }
//             }
//         }
//     }
// };


////////////////most optimal approach

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>rw(m,1);
        vector<int>cl(n,1);
        bool firstcolimpacted = false;
        bool firstrowimpacted = false;
        /// we have check for first row and first column before only 
        /// beacuse later it will create 
        /////for 1st row 
        for(int i=0;i<n;i++){
            if(matrix[0][i] == 0){
                firstrowimpacted = true;
            }
        }
        /////for 2nd row
        for(int i=0;i<m;i++){
            if(matrix[i][0] == 0){
                firstcolimpacted = true;
            }
        }
       
        /////changing first row and first coulmn accroding to requirement
        ///set markers

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        ///// chaning rest of the element excluding first row and first coulmn 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] =0;
                }
            }
        }


        if(firstrowimpacted == true){
            for(int j=0;j<n;j++){
                matrix[0][j] = 0;
            }
        }
        if(firstcolimpacted == true){
            for(int i=0;i<m;i++){
                matrix[i][0] = 0;
            }
        }

    }
};