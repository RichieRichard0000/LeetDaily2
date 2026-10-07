class Solution {
public:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};
        
        unordered_set<string> visited;
        queue<string> q;
        
        q.push(s);
        visited.insert(s);
        
        bool found = false;
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // If valid, add to result and set found flag to true
            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }
            
            // If we found a valid string at this level, we don't need to 
            // remove any more characters. Continue processing the current queue.
            if (found) continue;
            
            // Otherwise, branch out by removing one character at a time
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue; // Skip letters
                
                string nextStr = curr.substr(0, i) + curr.substr(i + 1);
                
                // If we haven't seen this string before, add it to queue
                if (visited.find(nextStr) == visited.end()) {
                    visited.insert(nextStr);
                    q.push(nextStr);
                }
            }
        }
        
        return result;
    }
};