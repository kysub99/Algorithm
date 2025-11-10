import java.util.*;

class Edge implements Comparable<Edge> {
    int cost, node;
    
    public Edge(int cost, int node){
        this.cost = cost;
        this.node = node;
    }
    
    @Override
    public int compareTo(Edge other){
        return this.cost - other.cost;
    }
}

class Solution {    
    
    List<Edge> graph[];
    int[] costArr;
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;

        graph = new ArrayList[N+1];
        costArr = new int[N+1];
        for(int i=1;i<=N;i++){
            graph[i] = new ArrayList<>();
            costArr[i] = -1;
        }
        
        for(int i=0;i<road.length;i++){
            int fn = road[i][0];
            int sn = road[i][1];
            int cost = road[i][2];
            graph[fn].add(new Edge(cost, sn));
            graph[sn].add(new Edge(cost, fn));
        }
        
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        
        costArr[1] = 0;
        pq.add(new Edge(0, 1));
        while(!pq.isEmpty()){
            Edge cur = pq.poll();
            int curCost = cur.cost;
            int curNode = cur.node;
            for(int i=0;i<graph[curNode].size();i++){
                Edge next = graph[curNode].get(i);
                int nextCost = next.cost;
                int nextNode = next.node;
                if(costArr[nextNode] == -1 ||
                   costArr[curNode] + nextCost < costArr[nextNode]){
                    costArr[nextNode] = costArr[curNode] + nextCost;
                    pq.add(next);
                }
            }
        }
        
        for(int i=1;i<costArr.length;i++){
            if(costArr[i] <= K){
                answer++;
            }
        }
        
        return answer;
    }
}