import java.util.*;

class Solution {
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    boolean[][] visit;
    String[] maps2;
    int rLen, cLen;

    boolean isIn(int r, int c) {
        return r >= 0 && r < rLen && c >= 0 && c < cLen && maps2[r].charAt(c) != 'X';
    }

    int dfs(int r, int c) {
        visit[r][c] = true;
        int sum = maps2[r].charAt(c) - '0'; 
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (isIn(nr, nc) && !visit[nr][nc]) {
                sum += dfs(nr, nc);
            }
        }
        return sum;
    }

    public int[] solution(String[] maps) {
        List<Integer> list = new ArrayList<>();
        rLen = maps.length;
        cLen = maps[0].length();
        visit = new boolean[rLen][cLen];
        maps2 = maps;

        for (int i = 0; i < rLen; i++) {
            for (int j = 0; j < cLen; j++) {
                if (!visit[i][j] && maps2[i].charAt(j) != 'X') {
                    list.add(dfs(i, j));
                }
            }
        }

        if (list.isEmpty()) return new int[]{-1};

        Collections.sort(list);
        return list.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}
