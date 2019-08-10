package b1562;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int N, VISIT = 1 << 10, MOD = 1000000000;
    public static long dp[][][] = new long[101][10][VISIT];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        System.out.println(calc());
    }

    private static long calc() {
        long sum = 0;

        /**
         * 1자리 수이면서,
         * 마지막 수가 i이고,
         * 1 << i로 해당 수가 나왓음을 마킹해둔다
         */
        for (int i = 1; i < 10; i++) {
            dp[1][i][1 << i] = 1;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < VISIT; k++) {
                    int bit = k | (1 << j);
                    dp[i][j][bit] = (dp[i][j][bit] +
                            ((j > 0 ? dp[i - 1][j - 1][k] : 0) +
                                    (j < 9 ? dp[i - 1][j + 1][k] : 0)) % MOD) % MOD;
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            sum = (sum + dp[N][i][VISIT - 1]) % MOD;
        }

        return sum;
    }
}
