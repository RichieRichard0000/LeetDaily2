class Solution {
public:
    bool isValid(string &a, string &b) {
        if (a.size() != b.size())
            return false;

        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                diff++;
        }

        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {

        int n = words.size();

        vector<int> dp(n, 1);
        vector<int> parent(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (groups[i] != groups[j] &&
                    isValid(words[i], words[j])) {

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<string> ans;

        while (parent[lastIndex] != lastIndex) {
            ans.push_back(words[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        ans.push_back(words[lastIndex]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};