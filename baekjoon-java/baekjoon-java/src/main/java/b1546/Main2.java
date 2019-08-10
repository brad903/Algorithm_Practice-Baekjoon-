package b1546;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        double sum = 0;
        int max = 0;
        StringTokenizer stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < count; i++) {
            int temp = Integer.parseInt(stk.nextToken());
            if(temp > max) max = temp;
            sum += temp;
        }
        System.out.println(sum / max * 100 / count);
        br.close();
    }
}
