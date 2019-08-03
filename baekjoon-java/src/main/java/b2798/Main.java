package b2798;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int max;
    private static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = br.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        max = Integer.parseInt(firstLine[1]);
        int[] nums = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] arr = new int[3];
        doCombination(arr, nums, n, 3, 0, 0);
        System.out.println(answer);
    }

    private static void doCombination(int[] space, int[] nums, int n, int r, int index, int target) {
        if (r == 0) {
            int sum = 0;
            for (int i = 0; i < index; i++) sum += nums[space[i]];
            if(canRenew(sum)) answer = sum;
            return;
        }
        if (target == n) return;

        space[index] = target;
        doCombination(space, nums, n, r - 1, index + 1, target + 1);
        doCombination(space, nums, n, r, index, target + 1);
    }

    private static boolean canRenew(int sum) {
        return sum <= max && ((max - sum) < (max - answer));
    }
}