package b4344;

import com.sun.javafx.binding.StringFormatter;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int count = Integer.parseInt(br.readLine());
        for (int i = 0; i < count; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            Double numCount = Double.parseDouble(stk.nextToken());
            List<Integer> nums = new ArrayList<>();
            for (int j = 0; j < numCount; j++) {
                nums.add(Integer.parseInt(stk.nextToken()));
            }
            double avg = nums.stream().mapToInt(Integer::intValue).sum() / numCount;
            long overAvgCount = nums.stream().filter(num -> num > avg).count();
            sb.append(String.format("%.3f", overAvgCount / numCount * 100) + "%\n");
        }
        System.out.println(sb);
    }
}
