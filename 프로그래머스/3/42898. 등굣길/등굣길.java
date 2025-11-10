class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int MOD = 1_000_000_007;
        int answer = 0;
        
        
        int[][] dp = new int[m+1][n+1];
        for(int i=0;i<puddles.length;i++){
            int r = puddles[i][0];
            int c = puddles[i][1];
            dp[r][c] = -1;
        }
        
        dp[1][1] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1&&j==1)
                    continue;
                if(dp[i][j] == -1){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
                dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
            }
        }
        answer = dp[m][n];
        return answer;
    }
}