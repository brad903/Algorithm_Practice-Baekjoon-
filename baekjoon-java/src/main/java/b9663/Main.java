package b9663;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static int[] memoRow;
    private static int n;
    private static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        memoRow = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            memoRow[1] = i;
            dfs(2);
            memoRow[1] = 0;
        }

        System.out.println(answer);
    }

    private static void dfs(int row) {
        if(row > n) answer++;
        for (int col = 1; col <= n; col++) {
            if(canPass(row, col)) {
                memoRow[row] = col;
                dfs(row + 1);
                memoRow[row] = 0;
            }
        }
    }

    private static boolean canPass(int row, int col) {
        return checkLeftDiagonal(row, col) && checkRightDiagonal(row, col) && checkUpper(row, col);
    }

    private static boolean checkUpper(int row, int col) {
        for (int i = 1; i < row; i++) {
            if(memoRow[row - i] == col) return false;
        }
        return true;
    }

    private static boolean checkRightDiagonal(int row, int col) {
        for (int i = 1; i < row; i++) {
            int nextCol = col + i;
            if(nextCol > n) return true;
            if(memoRow[row - i] == nextCol) return false;
        }
        return true;
    }

    private static boolean checkLeftDiagonal(int row, int col) {
        for (int i = 1; i < row; i++) {
            int nextCol = col - i;
            if(nextCol < 1) return true;
            if(memoRow[row - i] == nextCol) return false;
        }
        return true;
    }
}