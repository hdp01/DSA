class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int robotCount = robot.size();
        vector<int> factoryPositions;

        for (const auto& currentFactory : factory) {
            int copies = min(currentFactory[1], robotCount);
            for (int i = 0; i < copies; i++) {
                factoryPositions.push_back(currentFactory[0]);
            }
        }

        int slotCount = factoryPositions.size();
        vector<vector<long long>> dp(robotCount + 1, vector<long long>(slotCount + 1, 0));
        long long inf = LLONG_MAX / 4;

        for (int i = 0; i < robotCount; i++) {
            dp[i][slotCount] = inf;
        }

        for (int i = robotCount - 1; i >= 0; i--) {
            for (int j = slotCount - 1; j >= 0; j--) {
                long long assign =
                    llabs(1LL * robot[i] - factoryPositions[j]) + dp[i + 1][j + 1];
                long long skip = dp[i][j + 1];
                dp[i][j] = min(assign, skip);
            }
        }

        return dp[0][0];
    }
};