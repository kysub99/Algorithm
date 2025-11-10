import java.util.*;

class Node {
    int r;
    int c;
    
    Node(int r, int c){
        this.r = r;
        this.c = c;
    }
}

class Solution {
    int n;
    int m;
    int[] dr = new int[]{-1,1,0,0};
    int[] dc = new int[]{0,0,-1,1};
    int[][] maps;
    boolean[][] visit;
    int[][] dis;
    
    boolean isIn(int r, int c){
        return (0<=r&&r<n&&0<=c&&c<m);
    }
    
    boolean canGo(int r, int c){
        return isIn(r, c) && maps[r][c] == 1;
    }

    public int solution(int[][] maps2) {
        int answer = 0;
        
        maps = maps2;
        n = maps.length;
        m = maps[0].length;
        visit = new boolean[n][m];
        dis = new int[n][m];
        dis[n-1][m-1] = -1;
        
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0,0));
        dis[0][0] = 1;
        visit[0][0] = true;
        
        while(!q.isEmpty()){
            Node cur = q.poll();
            int curR = cur.r;
            int curC = cur.c;
            for(int i=0;i<4;i++){
                int nextR = curR+dr[i];
                int nextC = curC+dc[i];
                if(canGo(nextR, nextC) && visit[nextR][nextC] == false){
                    visit[nextR][nextC] = true;
                    dis[nextR][nextC] = dis[curR][curC]+1;
                    q.add(new Node(nextR, nextC));
                }
            }
        }
        
        answer = dis[n-1][m-1];
        return answer;
    }
}