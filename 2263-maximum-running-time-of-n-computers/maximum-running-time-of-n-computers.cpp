class Solution {
public:
    typedef long long ll;
    bool ispossible(ll mid , vector<int>& batteries,int n){
        ll sum =0;
        for(int i=0;i<batteries.size();i++){
            sum += min((ll)batteries[i],mid);
            if(sum >= (mid*n)){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll bn = batteries.size();
        ll l = *min_element(batteries.begin(),batteries.end());
        ll r ;
        ll total_sum = 0;
        for(int i=0;i<bn;i++){
            total_sum += batteries[i];
        }
        r = total_sum / n;
        ll res = 0;
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(ispossible(mid,batteries,n)){
                res = mid;
                l = mid+1;
            }
            else{
                r = mid -1;
            }
        }
        return res;
    }
};




//////////////////////////////////

// class Solution {
// public:
//     typedef long long ll;

//     long long maxRunTime(int n, vector<int>& batteries) {
//         ll bn = batteries.size();
//         ll l = *min_element(batteries.begin(),batteries.end());
//         ll r ;
//         ll total_sum = 0;
//         for(int i=0;i<bn;i++){
//             total_sum += batteries[i];
//         }
//         r = total_sum / n;
//         ll res = 0;
//         while(l <= r){
//             ll mid = l + (r-l)/2;
//             ll summ = 0;
//             for(int i=0;i<n;i++){
//                 summ += batteries[i];
//                 if(summ >= mid){
//                     res = mid;
//                     l = mid+1;
//                 }
//                 else{
//                     r = mid -1;
//                 }
//             }
//         }
//         return res;
//     }
// };