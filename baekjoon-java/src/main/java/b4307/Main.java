package b4307;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- != 0) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int stickLength = Integer.parseInt(stk.nextToken());
            int antCount = Integer.parseInt(stk.nextToken());

            int fastest = 0;
            int slowest = 0;
            for (int i = 0; i < antCount; i++) {
                int cur = Integer.parseInt(br.readLine());
                int min = Math.min(cur, stickLength - cur);
                int max = Math.max(cur, stickLength - cur);

                fastest = Math.max(fastest, min);
                slowest = Math.max(slowest, max);
            }
            System.out.println(fastest + " " + slowest);
        }

    }
}
