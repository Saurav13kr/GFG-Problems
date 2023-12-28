//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.io.*;

public class Main
{
    public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		    String inputLine[] = br.readLine().trim().split(" ");
		    int n = Integer.parseInt(inputLine[0]);
		    int m = Integer.parseInt(inputLine[1]);
		    long arr1[] = new long[n];
		    long arr2[] = new long[m];
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<n; i++){
		        arr1[i] = Long.parseLong(inputLine[i]);
		    }
		    inputLine = br.readLine().trim().split(" ");
		    for(int i=0; i<m; i++){
		        arr2[i] = Long.parseLong(inputLine[i]);
		    }
		    Solution ob = new Solution();
		    ob.merge(arr1, arr2, n, m);
		    
		    StringBuffer str = new StringBuffer();
		    for(int i=0; i<n; i++){
		        str.append(arr1[i]+" ");
		    }
		    for(int i=0; i<m; i++){
		        str.append(arr2[i]+" ");
		    }
		    System.out.println(str);
		}
	}
}

// } Driver Code Ends

class Solution
{
    
    public static int binarySearch(long[] arr2, int s,int e, long val){
        int currentIndex = -1;
        while(s <= e){
            int mid = (s + e)/2;
            if(arr2[mid] > val){
                e = mid - 1;
            }else{
                currentIndex = mid;
                s = mid + 1;
            }
        }
        return currentIndex;
    }
    public static void merge(long arr1[], long arr2[], int n, int m) 
    {
        int j = 0;
        for(int i = 0; i < n; i++){
            if(arr1[i] > arr2[j]){
                long temp = arr1[i];
                arr1[i] = arr2[j];
                int index = binarySearch(arr2,0,m-1,temp);
                for(int k = 0; k < index; k++){
                    arr2[k] = arr2[k+1];
                }
                arr2[index] = temp;
                
            }
        }
    }
}

