import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        String[] answer = {};
        
        HashMap<String, String> m = new HashMap<>();
        
        for(String s : record){
            String[] parts = s.split(" ");
            if(parts[0].equals("Enter") || parts[0].equals("Change")){
                m.put(parts[1], parts[2]);
            }
        }
        
        ArrayList<String> log = new ArrayList<>();
        for(String s : record){
            String[] parts = s.split(" ");
            String name = m.get(parts[1]);
            
            if(parts[0].equals("Enter")){
                log.add(name+"님이 들어왔습니다.");
            }
            else if(parts[0].equals("Leave")){
                log.add(name+"님이 나갔습니다.");
            }
        }
        
        return log.toArray(new String[0]);
    }
}