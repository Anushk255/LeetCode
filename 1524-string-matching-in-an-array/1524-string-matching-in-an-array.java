class Solution {
    public static boolean check(String a, String asub){
        int i = 0, j = 0, k, l, m = a.length(), n = asub.length();
        while(i < m-n+1 && j < n){
            k = i; l = j;
            if(a.charAt(k) == asub.charAt(l)){
                while(k < m && l < n && a.charAt(k) == asub.charAt(l)){
                    k++; l++;
                }
                if(l == n) return true;
            }
            i++;
        }
        return false;
    }

    public List<String> stringMatching(String[] words) {
        List<String> list = new ArrayList<>();
        Set<String> ans = new HashSet<>();
        int n = words.length, len;
        for(int i = 0; i<n; i++){
            len = words[i].length();
            for(int j = i+1; j<n; j++){
                if(len > words[j].length()){
                    if(check(words[i], words[j])) ans.add(words[j]);
                }
                else if(len == words[j].length()){
                    if(check(words[i], words[j])) ans.add(words[j]);
                    if(check(words[j], words[i])) ans.add(words[i]);
                }
                else{
                    if(check(words[j], words[i])) ans.add(words[i]);
                }
            }
        }
        for(String s : ans) list.add(s);
        return list;
    }
}