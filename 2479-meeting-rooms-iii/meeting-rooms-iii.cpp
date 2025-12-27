class Solution {
public:
    typedef pair<long long, int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(begin(meetings), end(meetings)); //sort by starting time of meetings

        vector<int> roomsUsedCount(n, 0); //Each room is used 0 times in the beginning

        priority_queue<P, vector<P>, greater<P>> usedRooms;
        //To store {earliest room empty time, room No.}
        
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        //To store rooms that are used
        for(int room = 0; room < n; room++) {
            unusedRooms.push(room); //All rooms are unused in the beginning
        }

        for(vector<int>& meet : meetings) {
            int start  = meet[0];
            int end    = meet[1];

            //First see, by this time, which rooms can be empty now
            //And move them to unusedRooms
            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            if(!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            } else { //We don't have any room available now. Pick earliest end room
                int room          = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + (end-start), room});
                roomsUsedCount[room]++;
            }

        }

        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};

