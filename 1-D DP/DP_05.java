
// Maximum sum of non-adjacent elements

public class DP_05 {

    public static void main(String[] args) {

        int[] arr = {9,9,8,2};
        int n = 4;

        // by recurssion
        System.out.println(solve(arr,n-1));

        // by top-down approach
        int[] dp = new int[n+1];
        for(int i=0 ; i<dp.length ; i++){
            dp[i] = -1;
        }
        System.out.println(solve_2(arr,n-1,dp));

        // by bottom-up approach
        System.out.println(solve_3(arr,n-1));

        // by space optimization
        System.out.println(solve_4(arr,n-1));

    }

    private static int solve_4(int[] arr, int n) {

        int prev2 = 0 ;
        int prev1 = arr[0];

        for(int i=1 ; i<arr.length ;i++){
        
            int include = prev2 + arr[i]; 
            int exclude = prev1 + 0;
            
            int ans = Math.max(include,exclude);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;

    }

    private static int solve_3(int[] arr, int n) {

        int[] dp = new int[n+1];

        dp[0] = arr[0];

        for(int i=1 ; i<dp.length ; i++){
            int include = 0 ;
            int exclude = 0;

            if(i-2 >=0){
                include = dp[i-2] + arr[i];
            }
            if(i-1 >=0){
                exclude = dp[i-1] + 0;
            }

            dp[i] = Math.max(include,exclude);
        }

        return dp[n];
        
    }

    private static int solve_2(int[] arr, int n, int[] dp) {
        // step-1 : base case
        if(n<0){
            return 0;
        }
        if(n==0){
            return arr[0];
        }

        // step-3
        if(dp[n]!=-1){
            return dp[n];
        }

        // step-2 : calculate value for new values
        int include = solve_2(arr, n-2,dp) + arr[n];
        int exclude = solve_2(arr, n-1,dp) + 0;

        dp[n] = Math.max(include , exclude);

        return dp[n];
    }

    private static int solve(int[] arr, int n) {
        // Base case
        if(n<0){
            return 0;
        }
        if(n==0){
            return arr[0];
        }

        int include = solve(arr, n-2) + arr[n];
        int exclude = solve(arr, n-1) + 0;

        int answer = Math.max(include, exclude);

        return answer;
    }
    
}
