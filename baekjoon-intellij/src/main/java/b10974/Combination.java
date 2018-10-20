package b10974;

import java.util.*;
import java.util.stream.IntStream;

public class Combination {
    static Set<String> answer = new HashSet<>();

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        int select = scan.nextInt();
        int[] array = IntStream.range(1, num + 1).toArray();
        combination(array, 0, num, select);
        List<String> sortedList = new ArrayList(answer);
        Collections.sort(sortedList);
        for (String s : sortedList) {
            System.out.println(s);
        }
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void combination(int[] arr, int d, int n, int r) {
        if (r == 0) {
            int[] temp = Arrays.copyOfRange(arr, 0, d);
            Arrays.sort(temp);
            answer.add(Arrays.toString(temp));
            return;
        }
        for (int i = d; i < n; i++) {
            swap(arr, d, i);
            combination(arr, d + 1, n, r - 1);
            swap(arr, d, i);
        }
    }

}
