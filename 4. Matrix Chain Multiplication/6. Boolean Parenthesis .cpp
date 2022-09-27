
class Solution{
    
    static Map<String, Integer> mp;
    
    static int solve(String s,int i, int j, boolean istrue)
    {
        
        if(i>j)
            return 0;
        if(i == j)
        {
            if(istrue == true)
                return (s.charAt(i) == 'T') ? 1:0;
            else
                return (s.charAt(i) == 'F') ? 1:0;
        }
        
        String temp = "";
        temp = temp + i+""+j+""+istrue;
        if(mp.containsKey(temp))
            return mp.get(temp);
        
        int ans = 0;
        int lt = 0, rt =0, lf = 0, rf = 0;
        for(int k = i+1; k<j; k = k+2)
        {
            lt = solve(s, i, k-1, true);
            lf = solve(s, i, k-1, false);
            rt = solve(s, k+1, j, true);
            rf = solve(s, k+1, j, false);
            
            if(s.charAt(k) == '&')
            {
                if(istrue == true)
                    ans = ans + lt*rt;
                else
                    ans = ans + lf*rt + lf*rf + lt*rf;
            }
            
            else if(s.charAt(k) == '|')
            {
                if(istrue == true)
                    ans = ans + lt*rt + lf*rt + lt*rf;
                else
                    ans = ans + lf*rf;
            }
            else if(s.charAt(k) == '^')
            {
                if(istrue == true)
                    ans = ans +lt*rf + lf*rt;
                else
                    ans = ans +lt*rt + lf*rf;
            }
        }
        mp.put(temp, ans%1003);
        return ans%1003;
        
    }
    
    static int countWays(int N, String S){
        
        mp = new HashMap<>();
        return solve(S,0,N-1,true);
        
    }
}