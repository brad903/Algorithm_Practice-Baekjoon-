package b2293;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = toArray(br.readLine());
        int n = arr[0];
        int sum = arr[1];
        List<Integer> coins = getCoins(n, br);
        int[][] d = new int[coins.size() + 1][sum + 1];
        init(d);

        for (int row = 1; row <= coins.size(); row++) {
            int coin = coins.get(row - 1);
            for (int col = 1; col <= sum; col++) {
                if(col < coin) {
                    d[row][col] = d[row - 1][col];
                    continue;
                }
                d[row][col] = d[row - 1][col] + d[row][col - coin];
            }
        }

        System.out.println(d[coins.size()][sum]);
    }

    private static void init(int[][] d) {
        for (int i = 0; i < d.length; i++) {
            d[i][0] = 1;
        }
    }

    private static List<Integer> getCoins(int n, BufferedReader br) throws IOException {
        List<Integer> coins = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            coins.add(Integer.parseInt(br.readLine()));
        }
        Collections.sort(coins);
        return coins;
    }

    private static int[] toArray(String readLine) {
        String[] arr = readLine.split(" ");
        return new int[]{Integer.parseInt(arr[0]), Integer.parseInt(arr[1])};
    }
}
