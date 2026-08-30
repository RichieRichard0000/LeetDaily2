class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();

        int target_index = -1;
        for (int i = len - 1; i > 0; i--) {
            if (s[i] > s[i - 1]) {
                target_index = i - 1;
                break;
            }
        }

        if (target_index == -1) return -1;
        for (int i = len - 1; i > target_index; i--) {
            if (s[i] > s[target_index]) {
                swap(s[i], s[target_index]);
                break;
            }
        }
        reverse(s.begin() + target_index + 1, s.end());

        long long ans = stoll(s);

        if (ans > INT_MAX) return -1;

        return (int)ans;
    }
};