class Solution {
public:
    int trapRainWater(vector<vector<int>>& hm) {
        vector<vector<int>> dir= {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int rows= hm.size();
        int cols= hm[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        priority_queue<Cell> bound;

        for(int i=0; i< rows; i++){
            bound.push(Cell(hm[i][0], i, 0));
            bound.push(Cell(hm[i][cols-1], i, cols-1));
            vis[i][0]= vis[i][cols-1]= true;
        }
        for(int i=0; i<cols; i++){
            bound.push(Cell(hm[0][i], 0, i));
            bound.push(Cell(hm[rows-1][i], rows-1, i));
            vis[0][i]= vis[rows-1][i]= true;
        }

        int tot=0;
        while(!bound.empty()){
            Cell cur= bound.top();
            bound.pop();

            int cr= cur.row, cc= cur.col, minh= cur.hgt;
            for(auto d: dir){
                int nr= cr+d[0], nc= cc+d[1];
                if(valid(nr, nc, rows, cols) and !vis[nr][nc]){
                    int nh= hm[nr][nc];
                    if(nh<minh){
                        tot+=minh-nh;
                    }
                    bound.push(Cell(max(nh, minh), nr, nc));
                    vis[nr][nc]= true;
                }
            }
        }
        return tot;
    }

    class Cell{
    public:
        int row;
        int col;
        int hgt;
        Cell(int hgt, int row, int col){
            this->hgt= hgt;
            this->row= row;
            this->col= col;
        }

        bool operator<(const Cell& other) const{
            return hgt>=other.hgt;
        }

    };
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
};