/////////recursion --- TLE

// #include <algorithm>
// class Solution {
// public:
//     int n;
//     int child1collect(vector<vector<int>>& fruits){
//         int c1sum=0;
//         for(int i=0;i<n;i++){
//             c1sum += fruits[i][i]; /// child 1 can only access diagonal elemnt
//         }
//         return c1sum;
//     }
//     int child2collect(vector<vector<int>>& fruits,int i,int j){
//         if(i>=n || j<0 || j>=n){
//             return 0;
//         }
//         if(i == n-1 && j == n-1){
//             return 0;  /// already collected by child 1
//         }
//         if(i == j || i > j){
//             return 0;
//         }
//         int curr = fruits[i][j];
//         int count1 = child2collect(fruits,i+1,j-1);
//         int count2 = child2collect(fruits,i+1,j);
//         int count3 = child2collect(fruits,i+1,j+1);
//         return curr + max({count1,count2,count3});

//     }
//      int child3collect(vector<vector<int>>& fruits,int i,int j){
//         if(i<0 || j>=n || i>=n){
//             return 0;
//         }
//         if(i == n-1 && j == n-1){
//              return 0;
//         }
//         if(i == j || i<j){
//             return 0;
//         }
//         int curr = fruits[i][j];
//         int count1 = child3collect(fruits,i-1,j+1);
//         int count2 = child3collect(fruits,i,j+1);
//         int count3 = child3collect(fruits,i+1,j+1);
//         return curr + max({count1,count2,count3});

//     }
//     int maxCollectedFruits(vector<vector<int>>& fruits) {
//         n = fruits.size();
//         ///all child can make n-1 moves only 

//         int c1 = child1collect(fruits);///can move diagonal only
//         int c2 = child2collect(fruits,0,n-1);
//         int c3 = child3collect(fruits,n-1,0);
        
//         return c1+c2+c3;
//     }
// };

///////////

/////////memoization

#include <algorithm>
class Solution {
public:
    int n;
    vector<vector<int>>t;
    int child1collect(vector<vector<int>>& fruits){
        int c1sum=0;
        for(int i=0;i<n;i++){
            c1sum += fruits[i][i]; /// child 1 can only access diagonal elemnt
        }
        return c1sum;
    }
    int child2collect(vector<vector<int>>& fruits,int i,int j){
        if(i>=n || j<0 || j>=n){
            return 0;
        }
        if(i == n-1 && j == n-1){
            return 0;  /// already collected by child 1
        }
        if(i == j || i > j){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        int curr = fruits[i][j];
        int count1 = child2collect(fruits,i+1,j-1);
        int count2 = child2collect(fruits,i+1,j);
        int count3 = child2collect(fruits,i+1,j+1);
        return t[i][j] = curr + max({count1,count2,count3});

    }
     int child3collect(vector<vector<int>>& fruits,int i,int j){
        if(i<0 || j>=n || i>=n){
            return 0;
        }
        if(i == n-1 && j == n-1){
             return 0;
        }
        if(i == j || i<j){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        int curr = fruits[i][j];
        int count1 = child3collect(fruits,i-1,j+1);
        int count2 = child3collect(fruits,i,j+1);
        int count3 = child3collect(fruits,i+1,j+1);
        return t[i][j] = curr + max({count1,count2,count3});

    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        ///all child can make n-1 moves only 
        t.resize(n,vector<int>(n,-1));
        int c1 = child1collect(fruits);///can move diagonal only
        int c2 = child2collect(fruits,0,n-1);
        int c3 = child3collect(fruits,n-1,0);
        
        return c1+c2+c3;
    }
};