class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadusers;

        ////o(F * L)
        for(auto &friends : friendships){
            int u = friends[0] -1;
            int v = friends[1] -1;
            unordered_set<int>langset(begin(languages[u]),end(languages[u]));
            bool cantalk = false;
            for(int lang : languages[v]){
                if(langset.count(lang)){
                    cantalk = true;
                    break;
                }
            }
            if(cantalk == false){
                sadusers.insert(u);
                sadusers.insert(v);
            }
        }

        ///////now find the mostspoked languages
        vector<int>languag(n+1,0);
        int mostknownlang = 0;
        
        /////o(F * L)
        for(int user : sadusers){
            for(int lang : languages[user]){
                languag[lang]++;
                mostknownlang = max(mostknownlang , languag[lang]);
            }
        }
        
        return sadusers.size() - mostknownlang;
    }
};