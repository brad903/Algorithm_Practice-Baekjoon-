package b10989;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            int[] nums = new int[10001];

            for (int i = 0; i < n; i++) {
                int num = Integer.parseInt(br.readLine());
                nums[num]++;
            }

            try (BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
                for (int i = 0; i <= 10000; i++) {
                    for (int j = 0; j < nums[i]; j++) {
                        bw.write(i + "\n");
                    }
                }
                bw.flush();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
