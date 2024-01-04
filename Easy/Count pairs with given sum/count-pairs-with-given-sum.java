//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int k = Integer.parseInt(inputLine[1]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            int ans = new Solution().getPairsCount(arr, n, k);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    int getPairsCount(int[] arr, int n, int k) {
        // code here
        HashMap<Integer, Integer> frequencyMap = new HashMap<>();
        int pairCount = 0;

        // Iterate through the array
        for (int num : arr) {
            // Check if complement (k - num) exists in the map
            if (frequencyMap.containsKey(k - num)) {
                pairCount += frequencyMap.get(k - num);
            }

            // Update the frequency of the current number in the map
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        return pairCount;
    }
}
