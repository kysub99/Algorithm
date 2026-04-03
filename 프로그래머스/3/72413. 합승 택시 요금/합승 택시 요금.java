import java.util.*;

class Solution {
    
    static class Edge{
        int cost;
        int node;
        
        Edge(int cost, int node){
            this.cost = cost;
            this.node = node;
        }
    }
    
    static final int INF = 100000001;
    static List<Edge>[] graph;
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        graph = new ArrayList[n+1];
        
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for(int i=0;i<fares.length;i++){
            int node1 = fares[i][0];
            int node2 = fares[i][1];
            int cost = fares[i][2];
            graph[node1].add(new Edge(cost, node2));
            graph[node2].add(new Edge(cost, node1));
        }
        
        int[] distS = dijkstra(n, s);
        int[] distA = dijkstra(n, a);
        int[] distB = dijkstra(n, b);
        
        int ans = INF;
        for(int i=1;i<=n;i++){
            ans = Math.min(ans, distS[i] + distA[i] + distB[i]);
        }
        
        return ans;
    }
    
    private int[] dijkstra(int n, int start){
        int[] dist = new int[n+1];
        Arrays.fill(dist, INF);
        
        PriorityQueue<Edge> pq = new PriorityQueue<>((x,y)->x.cost-y.cost);
        dist[start]=0;
        pq.offer(new Edge(0, start));
        
        while(!pq.isEmpty()){
            Edge cur = pq.poll();
            
            if(dist[cur.node] < cur.cost){
                continue;
            }
            
            for(Edge next : graph[cur.node]){
                if(dist[next.node] > cur.cost + next.cost) {
                    dist[next.node] = cur.cost + next.cost;
                    pq.offer(new Edge(dist[next.node], next.node));
                }
            }
        }
        return dist;
    }
}