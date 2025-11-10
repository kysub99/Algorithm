import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        boolean[] visit = new boolean[n];
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(computers[i][k] == 1 && computers[k][j] == 1){
                        computers[i][j] = 1;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(visit[i]==false){
                answer++;
                visit[i] = true;
                for(int j=0;j<n;j++){
                    if(computers[i][j] == 1 && visit[j] == false){
                        visit[j] = true;
                    }
                }
            }
        }
        
        return answer;
    }
}