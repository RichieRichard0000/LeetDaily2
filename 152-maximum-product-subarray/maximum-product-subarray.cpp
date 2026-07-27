class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curr_mx=nums[0];
        int curr_mn=nums[0];
        int result=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)swap(curr_mx,curr_mn);
            curr_mx=max(nums[i],curr_mx*nums[i]);
            curr_mn=min(nums[i],curr_mn*nums[i]);
            result=max(result,curr_mx);
        }
        return result;
    }
};