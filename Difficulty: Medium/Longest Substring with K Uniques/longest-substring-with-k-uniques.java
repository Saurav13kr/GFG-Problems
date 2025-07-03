class Solution {
    public int longestKSubstr(String s, int k) {
        // code here
        int i=0,j=0,max=-1;
        HashMap<Character,Integer>map=new HashMap<>();
        for(;i<s.length();i++){
            char ch=s.charAt(i);
            map.put(ch,map.getOrDefault(ch,0)+1);
            if(map.size()>k){
                char ch1=s.charAt(j);
                map.put(ch1,map.get(ch1)-1);
                if(map.get(ch1)==0)
                {
                    map.remove(ch1);
                }
                j++;
            }
            if(map.size()==k){
                max=Math.max(max,i-j+1);
            }
        }
        return max;
        
    }
}