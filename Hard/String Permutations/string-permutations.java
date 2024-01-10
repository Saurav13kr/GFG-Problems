//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class Main {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int T=sc.nextInt();
		sc.nextLine();
		while(T-->0)
		{
		    
		    Solution ob=new Solution();
		    
		    String S=sc.nextLine();
		    
		    ArrayList<String> arr = ob.permutation(S);
		    for(String s : arr){
		        System.out.print(s+" ");
		    }
		    System.out.println();
		}
		
	}
}

// } Driver Code Ends


//User function Template for Java


class Solution
{
    public static ArrayList<String> findparam(String S,String ans,ArrayList<String> al){
        if(S.length()==0){
            al.add(ans);
            return al;
        }
        for(int i=0;i<S.length();i++){
            char curr = S.charAt(i);
            String newStr=S.substring(0,i)+S.substring(i+1);
            findparam(newStr,ans+curr,al);
        }
        return al;
    }
    public ArrayList<String> permutation(String S)
    {
        //Your code here
        ArrayList<String> al = new ArrayList<>();
        findparam(S,"",al);
        Collections.sort(al);
        return al;
        
    }
       
}


