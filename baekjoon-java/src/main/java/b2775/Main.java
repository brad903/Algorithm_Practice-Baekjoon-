package b2775;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static final int MAX = 15;
    private static int[][] apt = new int[MAX][MAX];

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            initialize();
            fillUp();

            int N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                int floor = Integer.parseInt(br.readLine());
                int ho = Integer.parseInt(br.readLine());
                System.out.println(apt[floor][ho]);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void fillUp() {
        for (int i = 1; i < MAX; i++) {
            for (int j = 2; j < MAX; j++) {
                apt[i][j] = apt[i - 1][j] + apt[i][j - 1];
            }
        }
    }

    private static void initialize() {
        for (int i = 0; i < MAX; i++) {
            apt[0][i] = i;
            apt[i][1] = 1;
        }
    }

    // for debugging
    private static void printApt() {
        for (int[] ints : apt) {
            for (int anInt : ints) {
                System.out.printf("%10d", anInt);
            }
            System.out.println();
        }
    }
}
