import java.util.*;

class Solution {
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        
        int[] arr = new int[n+1];
        for(int i=0;i<arr.length;i++){
            arr[i] = -1;
        }
        
        List<Integer>[] list = new ArrayList[n+1];
        
        for(int i=1;i<n+1;i++){
            list[i] = new ArrayList<>();
        }
        
        for(int i=0;i<roads.length;i++){
            list[roads[i][0]].add(roads[i][1]);
            list[roads[i][1]].add(roads[i][0]);
        }
        
        Queue<Integer> q = new LinkedList<>();
    
        arr[destination] = 0;
        q.add(destination);
        
        while(!q.isEmpty()){
            int cur = q.peek();
            for(int i=0;i<list[cur].size();i++){
                int next = list[cur].get(i);
                int nextDist = arr[cur] + 1;
                if(nextDist < arr[next] || arr[next] == -1){
                    arr[next] = nextDist;
                    q.add(next);
                }
            }
            q.remove();
        }
        
        int[] answer = new int[sources.length];
        for(int i=0;i<sources.length;i++){
            answer[i] = arr[sources[i]];
        }
        
        return answer;
    }
}