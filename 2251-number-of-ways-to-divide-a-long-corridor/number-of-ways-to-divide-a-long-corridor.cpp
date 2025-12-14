class Solution {
public:
    int M = 1e9 +7;
    int numberOfWays(string corridor) {
        vector<int>idxstore;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i] == 'S'){
                idxstore.push_back(i);
            }
        }
        if(idxstore.size() == 0 || idxstore.size() %2 != 0){ /// if odd or size is 0
            return 0;
        }
        int prev_value = idxstore[1];

        int result =1;

        for(int i=2;i<idxstore.size();i = i+2){
            int curr = idxstore[i];
            result = (1ll * result * (curr - prev_value)) % M;
            prev_value = idxstore[i+1];
        }
        return result;
    }
};