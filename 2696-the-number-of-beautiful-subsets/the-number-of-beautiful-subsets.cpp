class Solution {
public:
unordered_map<int,int>mp;
int k;
int ans=0;
    void f(int i,vector<int>&nums){
        if(i==nums.size()){
            ans++;
            return;
        }
        f(i+1,nums);
        if(!mp[nums[i]-k] && !mp[nums[i]+k]){
            mp[nums[i]]++;
            f(i+1,nums);
            mp[nums[i]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int K) {
        k=K;
        f(0,nums);
        return ans-1;

    }
};