class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort to group similar/consecutive numbers
        
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            temp.push_back(nums[i]); // Start subsequence
            
            // Build subsequence with nums[j] where diff is 0 or 1
            for (int j = i + 1; j < n; j++) {
                if (nums[j] - nums[i] == 0 || nums[j] - nums[i] == 1) {
                    temp.push_back(nums[j]);
                } else {
                    break; // No longer valid
                }
            }

            // Only consider subsequence if max - min == 1
            if (!temp.empty() && temp.back() - temp.front() == 1) {
                maxi = max(maxi, (int)temp.size());
            }
        }
        
        return maxi;
    }
};