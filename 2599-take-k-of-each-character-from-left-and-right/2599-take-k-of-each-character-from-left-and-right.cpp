class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), maxlen = 0, i=0,j=0;
        vector<int>total(3,0),window(3,0);

        for(int i=0;i<n;i++){
            total[s[i]-'a']++;
        }
        if(total[0]<k || total[1] < k ||total[2]<k){
            return -1;
        }
        while(j<n){
            window[s[j]-'a']++;
            while(i <= j && (total[0] - window[0] < k || total[1] - window[1] < k || total[2]-window[2]<k)){
                window[s[i]-'a']--;
                i++;
            }
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return n - maxlen;
    }
};