class Solution {
public:
    int maximum69Number (int num) {
        string ans = to_string(num);
        for(int i=0;i<ans.size();i++){
            if(ans[i] == '6'){
                ans[i] = '9';
                break;
            }
        }
        int res = stoi(ans);
        return res;
    }
};