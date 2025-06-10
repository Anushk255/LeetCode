class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        vector<int> mp(26);
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        int oddmx = -1e3, evenmn = 1e3;
        for(int i=0;i<26;i++){
            if(mp[i]%2){
                oddmx=max(oddmx,mp[i]);
            }
            else if(mp[i]>0){
                evenmn=min(evenmn, mp[i]);
            }
        }
        return oddmx - evenmn;
    }
};