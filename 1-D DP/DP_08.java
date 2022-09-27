
// count derangements

public class DP_08 {

    public static int countDerangement(int n){

        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }

        int ans =  (countDerangement(n-1) + countDerangement(n-2)); 
        ans = ans * (n-1);

        return ans;

    }
    public static void main(String[] args) {

        int n = 3;

        // by recursion
        System.out.println(countDerangement(n));

        // by top-down approach
        int[] dp = new int[n+1];
        for(int i=0;i<dp.length;i++){
            dp[i] = -1;
        }
        System.out.println(solve_1(n,dp));

        // by botton-up approach
        System.out.println(solve_2(n));

        // by space optimization
        System.out.println(solve_3(n));

    }


    private static int solve_3(int n) {

        int prev2 = 0;
        int prev1 = 1;

        for(int i=3 ; i<=n ; i++){
            int ans = (i-1) * ( prev1 + prev2 );
            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
    private static int solve_2(int n) {
        
        int[] dp = new int[n+1];

        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;

        for(int i=3 ; i<dp.length ; i++){
            dp[i] = (i-1) * (dp[n-1]+dp[n-2]);
        }

        return dp[n];
    }

    private static int solve_1(int n, int[] dp) {
        // step-1
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }

        // step-3
        if(dp[n]!=-1){
            return dp[n];
        }


        // step-2
        int ans = solve_1(n-1, dp) + solve_1(n-2, dp);
        ans = ans * (n-1);

        dp[n] =ans;

        return dp[n];

    }
    
}
