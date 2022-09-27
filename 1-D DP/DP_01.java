
// fibonacci by top-down approach

public class DP_01{

    static int[] dp ;

    public static int fib(int n){

        // Time complexity : O(n)
        // Space complexity : O(n) + O(n)   // array + recurssion

        dp = new int[n+1];
        // step -1
        for(int i=0;i<dp.length;i++){
            dp[i] = -1;
        }

        return func(n);
    }
    public static int func(int n){
        // base case
        if(n==0 || n==1){
            return n;
        }
        // step -3
        if(dp[n]!=-1){
            return dp[n];
        }
        // step -2
        dp[n] = func(n-1) + func(n-2);
        return dp[n];
    }


    public static void main(String[] args) {
        

        System.out.println(fib(6));

    }
    
}