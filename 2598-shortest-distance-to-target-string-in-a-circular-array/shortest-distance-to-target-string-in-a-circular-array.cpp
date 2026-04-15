class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int answer = n;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int distance = abs(i - startIndex);
                answer = min(answer, min(distance, n - distance));
            }
        }
        return answer < n ? answer : -1;
    }
};