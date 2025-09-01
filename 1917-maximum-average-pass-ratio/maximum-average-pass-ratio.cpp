class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<P> pq; //max-heap  -  //{max-delta, idx}

        for(int i = 0; i < n; i++) {
            double current_PR = (double)classes[i][0]/classes[i][1];
            double new_PR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = new_PR - current_PR;
            pq.push({delta, i});
        }
        
        //O(extraStudents * log(n))
        while(extraStudents--) { //O(k)
            auto curr = pq.top(); //log(n)
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++; //incremeent total passing students in the class
            classes[idx][1]++; //increment total students oin the class

            double current_PR = (double)classes[idx][0]/classes[idx][1];
            double new_PR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            delta = new_PR - current_PR;
            pq.push({delta, idx}); //log(n)
        }

        double result = 0.0;
        for(int i = 0; i < n; i++) {
            result += (double)classes[i][0]/classes[i][1];
        }

        return result/n;
    }
};
