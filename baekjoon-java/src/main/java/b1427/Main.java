package b1427;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int[] nums = Arrays.stream(br.readLine().split(""))
                    .mapToInt(Integer::parseInt)
                    .boxed()
                    .sorted(Collections.reverseOrder())
                    .mapToInt(i -> i)
                    .toArray();
            System.out.println(toString(nums));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String toString(int[] nums) {
        StringBuilder sb = new StringBuilder();
        for (int num : nums) {
            sb.append(num);
        }
        return sb.toString();
    }
}
