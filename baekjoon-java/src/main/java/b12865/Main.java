package b12865;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] m = br.readLine().split(" ");
        final int N = Integer.parseInt(m[0]);
        final int C = Integer.parseInt(m[1]);
        // dp[a][b] : a개 선택하고 b 용량에서 가장 최고의 가치
        int[][] dp = new int[N + 1][C + 1];

        for (int i = 1; i <= N; i++) {
            String[] t = br.readLine().split(" ");
            int w = Integer.parseInt(t[0]);
            int v = Integer.parseInt(t[1]);

            for (int j = 0; j <= C; j++) {
                if (j < w) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w] + v);
            }
        }
        System.out.println(dp[N][C]);
    }
}
