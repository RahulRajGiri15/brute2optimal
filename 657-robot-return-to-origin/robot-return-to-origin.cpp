class Solution {
public:
    bool judgeCircle(string moves) {
        int xcor = 0;
        int ycor = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'U'){
                xcor += 1;
            }
            else if(moves[i] == 'D'){
                xcor -= 1;
            }
            else if(moves[i] == 'R'){
                ycor += 1;
            }
            else if(moves[i] == 'L'){
                ycor -= 1;
            }
        }
        if(xcor == 0 && ycor == 0){
            return true;
        }
        return false;
    }
};