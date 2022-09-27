
// painting fence algorithm

public class DP_09 {
    public static void main(String[] args) {
        

        int n = 3; // post
        int k = 2; // color

        // by recursion
        System.out.println(solve(n,k));

        // by top-down approach
        int[] dp = new int[n+1];
        for(int i=0 ; i<dp.length ; i++){
            dp[i] = -1;
        }
        System.out.println(solve_1(n , k , dp));

        // by bottom-up approach
        System.out.println(solve_2(n,k));

        // space optimization
        System.out.println((solve_3(n, k)));
    }

    private static int solve_3(int n, int k) {

        int prev2 = k;
        int prev1 = k+(k*(k-1));

        for(int i=3 ; i<=n ; i++){
            int ans = (prev2*(k-1))  + (prev1*(k-1)) ;
            prev2 = prev1;
            prev1 = ans; 
        }

        return prev1;
    }

    private static int solve_2(int n, int k) {
       
        int[] dp = new int[n+1];

        dp[1] = k;
        dp[2] = k+(k*(k-1));

        for(int i=3 ; i<dp.length ; i++){
            dp[i] = (dp[i-2]*(k-1))  + (dp[i-1]*(k-1)) ; 
        }

        return dp[n];
    }

    private static int solve_1(int n, int k, int[] dp) {
        // base case
        if(n==1){
            return k;
        }
        if(n==2){
            return k + (k*(k-1));
        }

        // step-3
        if(dp[n]!=-1){
            return dp[n];
        }

        // step-2
        int ans = ((solve(n-2, k)*(k-1)) + (solve(n-1, k)*(k-1)));
        dp[n] = ans;

        return dp[n];

    }

    private static int solve(int n, int k) {

        if(n==1){
            return k;
        }
        if(n==2){
            return k+(k*(k-1));
        }
        
        int ans = (solve(n-2,k)*(k-1)) + (solve(n-1,k)*(k-1));   // same  + different
        return ans;
    }
}
