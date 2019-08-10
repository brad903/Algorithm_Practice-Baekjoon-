package b2163;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = toArray(br.readLine());
        System.out.println(arr[0] * arr[1] - 1);
    }

    private static int[] toArray(String readLine) {
        String[] arr = readLine.split(" ");
        return new int[]{Integer.parseInt(arr[0]), Integer.parseInt(arr[1])};
    }
}
