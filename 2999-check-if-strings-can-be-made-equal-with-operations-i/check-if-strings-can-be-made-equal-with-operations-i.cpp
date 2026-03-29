class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i = 0;i<4;i++){
            string temp = s1;
            if(temp == s2){
                return true;
            }
            for(int j =i+2;j<4;j++){
                char a = temp[j];
                char b = temp[j-2];
                temp[j] = b;
                temp[j-2] = a;
                if(temp == s2){
                    return true;
                }
            }
        }
        return false;
    }
};