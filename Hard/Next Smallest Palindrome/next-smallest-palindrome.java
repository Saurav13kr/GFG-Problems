//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            int num[] = new int[n];
            String[] str = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                num[i] = Integer.parseInt(str[i]);
            }

            Vector<Integer> ans = new Solution().generateNextPalindrome(num, n);
            for (Integer x : ans) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends

class Solution {

    boolean allnine(int num[]){
        if(num.length==0)
        return false;
        for(int i=0;i<num.length;i++){
            if(num[i]!=9)
            return false;
        }
        return true;
    }

    Vector<Integer> generateNextPalindrome(int num[], int n) {
        
        Vector<Integer> list = new Vector<>();
        
        if(allnine(num)){
            list.add(1);
            for(int i=0;i<n-1;i++){
                list.add(0);
            }
            list.add(1);
            return list;
        }
          int mid=n/2;
            int l=mid-1;
            int r=(n%2==0)?mid:mid+1;
            while(l>=0 && num[l]==num[r]){
                l--;
                r++;
            }
            boolean leftsmall=false;    //if leftsmall is false then simply copying is required
            
            if(l<0||num[l]<num[r]){
                leftsmall=true;         //copying then increment is also required
            }
            while(l>=0){    //copying
                num[r++]=num[l--];
            }
            if(leftsmall){                      //increments required
                int carry=1;
                if(n%2==1){                     //incrementing middle if odd
                    num[mid]+=1;
                    carry=num[mid]/10;
                    num[mid]%=10;
                }
                l=mid-1;
                r=(n%2==0?mid:mid+1);
                
                while(l>=0 && carry>0){        //incrementing sides in case of both odd & even
                    num[l]=num[l]+carry;
                    carry=num[l]/10;
                    num[l]%=10;
                    num[r]=num[l];
                    l--;r++;
                    
                }
            }
            
         for(int i=0;i<n;i++){
             list.add(num[i]);
         }   
        return list;
    }
    
}

