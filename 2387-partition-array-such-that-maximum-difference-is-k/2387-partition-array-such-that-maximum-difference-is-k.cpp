class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        int mx = 0;
        for(auto x: nums) mx=max(mx, x);
        vector<int> cnt(mx + 1);
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        vector<int> sorted;
        for(int i=0;i<=mx;i++){
            if(cnt[i]!=0){
                while(cnt[i]--){
                    sorted.push_back(i);
                }

            }
        }
        int p=sorted[0];
        int ans = 1;
        for(int i=0;i<n;i++){
            if(sorted[i]-p>k){
                p=sorted[i];ans++;
            }
        }
        return  ans;

    }
};