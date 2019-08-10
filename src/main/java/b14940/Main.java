package b14940;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(s -> Integer.parseInt(s)).toArray();
        int rowNum = input[0];
        int colNum = input[1];
        int[][] d = new int[rowNum][colNum];
        int[][] check = new int[rowNum][colNum];
        int[][] answer = new int[rowNum][colNum];
        int startR = 0, startC = 0;
        Queue<Point> q = new LinkedList<>();
        int[] directRow = {0, 0, -1, 1};
        int[] directCol = {1, -1, 0, 0};

        // 입력
        for (int i = 0; i < rowNum; i++) {
            int[] rowArr = Arrays.stream(br.readLine().split(" ")).mapToInt(s -> Integer.parseInt(s)).toArray();
            for (int j = 0; j < colNum; j++) {
                d[i][j] = rowArr[j];
                answer[i][j] = -1;
                if(rowArr[j] == 2) {
                    startR = i; startC = j;
                    check[startR][startC] = 1;
                    answer[startR][startC] = 0;
                }
                if(rowArr[j] == 0) {
                    answer[i][j] = 0;
                }
            }
        }

        // 맨 처음 큐에 넣기
        for (int i = 0; i < directCol.length; i++) {
            int tempRow = startR + directRow[i];
            int tempCol = startC + directCol[i];
            if(tempCol > -1 && tempCol < colNum && tempRow > -1 && tempRow < rowNum && d[tempRow][tempCol] != 0) {
                Point point = new Point(tempRow, tempCol);
                q.offer(point);
                point.distance = 1;
                check[tempRow][tempCol] = 1;
                answer[tempRow][tempCol] = 1;
            }
        }

        while(!q.isEmpty()) {
            Point point = q.poll();
            for (int i = 0; i < directRow.length; i++) {
                int tempRow = point.row + directRow[i];
                int tempCol = point.col + directCol[i];
                if(tempCol > -1 && tempCol < colNum && tempRow > -1 && tempRow < rowNum) {
                    if(d[tempRow][tempCol] == 1 && check[tempRow][tempCol] == 0) {
                        Point nextPoint = new Point(tempRow, tempCol);
                        nextPoint.distance = point.distance + 1;
                        q.offer(nextPoint);
                        check[tempRow][tempCol] = 1;
                        answer[tempRow][tempCol] = point.distance + 1;
                    } else {
                        check[tempRow][tempCol] = 1;
                    }
                }
            }
        }

        for (int[] ints : answer) {
            for (int anInt : ints) {
                System.out.print(anInt + " ");
            }
            System.out.println();
        }
    }
}

class Point {
    int row;
    int col;
    int distance;

    public Point(int x, int y) {
        this.row = x;
        this.col = y;
    }
}
