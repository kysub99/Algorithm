import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        
        int maxW=0;
        int maxH=0;
        
        for(int[] cards:sizes){
            int w = Math.max(cards[0], cards[1]);
            int h = Math.min(cards[0], cards[1]);
            
            maxW = Math.max(maxW, w);
            maxH = Math.max(maxH, h);
        }
        
        return maxW * maxH;
    }
}