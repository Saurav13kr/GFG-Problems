//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s1 = br.readLine();
            String[] S = s1.split(" ");
            String s = S[0];
            String t = S[1];
            Solution ob = new Solution();
            int ans = ob.editDistance(s, t);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


class Solution {
    int memo[][];
    public int editDistance(String s, String t) {
       
        
        memo=new int[s.length()+1][t.length()+1];
        for(int[] r:memo)
        {
            Arrays.fill(r,-1);
        }
        int ans=recursion(s,t);
        return ans;
    }
    public int recursion(String s,String t)
    {
        if(s.length()==0) return t.length();
        if(t.length()==0) return s.length();

        if(memo[s.length()][t.length()]!=-1) return memo[s.length()][t.length()];

        if(s.charAt(0)==t.charAt(0)) return memo[s.length()][t.length()]= recursion(s.substring(1),t.substring(1));
        else
        {
            int insert=recursion(s,t.substring(1));   

            int delete=recursion(s.substring(1),t);

            int substitute=recursion(s.substring(1),t.substring(1));

            return memo[s.length()][t.length()]=1+Math.min(insert,Math.min(delete,substitute));
        }
        
    }
}