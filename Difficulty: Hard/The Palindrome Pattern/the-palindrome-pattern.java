
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        Solution ob = new Solution();
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String input_line[] = read.readLine().trim().split("\\s+");
            int n = Integer.parseInt(input_line[0]);
            String input_line1[] = read.readLine().trim().split("\\s+");
            int[][] a = new int[n][n];
            int c = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            String ans = ob.pattern(a);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public String pattern(int[][] arr) {
        // Code here
        String ans="-1";
        for(int i=0;i<arr.length;i++)
        {
            if(palindromeRow(arr[i])){
                return String.valueOf(i)+" R";
            }
        }
        for(int i=0;i<arr[0].length;i++){
            if(palindromeColumn(i,arr)){
                return String.valueOf(i)+" C";
            }
        }
        return ans;
        
    }
    
    public boolean palindromeRow(int[] A){
        int i=0,j=A.length-1;
        while(i<j){
            if(A[i]!=A[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public boolean palindromeColumn(int column,int[][] A)
    {
        int i=0;
        int j=A.length-1;
        while(i<j){
            if(A[i][column]!=A[j][column]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
}


