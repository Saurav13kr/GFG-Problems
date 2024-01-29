//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            sc.nextLine();
            String s = sc.next();
            Solution obj = new Solution();
            String ans = obj.postToPre(s);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends

class Solution {
    static String postToPre(String post_exp) {
        Stack <String> s= new Stack<>();
        for(int i=0; i<post_exp.length(); i++){
            char c= post_exp.charAt(i);
            if(Character.isLetter(c))s.push(String.valueOf(c));
            else{
                String v=s.pop();
                s.push(c+s.pop()+v);
            }
        }
        return s.pop();
    }
}
