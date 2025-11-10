import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] arr = new String[numbers.length];
        for(int i=0;i<numbers.length;i++){
            arr[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(arr, (a,b) -> (b+a).compareTo(a+b));
        
        for(int i=0;i<arr.length;i++){
            answer += arr[i];
        }
        
        if(answer.charAt(0) == '0')
            return "0";
        
        return answer;
    }
}