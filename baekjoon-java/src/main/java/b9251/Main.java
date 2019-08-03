package b9251;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] texts1 = br.readLine().split("");
        String[] texts2 = br.readLine().split("");

        int[][] memo = new int[texts1.length + 1][texts2.length + 1];
        for (int index1 = 1; index1 <= texts1.length; index1++) {
            for (int index2 = 1; index2 <= texts2.length; index2++) {
                if (texts1[index1 - 1].equals(texts2[index2 - 1])) {
                    memo[index1][index2] = memo[index1 - 1][index2 - 1] + 1;
                }
                int pastMax = Math.max(memo[index1 - 1][index2], memo[index1][index2 - 1]);
                memo[index1][index2] = Math.max(memo[index1][index2], pastMax);
            }
        }

        System.out.println(memo[texts1.length][texts2.length]);
    }
}
