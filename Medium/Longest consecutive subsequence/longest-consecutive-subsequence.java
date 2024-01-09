//{ Driver Code Starts
//Initial Template for Java

import java.math.*;
import java.util.*;
import java.io.*;

class Driverclass
{
    // Driver Code
    static class FastReader{ 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
            } 
            return st.nextToken(); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
            return str; 
        } 

        Integer nextInt(){
            return Integer.parseInt(next());
        }
    }
    
	public static void main(String args[])
	{
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = sc.nextInt();
		
		while(t>0)
		{
			int n = sc.nextInt();
			int a[] = new int[n];
			
			for(int i=0; i<n; i++)
				a[i] = sc.nextInt();
		    out.println(new Solution().findLongestConseqSubseq(a, n));
		    t--;
		}
		out.close();
	}
}
// } Driver Code Ends


class Solution
{   
    
static int findLongestConseqSubseq(int arr[], int N)
{
    
        TreeSet<Integer> tr=new TreeSet<>();
 
        for(Integer num:arr)
        tr.add(num);
        int ar[]=new int[tr.size()];
int j=0;
    for(Integer in:tr)
    {
        ar[j++]=in;
    }
int length=0;
int count=1;
    for(int i=0;i<tr.size()-1;i++)
    {
     
if(ar[i+1]-ar[i]==1)
{
    count++;
}
else
{
    length=Math.max(count,length);
    count=1;
 
}  
    }
 
    return Math.max(count,length);
}
}
