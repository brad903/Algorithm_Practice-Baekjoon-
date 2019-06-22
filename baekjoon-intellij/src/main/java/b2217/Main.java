package b2217;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> ropes = getRopes(br);
        Collections.sort(ropes);

        int max = 0;
        int ropeCount = ropes.size();
        for (Integer rope : ropes) {
            max = Math.max(max, rope * ropeCount);
            ropeCount--;
        }
        System.out.println(max);
    }

    private static List<Integer> getRopes(BufferedReader br) throws IOException {
        List<Integer> ropes = new ArrayList<>();
        int n = Integer.parseInt(br.readLine());
        while (n-- != 0) {
            ropes.add(Integer.parseInt(br.readLine()));
        }
        return ropes;
    }
}
