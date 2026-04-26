class Solution {
public:
    typedef long long ll;

    ll get1D(int side, int x, int y) {
        if(y == 0) return x;

        if(x == side) return side + y;

        if(y == side) return 3LL * side - x;

        return 4LL * side - y;
    }

    bool check(vector<ll>& doubled, int n, int k, int side, int mid) {
        ll perimeter = 4LL * side;

        for(int i = 0; i < n; i++) { //O(n)
            int count = 1; //Picked one point
            int idx   = i;

            ll lastPos = doubled[idx];

            for(int j = 2; j <= k; j++) { //O(k * log(n))
                ll target = lastPos + mid;

                auto it = lower_bound(begin(doubled) + idx + 1, begin(doubled) + i + n, target);

                if(it == begin(doubled) + i + n) break;

                idx = it - begin(doubled);
                lastPos = doubled[idx];
                count++;
            }

            if(count == k && (doubled[i] + perimeter - lastPos >= mid)) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        ll perimeter = 4LL * side;
        int n = points.size();

        vector<ll> positions(n);

        for(int i = 0; i < n; i++) {
            positions[i] = get1D(side, points[i][0], points[i][1]);
        }

        sort(begin(positions), end(positions));

        //double the positions array to easily handle round wrap
        vector<ll> doubled(2*n);
        for(int i = 0; i < n; i++) {
            doubled[i]   = positions[i];
            doubled[i+n] = positions[i] + perimeter;
        }

        int l = 0;
        int r = 2*side;

        int result = 0;

        //log(side) * n * klog(n)
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(check(doubled, n, k, side, mid)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return result;


    }
};
