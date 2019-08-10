package b11047;

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
        int answer = 0;
        int n = arr[0];
        int change = arr[1];
        List<Integer> coins = getCoins(n, br);

        while(change != 0) {
            for (Integer coin : coins) {
                int quotient = change / coin;
                if(quotient > 0) {
                    answer += quotient;
                    change = change % coin;
                    break;
                }
            }
        }

        System.out.println(answer);
    }

    private static List<Integer> getCoins(int n, BufferedReader br) throws IOException {
        List<Integer> coins = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            coins.add(Integer.parseInt(br.readLine()));
        }
        coins.sort(Collections.reverseOrder());
        return coins;
    }

    private static int[] toArray(String readLine) {
        String[] arr = readLine.split(" ");
        return new int[]{Integer.parseInt(arr[0]), Integer.parseInt(arr[1])};
    }
}
