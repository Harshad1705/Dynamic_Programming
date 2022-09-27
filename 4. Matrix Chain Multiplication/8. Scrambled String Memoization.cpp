class Solution {
public:
    
     bool solve(string a , string b , map<string,bool> &dp){
        
        if(a.compare(b)==0){
            return true;
        }
        
         
        string temp = a;
        temp.push_back(' ');
        temp.append(b);
         
         if(dp.find(temp) != dp.end()){
             return dp[temp];
         }
         
        
        bool flag = false;
        int n = a.length();
        
        for(int i=1 ;i<n;i++){
                  
            bool case1 = (solve(a.substr(0,i),b.substr(n-i,i),dp)&&solve(a.substr(i,n-i),b.substr(0,n-i),dp));
            bool case2 = (solve(a.substr(0,i),b.substr(0,i),dp)&&solve(a.substr(i,n-i),b.substr(i,n-i),dp));
            
            if(case1||case2){
                flag = true;
                break;
            }
            
        }
         
         dp[temp] = flag;
         
         return flag;
     }

    

    bool isScramble(string s1, string s2) {
        
        map<string,bool> dp;
        
        if(s1.length() != s2.length()){
            return false;
        }
        
        if(s1.length()==0 && s2.length()==0){
            return true;
        }
        
        return solve(s1,s2,dp);
    }
};