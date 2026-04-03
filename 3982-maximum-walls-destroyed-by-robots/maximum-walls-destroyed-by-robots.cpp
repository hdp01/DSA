class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {robots[i], distance[i]};
        ranges::sort(arr, {}, &pair<int,int>::first);
        ranges::sort(walls);

        auto countWalls = [&](int l, int r) -> int {
            if (l > r) return 0;
            int li = (int)(ranges::lower_bound(walls, l) - walls.begin());
            int ri = (int)(ranges::upper_bound(walls, r) - walls.begin());
            return ri - li;
        };
        int dp0 = 0, dp1 = 0;
        for (int i = 0; i < n; i++) {
            int prevL = (i > 0) ? dp0 : 0;
            int prevR = (i > 0) ? dp1 : 0;
            int fl = arr[i].first - arr[i].second;
            if (i > 0) fl = max(fl, arr[i-1].first + 1);
            int baseFl = prevL + countWalls(fl, arr[i].first);
            int frBase = arr[i].first + arr[i].second;
            int ndp0, ndp1;
            {
                int fr = frBase;
                if (i + 1 < n) fr = min(fr, arr[i+1].first - arr[i+1].second - 1);
                ndp0 = max(baseFl, prevR + countWalls(arr[i].first, fr));
            }
            {
                int fr = frBase;
                if (i + 1 < n) fr = min(fr, arr[i+1].first - 1);
                ndp1 = max(baseFl, prevR + countWalls(arr[i].first, fr));
            }
            dp0 = ndp0;
            dp1 = ndp1;
        }
        return dp1;
    }
};