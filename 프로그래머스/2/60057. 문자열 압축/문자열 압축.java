import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = s.length();
        for(int len = 1; len <= s.length()/2; len++){
            StringBuilder compressed = new StringBuilder();
            
            String prev = s.substring(0, len);
            int cnt=1;
            
            for(int i=len;i<s.length();i+=len){
                String cur = s.substring(i, Math.min(i+len, s.length()));
                if(cur.equals(prev)){
                    cnt++;
                }
                else{
                    append(compressed, prev, cnt);
                    prev = cur;
                    cnt=1;
                }
            }
            
            append(compressed, prev, cnt);
            
            answer = Math.min(answer, compressed.length());
        }
        
        return answer;
    }
    
    public void append(StringBuilder compressed, String prev, int cnt){ 
        if(cnt>1){
            compressed.append(cnt).append(prev);
        }
        else{
            compressed.append(prev);
        }
    }
}