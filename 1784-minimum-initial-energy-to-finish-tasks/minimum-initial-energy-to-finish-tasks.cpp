class Solution {
public:
    int minimumEffort(std::vector<std::vector<int>>& tasks) {
        std::sort(tasks.begin(), tasks.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        int totalInitialEnergy = 0;
        int currentEnergy = 0;
        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];
            if (currentEnergy < minimum) {
                totalInitialEnergy += (minimum - currentEnergy);
                currentEnergy = minimum;
            }
            currentEnergy -= actual;
        }
        return totalInitialEnergy;
    }
};   