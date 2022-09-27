
// fibonacci by bottom-up approach

public class DP_02 {
    
    static int[] dp;

    public static int fib(int n){

        // Time complexity : O(n)
        // Space complexity : O(n)    // array
        
        // step -1 : create array
        dp = new int[n+1];

        // step -2 : base case
        dp[0] = 0;
        dp[1] = 1;

        // step -3 : caluculate value based on last two sum
        for(int i=2;i<dp.length;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        // return answer
        return dp[n];
    }

    // space optimization
    public static int fin2(int n){

        // Time complexity : O(n)
        // Space complexity : O(1)   

        // step -1 : create variabke
        int prev2 = 0;
        int prev1 = 1;

        if(n==0) return prev2; 

        // calculate value based on last two sum
        for(int i=2;i<dp.length;i++){
            // calculate sum
            int curr = prev1 + prev2;
            // shift variable
            prev2 = prev1;
            prev1 = curr;
        }
        // return answer
        return prev1;
    }



    public static void main(String[] args) {
        
        System.out.println(fib(6));
        System.out.println(fin2(6));
    }
}
