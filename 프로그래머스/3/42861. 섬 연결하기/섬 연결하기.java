import java.util.*;

class Solution {
    public int solution(int n, int[][] costs) {
        int answer = 0;
        List<Integer[]>[] graph = new ArrayList[n];
        for(int i=0;i<n;i++){
            graph[i] = new ArrayList<>();
        }
        
        for(int i=0;i<costs.length;i++){
            int fn = costs[i][0];
            int sn = costs[i][1];
            int dis = costs[i][2];
            graph[fn].add(new Integer[]{dis, sn});
            graph[sn].add(new Integer[]{dis, fn});
        }
        
        
        boolean[] visit = new boolean[n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0,0});
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            int curCost = cur[0];
            int curNode = cur[1];
            if(visit[curNode] == false){
                visit[curNode] = true;
                answer += curCost;
                for(int i=0;i<graph[curNode].size();i++){
                    Integer[] next = graph[curNode].get(i);
                    int nextCost = next[0];
                    int nextNode = next[1];
                    if(visit[nextNode] == false){
                        pq.add(new int[]{nextCost, nextNode});
                    }
                }
            }
        }
        return answer;
    }
}