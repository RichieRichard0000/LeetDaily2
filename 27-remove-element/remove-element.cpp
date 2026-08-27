class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i;
        for(i=0;i<n;i++){
            if(nums[i]==val)break;
        }
        int j=i;
        while(j<n && nums[i]==nums[j])j++;
        if(j==n)return i;
        while(j<n){
            swap(nums[i],nums[j]);
            j++;
            i++;
        }
        return i;
    }
};