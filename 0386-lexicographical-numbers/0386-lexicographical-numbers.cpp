class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int x=1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(x);
            if(x*10 <= n){
                x*=10; continue;
            }
            if(x+1 > n) x/=10;
            x++;
            while(x%10==0){
                x/=10;
            }
        }
        return ans;
        
    }
};