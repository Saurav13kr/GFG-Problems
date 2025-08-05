import java.util.*;

public class Solution {
    public boolean isPalinSent(String s) {
        
        s = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();

        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();  
        Solution sol = new Solution();
        boolean result = sol.isPalinSent(s);
        System.out.println(result);
    }
}