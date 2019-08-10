package b10971;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static int N;
    private static int[][] costs;
    private static int[][] memo;

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            N = Integer.parseInt(br.readLine());
            costs = new int[N][N];
            memo = new int[N][1 << N];
            for (int i = 0; i < N; i++) {
                StringTokenizer stk = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    costs[i][j] = Integer.parseInt(stk.nextToken());
                }
            }

            int answer = TSP(0, 0);
            System.out.println(answer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int TSP(int now, int visited) {
        visited |= (1 << now);

        if(memo[now][visited] > 0) return memo[now][visited];
        if (visited == (1 << N) - 1) {
            if(costs[now][0] > 0) {
                return costs[now][0];
            }
            return Integer.MAX_VALUE / 2;
        }

        int cost = Integer.MAX_VALUE / 2;
        for (int i = 0; i < N; i++) {
            if (!isVisited(visited, i) && costs[now][i] > 0) {
                int temp = TSP(i, visited) + costs[now][i];
                if(temp < cost) cost = temp;
            }
        }
        return memo[now][visited] = cost;
    }

    private static boolean isVisited(int visited, int i) {
        return (visited & (1 << i)) != 0;
    }
}
