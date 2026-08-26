class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,j=1;
        while(i<(int)nums.size() && j<(int)nums.size()){
            while(i<(int)nums.size() &&  i%2==0 && nums[i]%2==0 )i+=2;
            while(j<(int)nums.size() &&  j%2!=0 && nums[j]%2!=0 )j+=2;
            if(i<(int)nums.size() && j<(int)nums.size())swap(nums[i],nums[j]);
        }
        return nums;
    }
};