package b10989;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            Map<Integer, Integer> nums = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int num = Integer.parseInt(br.readLine());
                int value = nums.getOrDefault(num, 0) + 1;
                nums.put(num, value);
            }

            for (Integer key : nums.keySet()) {
                for (int i = 0; i < nums.get(key); i++) {
                    System.out.println(key);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
