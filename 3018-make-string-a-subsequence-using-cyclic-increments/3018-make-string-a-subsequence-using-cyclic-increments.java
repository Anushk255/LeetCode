class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int j =0;
        for(int i=0; i<str1.length(); i++){
            if((str2.charAt(j)-str1.charAt(i)+26)%26<=1) j+=1;
            if(j==str2.length()) return true;
        }
        return false;
    }
}