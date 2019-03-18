package b1932;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] d = new int[n];
        d[0] = Integer.parseInt(br.readLine());

        for (int i = 1; i < n; i++) {
            int[] arr = toArray(br.readLine());
            for (int j = 0; j < arr.length; j++) {
                if (j == 0) arr[j] += d[j];
                if (j == arr.length - 1) arr[j] += d[j - 1];

                if (j > 0 && j < arr.length - 1) {
                    arr[j] += Math.max(d[j - 1], d[j]);
                }
            }
            reflect(d, arr);
        }
    }

    private static void reflect(int[] d, int[] arr) {
        int max = 0;
        for (int i = 0; i < arr.length; i++) {
            d[i] = arr[i];
            max = Math.max(max, d[i]);
        }
        if(d.length == arr.length) System.out.println(max);
    }

    private static int[] toArray(String readLine) {
        String[] splitted = readLine.split(" ");
        int[] arr = new int[splitted.length];
        for (int i = 0; i < splitted.length; i++) {
            arr[i] = Integer.parseInt(splitted[i]);
        }
        return arr;
    }
}
