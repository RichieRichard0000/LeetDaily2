class Solution {
public:
    int minDistance(string w1, string w2) {
        int l1 = w1.size();
        int l2 = w2.size();
            vector<vector<int>> mm(l1, vector<int>(l2, -1));
        
        return rc(w1, w2, 0, 0, l1, l2, mm);
    }
    
private:
    int rc(const string& w1, const string& w2, int ix, int jx, int l1, int l2, vector<vector<int>>& mm) {
        if (ix == l1) return l2 - jx; 
        if (jx == l2) return l1 - ix; 
        if (mm[ix][jx] != -1) {
            return mm[ix][jx];
        }
        if (w1[ix] == w2[jx]) {
            mm[ix][jx] = rc(w1, w2, ix + 1, jx + 1, l1, l2, mm);
            return mm[ix][jx];
        }
        int in = rc(w1, w2, ix, jx + 1, l1, l2, mm);     
        int dl = rc(w1, w2, ix + 1, jx, l1, l2, mm);     
        int rp = rc(w1, w2, ix + 1, jx + 1, l1, l2, mm); 
        
        mm[ix][jx] = 1 + min({in, dl, rp});
        return mm[ix][jx];
    }
};