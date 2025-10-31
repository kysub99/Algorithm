import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;

        Stack<Integer> st = new Stack<>();
        
        for(char c : s.toCharArray()){
            if(c=='('){
                st.push(1);
            }
            else if(c==')'){
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
        }
        
        if(!st.empty()){
            return false;
        }

        return answer;
    }
}