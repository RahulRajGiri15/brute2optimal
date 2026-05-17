

//Approach-2 (BFS with in-place visited marking)
//T.C : O(n)
//S.C : O(n) — queue space
class Solution {
public:
    bool bfs(vector<int>& arr, int start, int n) {
        queue<int> que;
        que.push(start);

        while(!que.empty()) {
            int curr = que.front();
            que.pop();

            //reached 0
            if(arr[curr] == 0)
                return true;

            //This was visited before. Ignore
            if(arr[curr] < 0)
                continue;

            int left  = curr + arr[curr];
            int right = curr - arr[curr];

            if(left >= 0 && left < n)
                que.push(left);
            if(right >= 0 && right < n)
                que.push(right);

            //curr is visited and its neighbours are explored. We don't need it
            arr[curr] = -arr[curr];
        }

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = (int) arr.size();
        return bfs(arr, start, n);
    }
};
