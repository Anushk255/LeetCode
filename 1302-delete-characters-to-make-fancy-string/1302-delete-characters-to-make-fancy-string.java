class Solution {
    public String makeFancyString(String s) {
        if(s.length()<=2)return s;
        StringBuilder ans=new StringBuilder();
        ans.append(s.charAt(0));
        ans.append(s.charAt(1));

        for(int i=2;i<s.length();i++){
            if(!(ans.charAt(ans.length()-1)==s.charAt(i) && ans.charAt(ans.length()-2)==s.charAt(i))){
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
    }
}