package b1546;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        List<Double> scores = new ArrayList<>();
        StringTokenizer stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < count; i++) {
            scores.add(Double.parseDouble(stk.nextToken()));
        }

        Double max = Collections.max(scores);
        for (int i = 0; i < count; i++) {
            scores.set(i, scores.get(i) / max * 100);
        }
        System.out.println(scores.stream().mapToDouble(Double::doubleValue).sum() / count);
        br.close();
    }
}
