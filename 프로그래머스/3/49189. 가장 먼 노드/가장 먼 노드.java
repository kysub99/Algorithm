import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        List<Integer>[] graph = new ArrayList[n+1];
        boolean[] visit = new boolean[n+1];
        int[] dis = new int[n+1];
        for(int i=1;i<=n;i++){
            graph[i] = new ArrayList<>();
            visit[i] = false;
            dis[i] = 0;
        }
        
        
        for(int i=0;i<edge.length;i++){
            int fn = edge[i][0];
            int sn = edge[i][1];
            graph[fn].add(sn);
            graph[sn].add(fn);
        }
        
        Queue<Integer> pq = new ArrayDeque<>();
        
        dis[1] = 0;
        visit[1] = true;
        pq.add(1);
        while(!pq.isEmpty()){
            int cur = pq.poll();
            for(int i=0;i<graph[cur].size();i++){
                int next = graph[cur].get(i);
                if(visit[next] == false){
                    dis[next] = dis[cur] + 1;
                    visit[next] = true;
                    pq.add(next);
                }
            }
        }
        
        int maxDis = 0;
        for(int i=1;i<=n;i++){
            maxDis = Math.max(maxDis, dis[i]);
        }
        
        
        int count = 0;
        for(int i=1;i<=n;i++){
            if(dis[i] == maxDis)
                count++;
        }
        
        return count;
    }
}