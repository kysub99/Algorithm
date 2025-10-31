import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        String[] arr = s.split(" ");
        List<Integer> list = new ArrayList<>();
        
        for(String cur : arr){
            list.add(Integer.parseInt(cur));
        }
        int minNum = Collections.min(list);
        int maxNum = Collections.max(list);
        answer = Integer.toString(minNum) + " " + Integer.toString(maxNum);
        
        return answer;
        
        
    }
}