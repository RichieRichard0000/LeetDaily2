class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int i = 0, j = n - 1;
        int currA = capacityA, currB = capacityB;
        int ans = 0;
        while (i < j) {
            if (currA < plants[i]) {
                ans++;
                currA = capacityA;
            }
            currA -= plants[i];
            if (currB < plants[j]) {
                ans++;
                currB = capacityB;
            }
            currB -= plants[j];

            i++;
            j--;
        }
        if (i == j) {
            if (max(currA, currB) < plants[i])
                ans++;
        }

        return ans;
    }
};