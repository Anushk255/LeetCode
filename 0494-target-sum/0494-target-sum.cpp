class Solution {
public:
int count=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums, 0, 0 , target);
        return count;
    }
    void solve(vector<int>& nums, int i, int sum, int target)
    {
        if(i==nums.size())
        {
            if(sum == target)
            {
                count++;
            }
        }
        else{
            solve(nums, i+1, sum+nums[i], target);
            solve(nums, i+1, sum-nums[i], target);
        }
    }
};