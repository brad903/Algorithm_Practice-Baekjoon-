package b1648;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int N, M;
    private static int[][] d = new int[14 * 14][1 << 14];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        initArray();

        System.out.println(go(0, 0));
    }

    private static int go(int num, int state) {
        if (num == N * M && state == 0) return 1;
        if (num >= N * M) return 0;


        if (d[num][state] != -1) return d[num][state];

        int ans;
        if ((state & 1) == 1) {
            ans = go(num + 1, (state >> 1));
        } else {
            ans = go(num + 1, (state >> 1) | (1 << (M - 1)));
            if ((num % M) != (M - 1) && (state & 2) == 0) {
                ans += go(num + 2, (state >> 2));
            }
        }
        return d[num][state] = ans % 9901;
    }

    private static void initArray() {
        for (int[] ints : d) {
            Arrays.fill(ints, -1);
        }
    }
}
