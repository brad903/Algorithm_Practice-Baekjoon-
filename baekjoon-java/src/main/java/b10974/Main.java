package b10974;

import java.util.*;
import java.util.stream.IntStream;

public class Main {
    static List<String> answer = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        int[] array = IntStream.range(1, num + 1).toArray();
        permutation(array, 0, num, num);
        Collections.sort(answer);
        for (String s : answer) {
            System.out.println(s);
        }
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void permutation(int[] arr, int d, int n, int r) {
        if (r == 0) {
            StringBuffer sb = new StringBuffer();
            for (int i : Arrays.copyOfRange(arr, 0, d)) {
                sb.append(String.valueOf(i) + " ");
            }
            answer.add(sb.toString());
            return;
        }
        for (int i = d; i < n; i++) {
            swap(arr, d, i);
            permutation(arr, d + 1, n, r - 1);
            swap(arr, d, i);
        }
    }

}
