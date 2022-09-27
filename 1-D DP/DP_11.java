
// Perfect square problem

public class DP_11 {

    public static void main(String[] args) {
        
        int n =  10;  // 2    // 3*3 + 1*1

        // by recursion
        System.out.println(solve(n));

        // by top-down approach
        int[] dp = new int[n+1];
        for(int i=0 ; i<dp.length;i++){
            dp[i] = -1;
        }
        System.out.println(solve_1(n,dp));

        // by bottom-up approach
        System.out.println(solve_2(n));
    }

    private static int solve_2(int n) {

        int[] dp = new int[n+1];

        for(int i=0 ; i<dp.length ; i++){
            dp[i] = Integer.MAX_VALUE;
        }

        dp[0] = 0;

        for(int i=1 ; i<dp.length ; i++){
            for(int j = 1 ; j*j<=n;j++){
                if(i-(j*j) >=0)
                    dp[i] = Math.min(dp[i], 1+ dp[i-(j*j)]);
            }
        }

        return dp[n];
    }

    private static int solve_1(int n, int[] dp) {
        if(n==0){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        int ans = n;
        for(int i=1 ;i*i<=n ; i++){
            ans = Math.min(ans , 1 + solve(n-(i*i)));
        }
        dp[n] = ans;
        return dp[n];
    }

    public static int solve(int n){

        if(n==0){
            return 0;
        }

        int ans = n;
        for(int i=1 ;i*i<=n ; i++){
            ans = Math.min(ans , 1 + solve(n-(i*i)));
        }

        return ans;
    }
    
}
