import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<progresses.length;i++){
            int day = (int) Math.ceil(((100.0-progresses[i])) / speeds[i]);
            q.add(day);
        }
        
        List<Integer> list = new ArrayList<>();
        int cur = q.poll();
        int cnt=1;
        while(!q.isEmpty()){
            int next = q.poll();
            if(next<=cur){
                cnt++;
            } else{
                list.add(cnt);
                cur = next;
                cnt=1;
            }
        }
        list.add(cnt);
        
        answer = list.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}