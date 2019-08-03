package b1149;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = Integer.parseInt(scan.next());
        int[][] data = new int[N][3];
        int[][] cost = new int[N][3];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                int tempData = scan.nextInt();
                data[i][j] = tempData;
            }
        }

        cost[0][0] = data[0][0];
        cost[0][1] = data[0][1];
        cost[0][2] = data[0][2];
        for (int i = 1; i < N; i++) {
            cost[i][0] = data[i][0] + Math.min(cost[i-1][1], cost[i-1][2]);
            cost[i][1] = data[i][1] + Math.min(cost[i-1][0], cost[i-1][2]);
            cost[i][2] = data[i][2] + Math.min(cost[i-1][0], cost[i-1][1]);
        }

        System.out.println(Math.min(cost[N-1][0], Math.min(cost[N-1][1], cost[N-1][2])));
    }
}
