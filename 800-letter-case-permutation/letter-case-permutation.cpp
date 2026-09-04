class Solution {
public:
    vector<string> ans;

    void f(int i, int n, string s) {
        if (i == n) {
            ans.push_back(s);
            return;
        }

        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = toupper(s[i]);
            f(i + 1, n, s);

            s[i] = tolower(s[i]);
            f(i + 1, n, s);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = tolower(s[i]);
            f(i + 1, n, s);

            s[i] = toupper(s[i]);
            f(i + 1, n, s);
        }
        else {
            f(i + 1, n, s);
        }
    }

    vector<string> letterCasePermutation(string s) {
        ans.clear();
        f(0, s.size(), s);
        return ans;
    }
};