package b1920;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Set<Integer> nums = new HashSet<>();

        int n1 = Integer.parseInt(br.readLine());
        StringTokenizer stk1 = new StringTokenizer(br.readLine());
        for (int i = 0; i < n1; i++) {
            nums.add(Integer.parseInt(stk1.nextToken()));
        }

        int n2 = Integer.parseInt(br.readLine());
        StringTokenizer stk2 = new StringTokenizer(br.readLine());
        for (int i = 0; i < n2; i++) {
            int target = Integer.parseInt(stk2.nextToken());
            int result = nums.contains(target) ? 1 : 0;
            System.out.println(result);
        }
    }
}
