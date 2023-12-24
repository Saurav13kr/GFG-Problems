//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            String str=br.readLine();
    		String[] starr=str.split(" ");
    		
    		//input n and d
    	    int n=Integer.parseInt(starr[0]);
    		int k= Integer.parseInt(starr[1]);
            
            starr = br.readLine().trim().split(" ");
            int[] price = new int[n];
            for(int i = 0; i < n; i++)
                price[i] = Integer.parseInt(starr[i]);
            
            Solution obj = new Solution();
            int res = obj.buyMaximumProducts(n, k, price);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    
    public static int buyMaximumProducts(int n, int k, int[] price) {
        // code here
        HashMap<Integer, Integer> tMap = new HashMap<>();
        
        for(int i = 0; i < n; i++){
            tMap.put(i+1, price[i]);
        }
        int count = 0;
        ArrayList<Map.Entry<Integer, Integer>> entryList = new ArrayList<>(tMap.entrySet());
        entryList.sort(Map.Entry.comparingByValue());
        
        for (Map.Entry<Integer, Integer> mapElement : entryList) {
            
            // finding key
            int value = mapElement.getKey();
 
            // Finding value
            int key = mapElement.getValue();
            
            int keyByK = k / key;
            
            if(keyByK > value){
                k = k - (key*value);
                count += value;
            }
            else{
                k = k - (key*keyByK);
                count += keyByK;
                return count;
            }
        }
        
        return count;
    }

}
        
