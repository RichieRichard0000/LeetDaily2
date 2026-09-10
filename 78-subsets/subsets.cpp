class Solution {
public:
    vector<int>curr;
    vector<vector<int>>ans;
    void f(int i,int n,vector<int>&nums){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        f(i+1,n,nums);
        curr.pop_back();
        f(i+1,n,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        curr.clear();
        f(0,nums.size(),nums);
        return ans;
    }
};