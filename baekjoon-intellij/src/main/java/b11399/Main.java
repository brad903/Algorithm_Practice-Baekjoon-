package b11399;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int answer = 0;
        int n = Integer.parseInt(br.readLine());
        int[] arr = toArray(br.readLine());
        Arrays.sort(arr);
        for (int i : arr) {
            answer += (i * n);
            n--;
        }
        System.out.println(answer);
    }

    private static int[] toArray(String line) {
        String[] arr = line.split(" ");
        int[] intArr = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            intArr[i] = Integer.parseInt(arr[i]);
        }
        return intArr;
    }
}
