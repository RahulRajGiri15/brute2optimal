class Solution {
public:
    void rotate(string &st , int b){
        reverse(st.begin(),st.end());
        reverse(st.begin(),st.begin()+b);
        reverse(st.begin()+b,st.end());
    }
    string findLexSmallestString(string s, int a, int b) {
        string smalleststring = s;
        queue<string>que;
        unordered_set<string>visited;
        que.push(s);
        visited.insert(s);
        while(!que.empty()){
            string curr = que.front();
            que.pop();
            if(curr < smalleststring){
                smalleststring = curr;
            }
            /////add a to the digit
            string temp = curr;
            for(int i=1;i<temp.size();i=i+2){
                temp[i] = (((temp[i]-'0')+a) %10)+'0';
            }
            if(!visited.count(temp)){
                visited.insert(temp);
                que.push(temp);
            }

            /////rorate
            rotate(curr, b);

            if(!visited.count(curr)){
                visited.insert(curr);
                que.push(curr);
            }
        }
        return smalleststring;
    }
};