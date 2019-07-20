package b2231;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            int answer = 0;
            for (int i = 1; i < n; i++) {
                int sum = getSum(i);
                if (n == sum) {
                    answer = i;
                    break;
                }
            }
            System.out.println(answer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static int getSum(int i) {
        int sum = i;
        while(i != 0) {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }
}
