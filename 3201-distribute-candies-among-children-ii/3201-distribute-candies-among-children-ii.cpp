class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=0;i<=min(n,limit);i++){
            int rem = n-i;
            if(rem > 2*limit) continue;
            int lower = max(rem-limit,0);
            int upper = min(limit,rem);
            ans+=(upper-lower+1);
        }
        return ans;
    }
};