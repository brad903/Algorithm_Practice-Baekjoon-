package b2098;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private static int[][] costs;
    private static int[][] memo;
    private static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        costs = new int[n][n];
        memo = new int[1 << n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                costs[i][j] = Integer.parseInt(stk.nextToken());
            }
        }

        int answer = TSP(0, 0);

        System.out.println(answer);
    }

    private static int TSP(int visit, int now) {
        visit |= (1 << now);

        int cost = memo[visit][now];
        if (cost > 0) return cost;

        if (visit == (1 << n) - 1) {
            if (costs[now][0] > 0) {
                return costs[now][0];
            }
            return Integer.MAX_VALUE / 2;
        }

        cost = Integer.MAX_VALUE / 2;
        for (int i = 0; i < n; i++) {
            if (!isVisited(visit, i) && costs[now][i] > 0) {
                int temp = TSP(visit, i) + costs[now][i];
                if (cost > temp) cost = temp;
            }
        }
        return memo[visit][now] = cost;
    }

    private static boolean isVisited(int visit, int i) {
        return (visit & (1 << i)) != 0;
    }
}
