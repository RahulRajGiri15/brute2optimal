class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleM=minutes*360/60.0;
        double angleH=(hour+minutes/60.0)*360/12.0;
        double ans=abs(angleM-angleH);
        return min(360-ans, ans);
    }
};