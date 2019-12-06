package b5015;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    private static String P, N;
    private static int[][] cache;

    private static void initCache() {
        int[][] temp = new int[101][101];
        for (int[] ints : temp) {
            Arrays.fill(ints, -1);
        }
        cache = temp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        P = br.readLine();
        int count = Integer.parseInt(br.readLine());
        List<String> matched = new ArrayList<>();
        for (int j = 0; j < count; j++) {
            initCache();
            N = br.readLine();
            if (matchMemoized(0, 0) == 1) {
                matched.add(N);
            }
        }

        for (String s : matched) {
            System.out.println(s);
        }
    }

    private static int matchMemoized(int p, int n) {
        if (cache[p][n] != -1) return cache[p][n];

        while (p < P.length() && n < N.length() && P.charAt(p) == N.charAt(n)) {
            return cache[p][n] = matchMemoized(p + 1, n + 1);
        }

        if (p == P.length()) {
            boolean temp = (n == N.length());
            return cache[p][n] = temp ? 1 : 0;
        }

        if (P.charAt(p) == '*') {
            if (matchMemoized(p + 1, n) == 1 || (n < N.length() && matchMemoized(p, n + 1) == 1)) {
                return cache[p][n] = 1;
            }
        }
        return cache[p][n] = 0;
    }
}

