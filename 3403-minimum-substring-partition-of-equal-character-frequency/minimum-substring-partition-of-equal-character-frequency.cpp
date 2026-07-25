class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0; 
        for (int i = 1; i <= n; i++) {
            vector<int> freq(26, 0);
            int max_freq = 0;
            int unique_chars = 0;
            
            for (int j = i; j >= 1; j--) {
                int char_idx = s[j - 1] - 'a';
                if (freq[char_idx] == 0) {
                    unique_chars++;
                }
                
                freq[char_idx]++;
                max_freq = max(max_freq, freq[char_idx]);
                
                int current_length = i - j + 1;
                if (max_freq * unique_chars == current_length) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        
        return dp[n];
    }
};