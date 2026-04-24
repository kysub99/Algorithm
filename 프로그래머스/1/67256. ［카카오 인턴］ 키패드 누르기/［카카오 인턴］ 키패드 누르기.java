import java.util.*;

class Solution {
    public String solution(int[] numbers, String hand) {
        StringBuilder sb = new StringBuilder();
        int[][] pos = {
            {3,1},
            {0,0}, {0,1}, {0,2},
            {1,0}, {1,1}, {1,2},
            {2,0}, {2,1}, {2,2}
        };
        int[] left = {3,0};
        int[] right = {3,2};
        
        for(int num:numbers){
            if(num==1 || num==4 || num==7){
                sb.append("L");
                left = pos[num];
            }
            else if(num==3 || num==6 || num==9){
                sb.append("R");
                right = pos[num];
            }
            else{
                int[] target = pos[num];
                
                int leftDist = Math.abs(left[0] - target[0]) + Math.abs(left[1] - target[1]);
                int rightDist = Math.abs(right[0] - target[0]) + Math.abs(right[1] - target[1]);
                
                if(leftDist < rightDist){
                    sb.append("L");
                    left = target;
                }
                else if(rightDist < leftDist){
                    sb.append("R");
                    right = target;
                }
                else{
                    if(hand.equals("right")){
                        sb.append("R");
                        right = target;
                    }
                    else{
                        sb.append("L");
                        left = target;
                    }
                }
            }
        }
        return sb.toString();
    }
}