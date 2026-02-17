class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>result;
        for(int h=0;h<=11;h++){
            for(int m=0;m<=59;m++){
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn){
                    string hour = to_string(h);
                    string minutes = (m < 10 ? "0" : "" ) + to_string(m);
                    result.push_back(hour + ":" + minutes);
                }
            }
        }
        return result;
    }
};