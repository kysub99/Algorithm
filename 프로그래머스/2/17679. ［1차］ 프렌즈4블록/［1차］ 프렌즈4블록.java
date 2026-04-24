import java.util.*;

class Solution {
    
    int[] dr = {0,1,1};
    int[] dc = {1,0,1};
    char[][] board;
    
        
    public boolean isEqual(int r, int c){
        char cur = board[r][c];

        if (cur == '0') return false;

        return cur == board[r][c + 1]
            && cur == board[r + 1][c]
            && cur == board[r + 1][c + 1];
    }
    
    public void fillRemain(int m, int n){
        for(int j=0;j<n;j++){
            for(int i=m-1;i>=0;i--){
                if(board[i][j] == '0'){
                    int nr = i-1;
                    while(nr>=0 && board[nr][j] == '0'){
                        nr--;
                    }
                    if(nr>=0){
                        board[i][j] = board[nr][j];
                        board[nr][j] = '0';
                    }
                }
            }
        }
    }
    
    public boolean bomb(int m, int n){
        ArrayList<int[]> needErase = new ArrayList<>();
        boolean isErased=false;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                if(board[i][j] == '0'){
                    continue;
                }
                if(isEqual(i, j)){
                    isErased=true;
                    needErase.add(new int[]{i, j});
                    needErase.add(new int[]{i+dr[0], j+dc[0]});
                    needErase.add(new int[]{i+dr[1], j+dc[1]});
                    needErase.add(new int[]{i+dr[2], j+dc[2]});
                }
            }
        }
        for(int i=0;i<needErase.size();i++){
            int r = needErase.get(i)[0];
            int c = needErase.get(i)[1];
            board[r][c] = '0';
        }
        return isErased;
    }

    
    public int solution(int m, int n, String[] board2) {
        board = new char[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] = board2[i].charAt(j);
            }
        }
        while(true){
            boolean changed = bomb(m,n);
            if(!changed){
                break;
            }
            fillRemain(m,n);
        }
        int answer = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '0'){
                    answer++;
                }
            }
        }
        return answer;
    }
}