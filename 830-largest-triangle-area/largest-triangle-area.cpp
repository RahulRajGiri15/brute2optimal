// class Solution {
// public:
//     double largestTriangleArea(vector<vector<int>>& points) {
//         double maxarea = 0.0;
//         int n  = points.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     double area = 0;
//                     int x1 = points[i][0];
//                     int y1 = points[i][1];
//                     int x2 = points[j][0];
//                     int y2 = points[j][1];
//                     int x3 = points[k][0];
//                     int y3 = points[k][1];
//                     double a = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
//                     double b = sqrt(pow(x3-x2,2) + pow(y3-y2,2));
//                     double c = sqrt(pow(x3-x1,2) + pow(y3-y1,2));

                        ///////////or use hypot function in c++
                        // double a = hypot(x2-x1, y2-y1);
                        // double b = hypot(x3-x2, y3-y2);
                        // double c = hypot(x3-x1, y3-y1);

//                     /////////heroin's formaula
//                     double s = (a+b+c)/2;
//                     area = sqrt(s * (s-a) * (s-b) * (s-c));
//                     maxarea = max(maxarea , area);
//                 }
//             }
//         }
//         return maxarea;
//     }
// };

//////////////////

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxarea = 0.0;
        int n  = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    double area = 0;
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                   
                    area = 0.5 * abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
                    maxarea = max(maxarea , area);
                }
            }
        }
        return maxarea;
    }
};
