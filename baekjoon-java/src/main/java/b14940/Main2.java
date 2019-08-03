package b14940;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(stk.nextToken());
        int c = Integer.parseInt(stk.nextToken());
        int[][] map = new int[r][c];
        int[][] ans = new int[r][c];
        int startR = 0;
        int startC = 0;
        for (int i = 0; i < r; i++) {
            stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < c; j++) {
                map[i][j] = Integer.parseInt(stk.nextToken());
                ans[i][j] = -1;
                if (map[i][j] == 2) {
                    startR = i;
                    startC = j;
                }
                if (map[i][j] == 0) {
                    ans[i][j] = 0;
                }
            }
        }

        int[] dr = {0, 0, -1, 1};
        int[] dc = {1, -1, 0, 0};
        boolean[][] visited = new boolean[r][c];
        ans[startR][startC] = 0;
        visited[startR][startC] = true;

        Queue<Pair> queue = new LinkedList<>();
        for (int i = 0; i < dr.length; i++) {
            queue.add(new Pair(startR + dr[i], startC + dc[i], 1));
        }

        while (!queue.isEmpty()) {
            Pair t = queue.poll();
            if(t.c < 0 || t.c >= c || t.r < 0 || t.r >= r) continue;
            if(visited[t.r][t.c]) continue;
            if(map[t.r][t.c] == 0) continue;
            visited[t.r][t.c] = true;
            ans[t.r][t.c] = t.w;
            for (int i = 0; i < dr.length; i++) {
                queue.add(new Pair(t.r + dr[i], t.c + dc[i], t.w + 1));
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int[] an : ans) {
            for (int i : an) {
                sb.append(i + " ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }
}

class Pair {
    int r, c, w;

    public Pair(int r, int c, int w) {
        this.r = r;
        this.c = c;
        this.w = w;
    }
}
