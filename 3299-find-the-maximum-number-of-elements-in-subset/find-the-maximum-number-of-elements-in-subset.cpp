using ll=long long;
static int K[4]; // K[0]=sqrt(1e9), K[i+1]=sqrt(K[i])
static int freq[31623]; 
static bitset<31623> seenSq;// x*x>K[0] & seen in nums

class Solution {
public:
    static void findK(){
        if (K[0]) return;
        K[0]=sqrt(1e9);
        for(int i=1; i<4; i++){
            K[i]=sqrt(K[i-1]);
        }
    }
    static void reset(vector<int>& nums) {
        for(int x : nums) {
            if (x<=K[0]) freq[x]=0;
        }
        seenSq.reset();
    }

    static int maximumLength(vector<int>& nums) {
        findK();
        int xMax=0, n=nums.size();
        for (int x : nums) {
            if (x>K[0]) {// only perfect square matters the max len
                int rx=sqrt(x);
                if (rx*rx==x) seenSq[rx]=1;
            }
            else {
                freq[x]++;
                xMax=max(xMax, x);
            }
        }
        if (xMax==0) {
            reset(nums);
            return 1;
        }
        int ans=1; 
        if (freq[1]) { 
            const int f1=freq[1];
            ans=max(ans, f1-((f1 & 1)==0));
        }
        if (ans>=9) {
            reset(nums);
            return ans; 
        }
        int k=3;
        for (int x=2; x<=xMax; x++) {
            if (freq[x]==0) continue;
            while(x>K[k]) k--;
            int cnt=0;
            ll y=x;
            bool flag=0;
            
            while(y<=K[0] && freq[y]>=2) {
                cnt+=2;
                ll y2=y*y;
                if (y*y>K[0]) { 
                    flag=1;
                    cnt+=(seenSq[y]<<1)-1;
                    break;
                }
                y=y2;
            }
            
            if (!flag) {
                bool isIn=(y<=K[0]) && (freq[y]>=1);
                cnt+=(isIn<<1)-1;
            }
            ans=max(ans, cnt);
            if (ans==2*(k+1)+1) {
                reset(nums);
                return ans;
            }
        }
        
        reset(nums);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();