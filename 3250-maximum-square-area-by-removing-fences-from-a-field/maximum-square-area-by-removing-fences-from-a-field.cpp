class Solution {
public:
    int M = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(begin(hFences),end(hFences));
        sort(begin(vFences),end(vFences));

        unordered_set<int> widths;
        unordered_set<int> heights;
        for(int i=0;i<vFences.size()-1;i++){
            for(int j=1;j<vFences.size();j++){
                int width = vFences[j] - vFences[i];
                widths.insert(width);
            }
        }
        int maxcomside = 0;
        for(int i=0;i<hFences.size()-1;i++){
            for(int j=1;j<hFences.size();j++){
                int height = hFences[j] - hFences[i];
                if(widths.find(height) != widths.end()){
                    maxcomside = max(height,maxcomside);
                }
            }
        }
        // return (maxcomside != 0)? (1LL * maxcomside * maxcomside) % M : -1;
        return maxcomside == 0 ? -1 : (1LL * maxcomside * maxcomside) % M;
    }
};