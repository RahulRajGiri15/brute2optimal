public class Solution {
    public int FirstUniqChar(string s) {
        Dictionary<char,int> mp = new Dictionary<char, int>();
        int n = s.Length;
        for(int i=0;i<n;i++){
            if(mp.ContainsKey(s[i])){
                mp[s[i]]++;
            }
            else{
                mp[s[i]] = 1;
            }
        }
        for(int i=0;i<s.Length;i++){
            if(mp[s[i]]  == 1){
                return i;
            }
        }
        return -1;
    }
}