class Solution {
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        
        int[][] panel = new int[board.length+1][board[0].length+1];
        
        for(int i=0;i<skill.length;i++){
            int degree = skill[i][5];
            if(skill[i][0] == 1){
                degree *= -1;
            }
            int r1 = skill[i][1];
            int c1 = skill[i][2];
            int r2 = skill[i][3];
            int c2 = skill[i][4];
            panel[r1][c1] += degree;
            panel[r1][c2+1] -= degree;
            panel[r2+1][c1] -= degree;
            panel[r2+1][c2+1] += degree;
        }
        
        for(int i=0;i<panel.length;i++){
            for(int j=1;j<panel[i].length;j++){
                panel[i][j] += panel[i][j-1];
            }
        }
        
        for(int i=1;i<panel.length;i++){
            for(int j=0;j<panel[i].length;j++){
                panel[i][j] += panel[i-1][j];
            }
        }
        
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][j] + panel[i][j] > 0){
                    answer++;
                }
            }
        }
        
        return answer;
    }
}