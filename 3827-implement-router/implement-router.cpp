#include <bits/stdc++.h>
using namespace std;

class Router {
    int limit;
    queue<array<int,3>> q; // FIFO packets
    unordered_set<string> seen; // duplicate detection

    // dest -> timestamps (sorted because insert in increasing order)
    unordered_map<int, vector<int>> destTimestamps;
    // dest -> index of first valid (not removed) timestamp
    unordered_map<int, int> startIdx;

    string makeKey(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

    void removePacket(const array<int,3>& pkt) {
        // remove from seen
        string key = makeKey(pkt[0], pkt[1], pkt[2]);
        seen.erase(key);
        // increment pointer for dest timestamps
        int dest = pkt[1];
        int ts = pkt[2];
        // The timestamp being removed is at destTimestamps[dest][startIdx[dest]]
        // so just increment startIdx
        if (startIdx.count(dest) && startIdx[dest] < (int)destTimestamps[dest].size()
            && destTimestamps[dest][startIdx[dest]] == ts) {
            startIdx[dest]++;
        } 
        // if we removed all old ones, can also compact vector later if needed
    }

public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source,destination,timestamp);
        if (seen.count(key)) return false; // duplicate
        
        if ((int)q.size() == limit) {
            auto old = q.front(); q.pop();
            removePacket(old);
        }

        q.push({source,destination,timestamp});
        seen.insert(key);
        destTimestamps[destination].push_back(timestamp);
        // ensure startIdx exists
        if (!startIdx.count(destination)) startIdx[destination] = 0;
        
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto pkt = q.front(); q.pop();
        removePacket(pkt);
        return {pkt[0], pkt[1], pkt[2]};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destTimestamps.count(destination)) return 0;
        auto &vec = destTimestamps[destination];
        int st = startIdx[destination]; // only valid from here onwards
        
        // binary search range within [st, end)
        auto low = lower_bound(vec.begin()+st, vec.end(), startTime);
        auto high = upper_bound(vec.begin()+st, vec.end(), endTime);
        return high - low;
    }
};
