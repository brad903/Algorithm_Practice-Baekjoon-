package b1010;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static long[] nums = new long[30];

    static {
        nums[1] = 1;
        nums[2] = 2;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int[] arr = toArray(br.readLine());
            int N = arr[1];
            int M = arr[0];
            if (N == M) {
                System.out.println(1);
                continue;
            }

            if(N - M < M) M = N - M;
            long num = upperPart(N, M) / factoryMethod(M);
            System.out.println(num);
        }
    }

    public static long upperPart(int n, int i) {
        long num = 1;
        for (int j = 0; j < i; j++) {
            num *= n;
            n--;
        }
        return num;
    }

    private static int[] toArray(String readLine) {
        String[] arr = readLine.split(" ");
        return new int[]{Integer.parseInt(arr[0]), Integer.parseInt(arr[1])};
    }

    public static long factoryMethod(int n) {
        if (nums[n] > 0) return nums[n];
        nums[n] = n * factoryMethod(n - 1);
        return nums[n];
    }
}
