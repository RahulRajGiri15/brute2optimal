class Solution {
public:
    long long sum =0;
    set<pair<int ,int>>main; ///top-x --> freq , elem
    set<pair<int ,int>>sec;  //// all other element -> freq , elem
    
    void insertinset(const pair<int,int> &p,int x){
        if(main.size() < x || p > *main.begin()){
            sum += 1LL * p.first * p.second;
            main.insert(p);
            if(main.size() > x){
                auto smallest = *main.begin();
                sum -= 1LL * smallest.first * smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        }else{
            sec.insert(p);
        }
    }
    void removefromset(const pair<int,int> &p){
        if(main.find(p) != main.end()){
            sum -= 1LL * p.first * p.second;
            main.erase(p);
            if(!sec.empty()){
                auto largest = *sec.rbegin();
                sum += 1LL * largest.first * largest.second;
                main.insert(largest);
                sec.erase(largest);
            }
        }
        else{
            sec.erase(p);
        }
    }


    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        vector<long long > res;

        unordered_map<int,int>mp; //// freq , elem
        int i=0;
        int j=0;
        while(j <n){
            if(mp[nums[j]] > 0){
                removefromset({mp[nums[j]], nums[j]});
            }
            mp[nums[j]]++;
            insertinset({mp[nums[j]], nums[j]}, x);

            if(j-i+1 == k){
                res.push_back(sum);
                
                removefromset({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                else{
                    insertinset({mp[nums[i]],nums[i]},x);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};