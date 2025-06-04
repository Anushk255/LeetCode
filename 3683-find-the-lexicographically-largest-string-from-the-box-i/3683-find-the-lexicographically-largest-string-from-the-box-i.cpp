class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int n = word.size();
        int k = n-numFriends+1;
        int best = 0,rival=1;
        while(rival<n){
            int len=0;
            while(rival+len<n && word[best+len]==word[rival+len]){
                len++;
            }
            if(rival+len<n && word[best+len]<word[rival+len]){
                int t=best;
                best = rival;
                rival=max(rival + 1,t+len+1);
            }
            else{
                rival=rival + len +1;
            }
        }
        string ans="";
        for(int i=best;i<best+k && i<n;i++){
            ans+=word[i];
        }
        return ans;
    }
};