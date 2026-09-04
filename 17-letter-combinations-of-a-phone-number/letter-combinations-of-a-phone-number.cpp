class Solution {
public:
    vector<string> ans;
    string s;
    string digits;

    vector<string> kp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void f(int i) {
        if (s.size() == digits.size()) {
            ans.push_back(s);
            return;
        }

        int sz = kp[digits[i] - '0'].size();

        for (int j = 0; j < sz; j++) {
            s.push_back(kp[digits[i] - '0'][j]);

            f(i + 1);

            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        ans.clear();
        s.clear();
        this->digits = digits;

        if (digits.empty())
            return {};

        f(0);

        return ans;
    }
};