////////using 2 loops -- TLE 

// class Solution {
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         int n = fruits.size();
//         int placed=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(baskets[j] >= fruits[i]){
//                     placed++;
//                     baskets[j] = 0;
//                     break;
//                 }
//             }
//         }
//         return n - placed;
//     }
// };

///t--o(n^2)
///s--o(1)

//////// approach 2 --- using segment tree 

class Solution {
public:
    void buildtree(int idx,int l,int r,vector<int>& baskets,vector<int>& segmenttree){
        /////base condition 
        if(l == r){
            segmenttree[idx] = baskets[r];
            return;
        }
        ////recursion condition
        int mid = l+(r-l)/2;
        buildtree(2*idx+1,l,mid,baskets,segmenttree);
        buildtree(2*idx+2,mid+1,r,baskets,segmenttree);

        segmenttree[idx] = max(segmenttree[2*idx+1],segmenttree[2*idx+2]);

    }
    bool querysegmenttree(int i,int l,int r,vector<int>& segmenttree,int fruit){
        
        if(segmenttree[i] < fruit){
            return false;
        }
        if(l == r){
            segmenttree[i] = -1; // mark it and assign the fruit in that basket
            return true;
        }
        int mid = l + (r-l)/2;
        // bool placed = false;
        // if(segmenttree[i] >= fruit){
        //     placed = querysegmenttree(2*i+1,l,mid,segmenttree,fruit);
        // }
        // else{  /// segmenttree[i] < fruit
        //     placed = querysegmenttree(2*i+2,mid+1,r,segmenttree,fruit);
        // }
        ///////////
        
        bool placed = querysegmenttree(2*i+1,l,mid,segmenttree,fruit);
        if(!placed){  /// segmenttree[i] < fruit
            placed = querysegmenttree(2*i+2,mid+1,r,segmenttree,fruit);
        }
        segmenttree[i] = max (segmenttree[2*i+1],segmenttree[2*i+2]);
        return placed;

    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int>segmenttree(4*n,-1);
        buildtree(0,0,n-1,baskets,segmenttree);
        
        int unplaced = 0;
        for(auto & fruit : fruits){
            if(querysegmenttree(0,0,n-1,segmenttree,fruit) == false){
                unplaced++;
            }
        }
        return unplaced;
    }
};


