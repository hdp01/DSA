class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int directions[5] = {0, 1, 0, -1, 0};
        auto hashCoordinate = [](int x, int y) {
            return x * 60010 + y;
        };
        unordered_set<int> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(hashCoordinate(obstacle[0], obstacle[1]));
        }
        int maxDistanceSquared = 0;
        int directionIndex = 0;
        int currentX = 0, currentY = 0;  
        for (int command : commands) {
            if (command == -2) {
                directionIndex = (directionIndex + 3) % 4;
            } else if (command == -1) {
                directionIndex = (directionIndex + 1) % 4;
            } else {
                while (command--) {
                    int nextX = currentX + directions[directionIndex];
                    int nextY = currentY + directions[directionIndex + 1];
                    if (obstacleSet.count(hashCoordinate(nextX, nextY))) {
                        break;  
                    }
                    currentX = nextX;
                    currentY = nextY;
                    maxDistanceSquared = max(maxDistanceSquared, currentX * currentX + currentY * currentY);
                }
            }
        }      
        return maxDistanceSquared;
    }
};