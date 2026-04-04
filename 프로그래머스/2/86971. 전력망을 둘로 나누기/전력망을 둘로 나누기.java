import java.util.*;

class Solution {
    public int solution(int n, int[][] wires) {
        
        int res = Integer.MAX_VALUE;
        
        for(int i=0;i<wires.length;i++){
            List<Integer>[] graph = new ArrayList[n+1];
            for(int j=1;j<=n;j++){
                graph[j] = new ArrayList<>();
            }
            
            for(int j=0;j<wires.length;j++){
                if(i==j){
                    continue;
                }
                int a = wires[j][0];
                int b = wires[j][1];
                graph[a].add(b);
                graph[b].add(a);
            }
            
            boolean[] visited = new boolean[n+1];
            int cnt = bfs(1, graph, visited);
            res = Math.min(res, Math.abs(cnt - (n-cnt)));
        }
        return res;
    }
    
    public int bfs(int start, List<Integer>[] graph, boolean[] visited){
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start]=true;
        int cnt = 1;
        while(!q.isEmpty()){
            int cur = q.poll();
            
            for(int next : graph[cur]){
                if(!visited[next]){
                    visited[next] = true;
                    q.offer(next);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
}