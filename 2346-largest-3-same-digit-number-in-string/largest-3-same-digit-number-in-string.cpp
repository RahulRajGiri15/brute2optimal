class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        int cnt = 0;
        for(int i=0;i<=num.size()-3;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                if(cnt == 0){
                    res = string(3,num[i]);
                    cnt++;
                }
                else if(cnt != 0){
                    int temp = atoi(string(3,num[i]).c_str());
                    if(atoi(res.c_str()) < temp){
                        res = to_string(temp);
                    }
                }
            }
        }
        return res;
    }
};